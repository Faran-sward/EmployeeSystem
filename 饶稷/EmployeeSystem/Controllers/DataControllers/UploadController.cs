using EmployeeSystem.Models.Tables;
using Microsoft.AspNetCore.Mvc;
using Oracle.ManagedDataAccess.Client;
using System.Drawing;


namespace EmployeeSystem.Controllers.DataControllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UploadController : ControllerBase
    {
        // Database connection details
        public OracleConnection con;

        UploadController(OracleConnection connection)
        {
            this.con = connection;
        }

        // POST: api/Upload
        [HttpPost]
        public IActionResult UploadEmployeeData([FromBody] EmployeeInfo employee)
        {
            // Validate the received data (you can add more validation logic as needed)
            string? id = employee.GetValue("ID");
            string? password  = employee.GetValue("Password");

            if (string.IsNullOrEmpty(id) || string.IsNullOrEmpty(password))
            {
                return BadRequest("Invalid data. ID and Password are required.");
            }

            try
            {
                con.Open();
                if (con.State == System.Data.ConnectionState.Open)
                {
                    // Insert the new tuple with the received values
                    string insertQuery = "INSERT INTO Employeeinfo (EmployeeID, Pass_word) " +
                                         "VALUES (:employeeID, :passWord)";

                    using (OracleCommand cmd = new OracleCommand(insertQuery, con))
                    {
                        cmd.Parameters.Add(new OracleParameter("employeeID", id));
                        cmd.Parameters.Add(new OracleParameter("passWord", password));
                        cmd.ExecuteNonQuery();
                    }

                    con.Close();
                    return Ok($"Successfully uploaded Employee data. EmployeeID: {id}, Pass_word: {password}");
                }
                else
                {
                    return StatusCode(500, "Failed to connect to the Oracle database.");
                }
            }
            catch (Exception ex)
            {
                return StatusCode(500, $"Error connecting to the Oracle database: {ex.Message}");
            }
        }
    }
}
