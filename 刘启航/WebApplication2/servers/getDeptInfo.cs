using System.Collections.Generic;
using WebApplication2.entities;
using WebApplication2.entities.backentities;
using WebApplication2.entities.backentities.listentities;
using WebApplication2.servers.mapper;

namespace WebApplication2.servers
{
    public class getDeptInfo
    {
        public ObtainDeptInfo obtainDeptInfo(String DepartmentTitle)
        {
            MapperOfDepartment modm = new MapperOfDepartment();
            List<GetDeptInfo> resultList = new List<GetDeptInfo>();
            resultList = modm.getCertainDepartment(DepartmentTitle);

            ObtainDeptInfo result = new ObtainDeptInfo();

            if (resultList == null || resultList.Count() == 0)
            {
                result.BackCode = -101;//此时代表查询失败，其中无信息
            }
            else
            {
                result.BackCode = 1;
                result.Layer = resultList[0].Layer;
                result.Building = resultList[0].Building;
                result.DepartmentID = resultList[0].DepartmentID;
            }
            return result;
        }

        public ObtainOrgInfo obtainOrgInfo(String DepartmentTitle)
        {
            ObtainOrgInfo result = new ObtainOrgInfo();

            ObtainDeptInfo DepartmentIDPackage = new ObtainDeptInfo();
            DepartmentIDPackage = obtainDeptInfo(DepartmentTitle);
            if (DepartmentIDPackage.BackCode != 1)
            {
                result.BackCode = -101;//表示查询失败，其中无信息
                return result;
            }

            //此时根据这个ID来找寻list
            List<GetOrgInfo> resultList = new List<GetOrgInfo>();
            MapperOfDepartment modm = new MapperOfDepartment();

            resultList = modm.getCertainOrg(DepartmentIDPackage.DepartmentID);


            if (resultList.Count() == 0) { result.BackCode = -102; return result; } //表示查询得到名称，但目前无任何编制
            result.BackCode = 1;
            result.requestResult = resultList;
            return result;
        }


        public ObtainPositionInfo obtainPosInfo(String DepartmentTitle)
        {
            ObtainPositionInfo result = new ObtainPositionInfo();
            MapperOfDepartment modm = new MapperOfDepartment();
            List<GetPostionInfo> templist = new List<GetPostionInfo>();

            //首先我们获得整个对应的职位表，然后再根据一个个职位来检索服务器
            ObtainOrgInfo TempP1 = obtainOrgInfo(DepartmentTitle);

            //如果未检索到，就直接返回
            if (TempP1.BackCode != 1) { result.BackCode = TempP1.BackCode; return result; }

            //接着我们根据每一代码进行检索，检索成功就将其放置在列表中
            int iSize = TempP1.requestResult.Count();
            for (int i = 0; i < iSize; i++)
            {
                String code = TempP1.requestResult.ElementAt(i).PostID;
                Console.WriteLine("此时搜索的code为：" + code);
                GetPostionInfo tempSave = new GetPostionInfo();
                tempSave = modm.getCertainPos(code);

                if (tempSave == null)
                {
                    result.BackCode = -103;
                    return result;
                }

                //然后根据这个进行查询，查询结果放置在list中
                templist.Add(tempSave);
            }

            result.BackCode = 1;
            result.requestResult = templist;

            return result;
        }

        public ObtainEmployeeInfo obtainEmployeeInfo(String DepartmentTitle)
        {
            ObtainEmployeeInfo result = new ObtainEmployeeInfo();
            MapperOfDepartment modm = new MapperOfDepartment();
            List<GetEmployeeInfo> templist = new List<GetEmployeeInfo>();

            //首先我们获得整个对应的职位表，然后再根据一个个职位来检索服务器
            ObtainOrgInfo TempP1 = obtainOrgInfo(DepartmentTitle);

            //如果未检索到，就直接返回
            if (TempP1.BackCode != 1) { result.BackCode = TempP1.BackCode; return result; }

            //接着我们根据每一代码进行检索，检索成功就将其放置在列表中
            int iSize = TempP1.requestResult.Count();
            for (int i = 0; i < iSize; i++)
            {
                String code = TempP1.requestResult.ElementAt(i).PostID;
                Console.WriteLine("此时搜索的code为：" + code);
                List<GetEmployeeInfo> templist1 = new List<GetEmployeeInfo>();
                //此时最好使用list的方式进行检测
                templist1 = modm.getCertainEmployee(code);

                //然后根据这个进行查询，查询结果放置在list中
                foreach(GetEmployeeInfo temp in templist1)
                {
                    templist.Add(temp);
                }
            }

            result.BackCode = 1;
            result.requestResult = templist;


            return result;
        }

        public ObtainResultCode newBuildDept(String DepartmentID, String DepartmentTitle, String Building, int layer)
        {
            ObtainResultCode resultCode = new ObtainResultCode();
            MapperOfDepartment modm = new MapperOfDepartment();

            //此时我们需要完成两个操作，其一为检测其中是否存在ID，其二为创造ID
            ObtainDeptInfo check1 = new ObtainDeptInfo();
            check1 = obtainDeptInfo(DepartmentTitle);

            //如果之前已经注册过了，就放回错误代码-201
            if (check1.BackCode == 1) { resultCode.BackCode = -201; }

            //之前没有注册过，就在此处进行注册操作
            modm.newBuildDept(DepartmentID, DepartmentTitle, Building, layer);
            resultCode.BackCode = 1;

            return resultCode;
        }

        public ObtainAllDeptInfo getAllDepartmentInfo()
        {
            ObtainAllDeptInfo result = new ObtainAllDeptInfo();
            MapperOfDepartment modm = new MapperOfDepartment();
            List<GetDeptInfo> resultList = new List<GetDeptInfo>();

            //首先我们得到整个列表

            resultList = modm.getAllDepartment();

            //然后根据列表完善整个结构体
            if (resultList == null) { result.BackCode = -101; }
            else
            {
                result.nums = resultList.Count;
                result.BackCode = 1;
                result.infos = resultList;
            }

            return result;
        }

        public ObtainResultCode newBuildPost(String DepartmentID, String PostID, String PostTitle, String PostType, String PostLevel)
        {
            ObtainResultCode result = new ObtainResultCode();
            MapperOfDepartment modm = new MapperOfDepartment();

            //首先我们需要进行两个检查
            //第一个检查即为此时对应的部门是否存在，如果不存在则需要进行返回报错信息
            List<GetDeptInfo> check1 = new List<GetDeptInfo>();
            check1 = modm.getCertainDepartmentFromId(DepartmentID);
            if (check1.Count != 1)
            {
                result.BackCode = -202;
                return result;
            }

            //其次即检查对应的职位是否存在，如果存在，为了避免反复创建，我们直接返回报错信息
            List<GetPostionInfo> check2 = new List<GetPostionInfo>();
            check2 = modm.getCertainPost(PostID);

            if (check2.Count != 0)
            {
                result.BackCode = -203;
                return result;
            }

            //接着我们需要进行表的插入工作
            //首先加入到岗位信息表中
            modm.newPostInfo(PostID, PostTitle, PostType, PostLevel);

            //其次加入到编制表中
            modm.newDeptPost(DepartmentID, PostID);


            result.BackCode = 1;
            return result;
        }

        public ObtainResultCode changeScale(String DepartmentID, String PostID, int EmulatedScale)
        {
            ObtainResultCode result = new ObtainResultCode();

            //首先尝试查看是否有对应的职位，如果有的话，才进行下一步操作
            //没有的话直接写入result报错信息
            MapperOfDepartment modm1 = new MapperOfDepartment();
            List<GetOrgInfo> check1 = new List<GetOrgInfo>();
            check1 = modm1.getCertainOrg(DepartmentID);

            //之后检查check1中是否有满足条件的职位
            bool checkOK = false;
            if (check1 == null || check1.Count == 0)
            {
                result.BackCode = -111;
                return result;
            }

            foreach (GetOrgInfo i in check1)
            {
                if (i.PostID == PostID) { checkOK = true; break; }
            }

            if (checkOK == false)
            {
                result.BackCode = -112;
                return result;
            }

            //接着即可开始进行修改
            modm1.updatePostScale(DepartmentID, PostID, EmulatedScale);
            result.BackCode = 1;

            return result;
        }

        public ObtainResultCode delDeptInfo(String DepartmentID)
        {
            ObtainResultCode result = new ObtainResultCode();
            MapperOfDepartment modm1 = new MapperOfDepartment();

            //此时我们需要检查其部门下是否还存在对应的职位，如果有的话，直接抛出报错信息，要求用户删除对应的职位信息后再进行删除
            List<GetOrgInfo> check1 = new List<GetOrgInfo>();

            check1 = modm1.getCertainOrg(DepartmentID);

            if (check1 == null || check1.Count == 0)
            {
                //此时可以进行删除操作
                modm1.delDeptInfo(DepartmentID);
            }
            else
            {
                result.BackCode = -601;
                return result;
            }
            result.BackCode = 1;
            return result;
        }

        public ObtainResultCode delPosInfo(String DepartmentID,String PostID)
        {
            ObtainResultCode result = new ObtainResultCode();
            MapperOfDepartment modm1 = new MapperOfDepartment();

            //此时我们需要检查其职位下是否还存在对应的员工，如果有的话，直接抛出报错信息，要求用户转移对应的员工职位信息后再进行删除
            List<GetEmployeeInfo> check1 = new List<GetEmployeeInfo>();
            check1 = modm1.getCertainEmployee(DepartmentID);

            if (check1 == null || check1.Count == 0)
            {
                //此时可以进行删除操作，需要将多个表中的项目进行删除
                modm1.delDept_Post(PostID);
                modm1.delPostInfo(PostID);
            }
            else
            {
                result.BackCode = -601;
                return result;
            }
            result.BackCode = 1;
            return result;
        }

        public string SignAndLogin(LoginInfo _logininfo)
        {
            MapperOfDepartment modm1 = new MapperOfDepartment();
            String keyWord = System.Text.Encoding.Default.GetString(System.Convert.FromBase64String(_logininfo.keyword));

            if (_logininfo.account.Length > 20) { return "ACCOUNTLENGTHERR"; }
            if (keyWord.Length > 20) { return "KEYWORDLENGTHERR"; }
            if (_logininfo.status == "Sign")
            {
                //此时对应的是注册，这一块交给员工信息新增系统完成
                return "MODEERR";

                /*先判断数据库是否有账号与其重复的，如果有，则返回失败*//*
                string resultofcheckrepeat = FUNC.CheckRepeat(_logininfo.account);
                if (resultofcheckrepeat != "OK")
                {
                    if (resultofcheckrepeat == "NO")
                        return "REPEATERR";
                    else
                        return resultofcheckrepeat;
                }*/


                /*如果没有重复的，我们就直接进行插入*//*
                return  FUNC.Sign(_logininfo.account,_logininfo.keyword);*/
            }
            else if (_logininfo.status == "Login")
            {
                /*先判断数据库是否有账号与密码匹配的，如果没有，则返回失败*/

                /*有，返回成功*/
                List<GetEmployeeInfo> check1 = new List<GetEmployeeInfo>();
                check1 = modm1.Login(_logininfo.account, keyWord);
                if (check1 == null || check1.Count == 0)
                    return "ACCOUNTLACKERR";
                else return "LOGINOK";
            }
            else
                return "MODEERR";
        }
    }
}
