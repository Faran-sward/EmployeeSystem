using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.Reflection.Emit;
using WebApplication2.entities;
using WebApplication2.entities.backentities;
using WebApplication2.servers;

namespace WebApplication2.Controllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        [HttpGet]
        public string Test()
        {
            return "OK";
        }

        [HttpGet]
        public string LoginAndSign(String account,String keyword,String  status )
        {
            LoginInfo info = new LoginInfo();
            info.account = account;
            info.keyword = keyword;
            info.status = status;
            getDeptInfo dc = new getDeptInfo();
            return dc.SignAndLogin(info);
        }

        [HttpGet]
        public ObtainAllDeptInfo GetAllDeptInfo() {
            getDeptInfo dc = new getDeptInfo();
            return dc.getAllDepartmentInfo();
        }

        [HttpGet]
        public ObtainDeptInfo GetCertainDeptInfo(String DepartmentTitle)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.obtainDeptInfo(DepartmentTitle);
        }

        [HttpGet]
        public ObtainOrgInfo getCertainOrgInfo(String DepartmentTitle)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.obtainOrgInfo(DepartmentTitle);
        }

        [HttpGet]
        public ObtainPositionInfo getCertainPositionInfo(String DepartmentTitle)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.obtainPosInfo(DepartmentTitle);
        }

        [HttpGet]
        public ObtainEmployeeInfo getCertainEmployeeInfo(String DepartmentTitle)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.obtainEmployeeInfo(DepartmentTitle);
        }

        [HttpGet]
        public ObtainResultCode newBuildDept(String DepartmentID,String DepartmentTitle,String Building,int layer)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.newBuildDept(DepartmentID, DepartmentTitle, Building, layer);
        }

        [HttpGet]
        public ObtainResultCode newBuildPost(String DepartmentID,String PostID,String PostTitle,String PostType,String PostLevel)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.newBuildPost(DepartmentID, PostID, PostTitle, PostType, PostLevel);
        }

        [HttpGet]
        public ObtainSalaryTableInfo getSalaryTable(String year,String month)
        {
            getSalaryInfo dc = new getSalaryInfo();
            return dc.getSalaryTableInfo("01-" + month + "月-" + Convert.ToString(Convert.ToInt32(year) - 2000));
        }

        [HttpGet]
        public ObtainPersonalSalary getPersonalSalary(String EmployeeID)
        {
            getSalaryInfo dc = new getSalaryInfo();
            return dc.getPersonalSalaryList(EmployeeID);
        }

        /*        [HttpGet]
                public ObtainResultCode changeSalary(String EmployeeID,float BasicSalary,float Bonus,float Commission)
                {

                }*/

        [HttpGet]
        public ObtainResultCode changeScale(String DepartmentID,String PostID,int EmulatedScale)
        {
            getDeptInfo dc =new getDeptInfo();
            return dc.changeScale(DepartmentID, PostID, EmulatedScale);
        }

        [HttpGet]
        public ObtainResultCode delDeptInfo(String DepartmentID)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.delDeptInfo(DepartmentID);
        }

        [HttpGet]
        public ObtainResultCode delPosInfo(String DepartmentID,String PostID)
        {
            getDeptInfo dc = new getDeptInfo();
            return dc.delPosInfo(DepartmentID,PostID);
        }

        [HttpGet]
        public ObtainResultCode ChangeSalary(String EmployeeID,float BasicSalary,float Bonus,float Commission)
        {
            getSalaryInfo dc = new getSalaryInfo();
            return dc.ChangeSalary(EmployeeID, BasicSalary, Bonus, Commission);
        }

        [HttpGet]
        public ObtainResultCode initSalary()
        {
            getSalaryInfo dc =new getSalaryInfo();
            return dc.initSalary();
        }

    }
}
