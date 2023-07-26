using DB_project.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Oracle.ManagedDataAccess.Client;

namespace DB_project.Controllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class BasicInfoController : ControllerBase
    {
        private static string connectionString = "Data Source=localhost/ORCL;User ID=sys_developer;Password=1738477932;";
        [HttpGet("{EmpID}")]
        public string GetBasicInfo(string EmpID)
        {
            List<BasicInfo> BasicInfos = new List<BasicInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string sql = "SELECT * FROM FundamentalInfo F, EmployeeInfo E WHERE f.employeeid = e.employeeid and f.EMPLOYEEID= :EmpID";
                    BasicInfo basicInfo = new BasicInfo();
                    using (OracleCommand cmd = new OracleCommand(sql, connection))
                    {
                        cmd.Parameters.Add(":EmpID", OracleDbType.Varchar2).Value = EmpID;
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            reader.Read();
                            // 根据需要获取列的值
                            basicInfo.ID = reader["ID_number"].ToString();
                            basicInfo.Name = reader["Name"].ToString();
                            basicInfo.BasicSalary = reader["BasicSalary"].ToString();
                            basicInfo.Sex = reader["Sex"].ToString();
                            basicInfo.PhoneNumber = reader["PhoneNumber"].ToString();
                            basicInfo.HomeAddress = reader["HomeAddress"].ToString();
                            basicInfo.ImageURL = reader["ImageURL"].ToString();
                            basicInfo.WorkState = reader["WorkState"].ToString();
                            string sTime = reader["StartWorkingDate"].ToString();
                            string birth = reader["Birth"].ToString();
                            string startTime = sTime.Substring(0, sTime.Length - 8);
                            string birthTime = birth.Substring(0, birth.Length - 8);
                            basicInfo.Birth = birthTime;
                            basicInfo.StartWorkingDate = startTime;
                            BasicInfos.Add(basicInfo);
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return JsonConvert.SerializeObject(BasicInfos);
        }
    }
}
