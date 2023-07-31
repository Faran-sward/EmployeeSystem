using Microsoft.AspNetCore.Mvc;
using Oracle.ManagedDataAccess.Client;

namespace EmployeeSystem.Controllers.DataControllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DatabaseController : ControllerBase
    {
        // Database connection details
        private static readonly string connectionString = "User Id=SYSTEM;Password=1738477932;Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=orcl)));";

        // GET: api/database
        [HttpGet]
        public IActionResult CheckDatabaseConnection()
        {
            try
            {
                using (OracleConnection con = new OracleConnection(connectionString))
                {
                    con.Open();
                    if (con.State == System.Data.ConnectionState.Open)
                    {
                        con.Close();
                        return Ok("成功连接到 Oracle 数据库。");
                    }
                    else
                    {
                        return StatusCode(500, "连接到 Oracle 数据库失败。");
                    }
                }
            }
            catch (Exception ex)
            {
                return StatusCode(500, $"连接到 Oracle 数据库时出错: {ex.Message}");
            }
        }

        // GET: api/database/Employeeinfo/FirstTuple
        // GET: api/database/Employeeinfo/FirstTuple
        [HttpGet("Employeeinfo/FirstTuple")]
        public IActionResult GetFirstEmployeeInfoTuple()
        {
            try
            {
                using (OracleConnection con = new OracleConnection(connectionString))
                {
                    con.Open();
                    if (con.State == System.Data.ConnectionState.Open)
                    {
                        string query = "SELECT * FROM Employeeinfo WHERE ROWNUM = 1";
                        using (OracleCommand cmd = new OracleCommand(query, con))
                        {
                            using (OracleDataReader reader = cmd.ExecuteReader())
                            {
                                if (reader.Read())
                                {
                                    // Assuming Employeeinfo table columns: EmployeeID, CurrentPostID, CurrentCity, StartWorkingDate, BasicSalary, ImageUrl, Pass_word
                                    string employeeID = reader["EmployeeID"] is DBNull ? null : reader["EmployeeID"].ToString();
                                    string currentPostID = reader["CurrentPostID"] is DBNull ? null : reader["CurrentPostID"].ToString();
                                    string currentCity = reader["CurrentCity"] is DBNull ? null : reader["CurrentCity"].ToString();
                                    DateTime? startWorkingDate = reader["StartWorkingDate"] is DBNull ? null : (DateTime?)Convert.ToDateTime(reader["StartWorkingDate"]);
                                    decimal? basicSalary = reader["BasicSalary"] is DBNull ? null : (decimal?)Convert.ToDecimal(reader["BasicSalary"]);
                                    string imageUrl = reader["ImageUrl"] is DBNull ? null : reader["ImageUrl"].ToString();
                                    string passWord = reader["Pass_word"] is DBNull ? null : reader["Pass_word"].ToString();

                                    // Create a dictionary to store the first tuple's data
                                    Dictionary<string, object> employeeData = new Dictionary<string, object>
                            {
                                { "EmployeeID", employeeID },
                                { "CurrentPostID", currentPostID },
                                { "CurrentCity", currentCity },
                                { "StartWorkingDate", startWorkingDate },
                                { "BasicSalary", basicSalary },
                                { "ImageUrl", imageUrl },
                                { "Pass_word", passWord }
                            };

                                    con.Close();
                                    return Ok(employeeData);
                                }
                                else
                                {
                                    con.Close();
                                    return NotFound("Employeeinfo表中没有数据。");
                                }
                            }
                        }
                    }
                    else
                    {
                        return StatusCode(500, "连接到 Oracle 数据库失败。");
                    }
                }
            }
            catch (Exception ex)
            {
                return StatusCode(500, $"连接到 Oracle 数据库时出错: {ex.Message}");
            }
        }

        [HttpPost("AddEmployee")]
        public IActionResult AddEmployee()
        {
            try
            {
                using (OracleConnection con = new OracleConnection(connectionString))
                {
                    con.Open();
                    if (con.State == System.Data.ConnectionState.Open)
                    {
                        Random random = new Random();

                        // Generate EmployeeID
                        int year = 2023; // Year is fixed as 2023
                        int month = random.Next(1, 13); // Random month from 1 to 12
                        int day = random.Next(1, 29); // Random day from 1 to 28/29 (ignoring leap years)
                        string employeeID = $"{year}{month:D2}{day:D2}";

                        // Generate Pass_word (all digits, 8 characters)
                        string passWord = random.Next(10000000, 99999999).ToString();

                        // Insert the new tuple with generated values
                        string insertQuery = "INSERT INTO Employeeinfo (EmployeeID, Pass_word) VALUES (:employeeID, :passWord)";
                        using (OracleCommand cmd = new OracleCommand(insertQuery, con))
                        {
                            cmd.Parameters.Add(new OracleParameter("employeeID", employeeID));
                            cmd.Parameters.Add(new OracleParameter("passWord", passWord));
                            cmd.ExecuteNonQuery();
                        }

                        con.Close();
                        return Ok($"已成功添加元组，EmployeeID: {employeeID}, Pass_word: {passWord}");
                    }
                    else
                    {
                        return StatusCode(500, "连接到 Oracle 数据库失败。");
                    }
                }
            }
            catch (Exception ex)
            {
                return StatusCode(500, $"连接到 Oracle 数据库时出错: {ex.Message}");
            }
        }
    }
}
