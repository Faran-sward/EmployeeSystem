using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Oracle.ManagedDataAccess.Client;

using EmployeeSystem.Models.Tables;
using EmployeeSystem.Models.Connection;

namespace EmployeeSystem.Controllers.DataControllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class BasicInfoController : ControllerBase  // 负责对员工的基本信息操作
    {
        [HttpGet("{emp_id}")]
        public string GetBasicInfoAll(string emp_id, OracleConnection connection)  // 由emp_id获取其他属性值
        {
            BasicInfo basicinfo = new BasicInfo();  // 用于接收数据的实例
            try
            {
                connection.Open();
                string sql = "SELECT * " +
                             "FROM FundamentalInfo F, EmployeeInfo E " +
                             "WHERE f.employeeid = e.employeeid and f.EMPLOYEEID= :emp_id";
                using (OracleCommand cmd = new OracleCommand(sql, connection))
                {
                    cmd.Parameters.Add(":emp_id", OracleDbType.Varchar2).Value = emp_id;
                    using (OracleDataReader reader = cmd.ExecuteReader())
                    {
                        reader.Read();
                        // 根据需要获取列的值
                        basicinfo.ID = reader["ID_number"].ToString();  // 在数据表中，可以建立string数组存储对应属性值
                        basicinfo.Name = reader["Name"].ToString();  // 可以声明一个enum对应basicinfo对应的属性名
                        basicinfo.BasicSalary = reader["BasicSalary"].ToString();  // 方便日后修改，且能够循环遍历
                        basicinfo.Sex = reader["Sex"].ToString();  // 尽量消除弱警告：使用 string? 表明该字符串可以为空指针
                        basicinfo.PhoneNumber = reader["PhoneNumber"].ToString();  // string调用方法前可以使用空合并运算符 ??消除为空情形
                        basicinfo.HomeAddress = reader["HomeAddress"].ToString();  // 防止不必要的错误
                        basicinfo.ImageURL = reader["ImageURL"].ToString();
                        basicinfo.WorkState = reader["WorkState"].ToString();
                        string? sTime = reader["StartWorkingDate"].ToString();
                        string? birth = reader["Birth"].ToString();
                        string? startTime = string.IsNullOrEmpty(sTime) ? "" : sTime.Substring(0, sTime.Length - 8);  // TODO
                        string? birthTime = string.IsNullOrEmpty(birth) ? "" : birth.Substring(0, birth.Length - 8);
                        basicinfo.Birth = birthTime;
                        basicinfo.StartWorkingDate = startTime;
                    }
                }
                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
            }

            return JsonConvert.SerializeObject(basicinfo);
        }
    }
}
