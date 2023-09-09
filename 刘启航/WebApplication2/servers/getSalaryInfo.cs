using WebApplication2.entities;
using WebApplication2.entities.backentities;
using WebApplication2.entities.backentities.listentities;
using WebApplication2.servers.mapper;

namespace WebApplication2.servers
{
    public class getSalaryInfo
    {
        //该函数用于获取指定月份的工资表
        public ObtainSalaryTableInfo getSalaryTableInfo(String idate)
        {
            ObtainSalaryTableInfo result= new ObtainSalaryTableInfo();

            //首先我们需要获得整个指定月份的Emp_Salary表格
            MapperOfSalary modm = new MapperOfSalary();
            MapperOfDepartment modm1 = new MapperOfDepartment();
            List<GetEmpSalaryInfo> list1 = new List<GetEmpSalaryInfo>();
            List<GetAllSalaryInOneMonth> list2 = new List<GetAllSalaryInOneMonth>();
            list1 = modm.getCertainSalaryTable(idate);

            //接着对整个list内的内容进行检查，并对信息进行拓展
            if(list1 == null || list1.Count < 1)
            {
                result.BackCode = -101;
                return result;
            }

            for(int i = 0; i < list1.Count;i++)
            {
                GetAllSalaryInOneMonth tempSave = new GetAllSalaryInOneMonth();

                //此时我们需要查询其对应的姓名以及其对应的底薪
                tempSave.Name = modm1.getEmpNameFromEmpId(list1[i].EmployeeID);
                tempSave.Commission = list1[i].Commission;
                tempSave.Bonus = list1[i].Bonus;
                tempSave.EmployeeID = list1[i].EmployeeID;
                tempSave.OverallSalary = list1[i].OverallSalary;
                tempSave.BasicSalary = tempSave.OverallSalary - tempSave.Bonus - tempSave.Commission;
                list2.Add(tempSave);
            }

            result.requestResult = list2;
            result.BackCode = 1;

            return result;
        }
        public ObtainPersonalSalary getPersonalSalaryList(String EmpId)
        {
            ObtainPersonalSalary result = new ObtainPersonalSalary();
            MapperOfSalary modm1 = new MapperOfSalary();

            //此时我们直接查询，查完之后再进行一次分割操作即可
            List<GetEmpSalaryInfo> list1 = new List<GetEmpSalaryInfo>();
            List<GetPersonalSalary> list2 = new List<GetPersonalSalary>();
            list1 = modm1.getPersonalSalaryTable(EmpId);

            foreach (GetEmpSalaryInfo info in list1)
            {
                GetPersonalSalary tempSave= new GetPersonalSalary();
                String[] DateList = info.Date.Split("-");
                tempSave.OverallSalary = info.OverallSalary;
                tempSave.Bonus= info.Bonus;
                tempSave.Commission= info.Commission;
                tempSave.BasicSalary = tempSave.OverallSalary-tempSave.Bonus-tempSave.Commission;
                tempSave.year = DateList[2];
                tempSave.month = DateList[1];
                list2.Add(tempSave);
            }

            if (list2 == null || list2.Count == 0) { result.BackCode = -101; }
            else { result.BackCode = 1;result.requestResult = list2; }
            return result;
        }

        public ObtainResultCode ChangeSalary(String EmployeeID, float BasicSalary, float Bonus, float Commission)
        {
            ObtainResultCode result = new ObtainResultCode();
            MapperOfDepartment modm1 = new MapperOfDepartment();
            MapperOfSalary modm2 = new MapperOfSalary();

            //首先查询其是否存在指定员工
            List<GetEmployeeInfo> check1 = new List<GetEmployeeInfo>();
            check1 = modm1.getEmployeeInfo(EmployeeID);
            if(check1== null || check1.Count == 0)
            {
                result.BackCode = -701;
                return result;
            }

            //接着查询是否存在当月工资条,即此时工资条年月与当下相符，当前日期处于1号到21号之间

            /*先查询当下的年月日*/
            DateTime currentTime = DateTime.Now;

            String curyear = currentTime.Year.ToString();
            String curmonth = currentTime.Month.ToString();
            int curday = currentTime.Day;
            if (curday > 31)
            {
                result.BackCode = -702;
                return result;
            }

            /*获取该员工的所有工资条，然后进行遍历*/
            ObtainPersonalSalary gePersonalSalary = new ObtainPersonalSalary();
            gePersonalSalary = getPersonalSalaryList(EmployeeID);

            if (gePersonalSalary == null||gePersonalSalary.BackCode!=1) {
                result.BackCode = -703;
                return result;
            }

            List<GetPersonalSalary> list2 = new List<GetPersonalSalary>();
            list2 = gePersonalSalary.requestResult;
            bool find = false;
            foreach(GetPersonalSalary temp in list2)
            {
                String tempCalYear =  Convert.ToString(Convert.ToInt32(temp.year) + 2000);
                String tempCalMonth = curmonth.Split("月")[0]; ;

                if (tempCalMonth == curmonth&& tempCalYear == curyear)
                {
                    find = true;
                    break;
                }
            }

            if (!find) {
                result.BackCode = -704;
                return result;
            }
            //对底薪进行修改
            modm1.updateBasicSalary(EmployeeID, BasicSalary);
            String dateTemp = "01-"+curmonth+"月-"+ Convert.ToString(Convert.ToInt32(curyear) - 2000);
/*            if (Convert.ToInt32(curmonth)<10)
                dateTemp = curyear+"/0"+curmonth+"/01";
            else
                dateTemp = curyear + "/" + curmonth + "/01";*/

            //对工资条进行修改

            modm2.updateSalaryList(EmployeeID, dateTemp, Bonus, Commission, Bonus + Commission + BasicSalary);

            result.BackCode = 1;
            return result;
        }

        public ObtainResultCode initSalary()
        {
            ObtainResultCode resultCode= new ObtainResultCode();
            MapperOfDepartment modm1 = new MapperOfDepartment();
            MapperOfSalary modm2 = new MapperOfSalary();

            //此时我们需要检索所有的员工，看其是否存在当月记录，如果不存在当月记录则进行插入
            List<GetEmployeeInfo> check1 = new List<GetEmployeeInfo>();
            check1 = modm1.getALLEmployee();

            if(check1 == null|| check1.Count == 0) { resultCode.BackCode = -101;return resultCode;}

            DateTime currentTime = DateTime.Now;

            String curyear = currentTime.Year.ToString();
            String curmonth = currentTime.Month.ToString();

            foreach (GetEmployeeInfo info in check1)
            {
                for(int i = 0;i<3;i++)
                {
                    String curtime = "01-" + (currentTime.Month-i).ToString() + "月-" + Convert.ToString(Convert.ToInt32(curyear) - 2000);
                    List<GetEmpSalaryInfo> check2 = new List<GetEmpSalaryInfo>();
                    check2 = modm2.getCertainPersonalSalartList(info.EmployeeID, curtime);
                    if (check2 == null || check2.Count == 0)
                    {
                        Random rd = new Random();
                        float s1 = 2000 * (float)(rd.Next(75, 100)*1.0 / 100.0);
                        float s2 = 2000 * (float)(rd.Next(69, 100)*1.0 / 100.0);
                        //此时满足条件，可以进行添加
                        modm2.newEmp_Salary(info.EmployeeID, curtime, s1, s2, s1+s2 + info.BasicSalary);
                    }
                }
                
            }
            resultCode.BackCode = 1;
            return resultCode;
        }
    }
}
