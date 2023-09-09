using Oracle.ManagedDataAccess.Client;
using Microsoft.AspNetCore.Mvc;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Database;
using System.Reflection.PortableExecutable;
using System.Diagnostics.Contracts;
using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.servers.mapper
{
    public class MapperOfSalary
    {
        private static string connectionString = "Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=8.130.119.222)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=ORCL)));Persist Security Info=True;User ID=project;Password=project;";

        //用于获取整个月份的薪资表
        public List<GetEmpSalaryInfo> getCertainSalaryTable(String idate)
        {
            List<GetEmpSalaryInfo> rb = new List<GetEmpSalaryInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM Emp_Salary WHERE PAYDATE= :SDate");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDate", idate));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("Emp_Salary表查询成功！");
                            while (reader.Read())
                            {
                                GetEmpSalaryInfo info = new GetEmpSalaryInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    info.EmployeeID = reader.GetString(0);
                                    info.Date = reader.GetString(1);
                                    info.Bonus = reader.GetFloat(2);
                                    info.Commission = reader.GetFloat(3);
                                    info.OverallSalary = reader.GetFloat(4);
                                }
                                rb.Add(info);
                            }
                        }
                        foreach (string result in results)
                        {
                            Console.WriteLine(result);
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return rb;
        }

        //其用于获取个人工资单
        public List<GetEmpSalaryInfo> getPersonalSalaryTable(String EmpID)
        {
            List<GetEmpSalaryInfo> rb = new List<GetEmpSalaryInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM Emp_Salary WHERE EmployeeID= :SEmployeeID");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", EmpID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("Emp_Salary表查询成功！");
                            while (reader.Read())
                            {
                                GetEmpSalaryInfo info = new GetEmpSalaryInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    info.EmployeeID = reader.GetString(0);
                                    info.Date = reader.GetString(1);
                                    info.Bonus = reader.GetFloat(2);
                                    info.Commission = reader.GetFloat(3);
                                    info.OverallSalary = reader.GetFloat(4);
                                }
                                rb.Add(info);
                            }
                        }
                        foreach (string result in results)
                        {
                            Console.WriteLine(result);
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return rb;
        }

        public void updateSalaryList(String EmpID, String Date,float Bonus,float Commission,float OverallSalary)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接Emp_Salary成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("update Emp_Salary set Bonus = :SBonus,Commission = :SCommission,OverallSalary = :SOverallSalary where EmployeeID = :SEmployeeID and PAYDATE = :SDate");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SBonus", Bonus));
                        cmd.Parameters.Add(new OracleParameter(":SCommission", Commission));
                        cmd.Parameters.Add(new OracleParameter(":SOverallSalary", OverallSalary));
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", EmpID));
                        cmd.Parameters.Add(new OracleParameter(":SDate", Date));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("更新成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        //获得指定员工指定日期的工资条
        public List<GetEmpSalaryInfo> getCertainPersonalSalartList(String EmployeeID,String date)
        {
            List<GetEmpSalaryInfo> rb = new List<GetEmpSalaryInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM Emp_Salary WHERE EmployeeID = :SEmployeeID and PAYDATE = :SPaydate");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", EmployeeID));
                        cmd.Parameters.Add(new OracleParameter(":SPaydate", date));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("EmployeeInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmpSalaryInfo info = new GetEmpSalaryInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader[i].ToString());
                                    info.EmployeeID = reader[0].ToString();
                                    info.Date = reader[1].ToString();
                                    info.Bonus = reader.GetFloat(2);
                                    info.Commission = reader.GetFloat(3);
                                    info.OverallSalary = reader.GetFloat(4);
                                }
                                rb.Add(info);
                            }
                        }
                        foreach (string result in results)
                        {
                            Console.WriteLine(result);
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return rb;
        }

        public void newEmp_Salary (String DepartmentID, String Paydate, float Bonus, float Commission, float OverallSalary)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("insert into Emp_Salary values(:SDepartmentID,:SPaydate,:SBonus,:SCommission,:SOverallSalary)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        cmd.Parameters.Add(new OracleParameter(":SPaydate", Paydate));
                        cmd.Parameters.Add(new OracleParameter(":SBonus", Bonus));
                        cmd.Parameters.Add(new OracleParameter(":SCommission", Commission));
                        cmd.Parameters.Add(new OracleParameter(":SOverallSalary", OverallSalary));

                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("插入成功！");
                        }
                    }
                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);
                }
            }
            return;
        }
    }
}
