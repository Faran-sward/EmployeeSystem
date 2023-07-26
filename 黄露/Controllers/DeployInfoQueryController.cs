using DB_project.Model;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Oracle.ManagedDataAccess.Client;
using System.Data;
using System.Globalization;

namespace DB_project.Controllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class DeployInfoQueryController : ControllerBase
    {
        private static string connectionString = "Data Source=8.130.115.212/ORCL;User ID=TESTER;Password=123456;";
        [HttpGet("{EmpID}")]
        public string GetDeployInfo(string EmpID)
        {
            List<DeployInfo> DeployInfos = new List<DeployInfo>();
            using(OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    string sql = "SELECT * FROM BusinessInfo WHERE EMPLOYEEID= :EmpID";
                    DeployInfo deployInfo = new DeployInfo();
                    using (OracleCommand cmd = new OracleCommand(sql, connection))
                    {
                        cmd.Parameters.Add(":EmpID", OracleDbType.Varchar2).Value = EmpID;
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            while (reader.Read())
                            {
                                // 根据需要获取列的值
                                deployInfo.BusinessID = reader["BusinessID"].ToString();
                                deployInfo.BusinessEnterpriseName = reader["BusinessEnterpriseName"].ToString();
                                deployInfo.BusinessDepartmentName = reader["BusinessDepartmentName"].ToString();
                                deployInfo.BusinessPostName = reader["BusinessPostName"].ToString();
                                string sTime = reader["StartTime"].ToString();
                                string eTime = reader["EndTime"].ToString();
                                string startTime = sTime.Substring(0, sTime.Length - 8);
                                string endTime = eTime.Substring(0, eTime.Length - 8);
                                deployInfo.StartTime = startTime;
                                deployInfo.EndTime = endTime;
                                DeployInfos.Add(deployInfo);
                            }
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return JsonConvert.SerializeObject(DeployInfos);
        }
    }
}
