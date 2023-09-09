using Oracle.ManagedDataAccess.Client;
using System.Diagnostics.Contracts;
using WebApplication2.entities;
using WebApplication2.entities.backentities;
using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.servers.mapper
{
    public class MapperOfDepartment
    {
        private static string connectionString = "Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=8.130.119.222)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=ORCL)));Persist Security Info=True;User ID=project;Password=project;";
        //使用时，需要四个nuget包
        public List<GetDeptInfo> getAllDepartment()
        {
            List<GetDeptInfo> rb = new List<GetDeptInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    // 模拟将合同信息插入数据库
                    //sqlInsert = string.Format("INSERT INTO contractinfo VALUES (:employeeID, :contractId, :contractType, :contractState, to_date('{0}','yyyy-mm-dd'), to_date('{1}','yyyy-mm-dd'), :documentLink)");
                    sqlInsert = string.Format("SELECT * FROM DepartmentInfo");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {

                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                GetDeptInfo departmentInfo = new GetDeptInfo { };

                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));


                                    departmentInfo.DepartmentID = reader.GetString(0);
                                    departmentInfo.DepartmentTitle = reader.GetString(1);
                                    departmentInfo.Building = reader.GetString(2);
                                    departmentInfo.Layer = (reader.GetInt32(3));

                                }
                                rb.Add(departmentInfo);
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

        public List<GetDeptInfo> getCertainDepartment(String DepartmentTitle)
        {
            List<GetDeptInfo> rb = new List<GetDeptInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    // 模拟将合同信息插入数据库
                    //sqlInsert = string.Format("INSERT INTO contractinfo VALUES (:employeeID, :contractId, :contractType, :contractState, to_date('{0}','yyyy-mm-dd'), to_date('{1}','yyyy-mm-dd'), :documentLink)");
                    sqlInsert = string.Format("SELECT * FROM DepartmentInfo WHERE DepartmentTitle= :SDdepartmentTitle");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDdepartmentTitle", DepartmentTitle));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                GetDeptInfo departmentInfo = new GetDeptInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    departmentInfo.DepartmentID = reader.GetString(0);
                                    departmentInfo.DepartmentTitle = reader.GetString(1);
                                    departmentInfo.Building = reader.GetString(2);
                                    departmentInfo.Layer = (reader.GetInt32(3));
                                }
                                rb.Add(departmentInfo);
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

        public List<GetDeptInfo> getCertainDepartmentFromId(String DepartmentId)
        {
            List<GetDeptInfo> rb = new List<GetDeptInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    // 模拟将合同信息插入数据库
                    //sqlInsert = string.Format("INSERT INTO contractinfo VALUES (:employeeID, :contractId, :contractType, :contractState, to_date('{0}','yyyy-mm-dd'), to_date('{1}','yyyy-mm-dd'), :documentLink)");
                    sqlInsert = string.Format("SELECT * FROM DepartmentInfo WHERE DepartmentID= :SDepartmentId");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentId", DepartmentId));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                GetDeptInfo departmentInfo = new GetDeptInfo { };

                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    departmentInfo.DepartmentID = reader.GetString(0);
                                    departmentInfo.DepartmentTitle = reader.GetString(1);
                                    departmentInfo.Building = reader.GetString(2);
                                    departmentInfo.Layer = (reader.GetInt32(3));
                                }
                                rb.Add(departmentInfo);
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

        public List<GetOrgInfo> getCertainOrg(String DepartmentID)
        {
            List<GetOrgInfo> rb = new List<GetOrgInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    // 模拟将合同信息插入数据库
                    //sqlInsert = string.Format("INSERT INTO contractinfo VALUES (:employeeID, :contractId, :contractType, :contractState, to_date('{0}','yyyy-mm-dd'), to_date('{1}','yyyy-mm-dd'), :documentLink)");
                    sqlInsert = string.Format("SELECT * FROM Dept_Post WHERE DepartmentID= :SDepartmentID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                GetOrgInfo orgInfo = new GetOrgInfo { };

                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    orgInfo.PostID = reader.GetString(1);
                                    orgInfo.CurrentScale = (reader.GetInt32(2));
                                    orgInfo.EmulatedScale = (reader.GetInt32(3));
                                }
                                rb.Add(orgInfo);
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

        public List<GetPostionInfo> getCertainPost(String PostID)
        {
            List<GetPostionInfo> rb = new List<GetPostionInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM PostInfo WHERE PostID= :SPostID");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                GetPostionInfo info = new GetPostionInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    info.PostID = reader.GetString(0);
                                    info.PostTitle = reader.GetString(1);
                                    info.PostType = reader.GetString(2);    
                                    info.PostLevel = reader.GetString(3);
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
        public GetPostionInfo getCertainPos(String PostID)
        {
            GetPostionInfo rb = new GetPostionInfo();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                   sqlInsert = string.Format("SELECT * FROM PostInfo WHERE PostID= :SPostID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                for (int i = 0; i < 1; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    rb.PostID = reader.GetString(0);
                                    rb.PostTitle = reader.GetString(1);
                                    rb.PostType = reader.GetString(2);
                                    rb.PostLevel = reader.GetString(3);
                                }
                                break;
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

        public List<GetEmployeeInfo> getCertainEmployee(String PostID)
        {
            List<GetEmployeeInfo> rb = new List<GetEmployeeInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM EmployeeInfo WHERE CurrentPostID= :SCurrentPostID");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SCurrentPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("EmployeeInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmployeeInfo info = new GetEmployeeInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader[i].ToString());
                                    info.EmployeeID = reader[0].ToString();
                                    info.CurrentPostID = reader[1].ToString();
                                    info.CurrentCity = reader[2].ToString();
                                    info.StartWorkingDate = reader[3].ToString();
                                    info.BasicSalary = reader.GetFloat(4);
                                    info.PassWord = reader[5].ToString();
                                    if (info.PassWord != null)
                                        info.PassWord = Convert.ToBase64String(System.Text.Encoding.Default.GetBytes(reader[5].ToString()));
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

        public List<GetEmployeeInfo> Login(String EmployeeId,String keyWord)
        {
            List<GetEmployeeInfo> rb = new List<GetEmployeeInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM EmployeeInfo WHERE EMPLOYEEID= :SEMPLOYEEID and Pass_Word = :SPassWord");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEMPLOYEEID", EmployeeId));
                        cmd.Parameters.Add(new OracleParameter(":SPassWord", keyWord));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("EmployeeInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmployeeInfo info = new GetEmployeeInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader[i].ToString());
                                    info.EmployeeID = reader[0].ToString();
                                    info.CurrentPostID = reader[1].ToString();
                                    info.CurrentCity = reader[2].ToString();
                                    info.StartWorkingDate = reader[3].ToString();
                                    info.BasicSalary = reader.GetFloat(4);
                                    info.PassWord = reader[5].ToString();
                                    if (info.PassWord != null)
                                        info.PassWord = Convert.ToBase64String(System.Text.Encoding.Default.GetBytes(reader[5].ToString()));
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

        public List<GetEmployeeInfo> getALLEmployee()
        {
            List<GetEmployeeInfo> rb = new List<GetEmployeeInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM EmployeeInfo");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("EmployeeInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmployeeInfo info = new GetEmployeeInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader[i].ToString());
                                    info.EmployeeID = reader[0].ToString();
                                    info.CurrentPostID = reader[1].ToString();
                                    info.CurrentCity = reader[2].ToString();
                                    info.StartWorkingDate = reader[3].ToString();
                                    info.BasicSalary = reader.GetFloat(4);
                                    info.PassWord = reader[5].ToString();
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

        public List<GetEmployeeInfo> getEmployeeInfo(String AEmployeeID)
        {
            List<GetEmployeeInfo> rb = new List<GetEmployeeInfo>();
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT * FROM EmployeeInfo WHERE EmployeeID = :SEmployeeID");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", AEmployeeID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("EmployeeInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmployeeInfo info = new GetEmployeeInfo { };
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader[i].ToString());
                                    info.EmployeeID = reader[0].ToString();
                                    info.CurrentPostID = reader[1].ToString();
                                    info.CurrentCity = reader[2].ToString();
                                    info.StartWorkingDate = reader[3].ToString();
                                    info.BasicSalary = reader.GetFloat(4);
                                    info.PassWord = reader[5].ToString();
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

        public void newBuildDept(String DepartmentID, String DepartmentTitle, String Building, int layer)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("insert into DepartmentInfo values(:SDepartmentID,:SDepartmentTitle,:SBuilding,:Slayer)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentTitle", DepartmentTitle));
                        cmd.Parameters.Add(new OracleParameter(":SBuilding", Building));
                        cmd.Parameters.Add(new OracleParameter(":Slayer", layer));
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
            return ;
        }
        public void newPostInfo(String PostID, String PostTitle, String PostType, String PostLevel)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("insert into PostInfo values(:SPostID,:SPostTitle,:SPostType,:SPostLevel,null)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        cmd.Parameters.Add(new OracleParameter(":SPostTitle", PostTitle));
                        cmd.Parameters.Add(new OracleParameter(":SPostType", PostType));
                        cmd.Parameters.Add(new OracleParameter(":SPostLevel", PostLevel));
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
        public void newDeptPost(String DepartmentID, String PostID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("insert into Dept_Post values(:SDepartmentID,:SPostID,0,0)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()){Console.WriteLine("插入成功！");}
                    }
                    connection.Close();
                }
                catch (Exception ex){Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message);}
            }
            return;
        }

        public void newWorkSchedule( String PostID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("insert into WorkSchedule values(:SPostID,null, null)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("插入成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public String getEmpNameFromEmpId(String EmpID)
        {
            String resultName = "";
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("数据库连接成功！");
                    string sqlInsert = string.Format("SELECT Name FROM FundamentalInfo WHERE EmployeeID= :SEmployeeID");
                    List<string> results = new List<string>();
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", EmpID));
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("FundamentalInfo表查询成功！");
                            while (reader.Read())
                            {
                                GetEmpSalaryInfo info = new GetEmpSalaryInfo { };
                                for (int i = 0; i < 1; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));
                                    resultName = reader.GetString(0);
                                }
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
            return resultName;
        }

        public void updatePostScale(String DepartmentID, String PostID,int NewScale)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("update Dept_Post set EmulatedScale = :SEmulatedScale where DepartmentID=:SDepartmentID and PostID=:SPostID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SEmulatedScale", NewScale));
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("更新成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public void delDeptInfo(String DepartmentID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("delete from DepartmentInfo where DepartmentID=:SDepartmentID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SDepartmentID", DepartmentID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("删除成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public void delPostInfo(String PostID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("delete from PostInfo where PostID=:SPostID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("删除成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public void delDept_Post(String PostID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("delete from Dept_Post where PostID=:SPostID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("删除成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public void delWorkSchedule(String PostID)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("delete from WorkSchedule where PostID=:SPostID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SPostID", PostID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("删除成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }

        public void updateBasicSalary(String EmpID, float NewValue)
        {
            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("连接成功！");
                    string sqlInsert;
                    List<string> results = new List<string>();
                    sqlInsert = string.Format("update EmployeeInfo set BasicSalary = :SBasicSalary where EmployeeID=:SEmployeeID");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":SBasicSalary", NewValue));
                        cmd.Parameters.Add(new OracleParameter(":SEmployeeID", EmpID));
                        using (OracleDataReader reader = cmd.ExecuteReader()) { Console.WriteLine("更新成功！"); }
                    }
                    connection.Close();
                }
                catch (Exception ex) { Console.WriteLine("连接或操作数据库时发生错误：" + ex.Message); }
            }
            return;
        }
    }
}
