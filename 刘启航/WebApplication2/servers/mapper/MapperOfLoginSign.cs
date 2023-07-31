using Oracle.ManagedDataAccess.Client;
using Microsoft.AspNetCore.Mvc;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Database;
using System.Reflection.PortableExecutable;
using System.Diagnostics.Contracts;

namespace WebApplication2.servers.mapper
{
    public class MapperOfLoginSign
    {
        private static string connectionString = "Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=8.130.115.212)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=ORCL)));Persist Security Info=True;User ID=TESTER;Password=123456;";
        //用于注册前查询是否有重复项
        public string CheckRepeat(string account)
        {
            int status = 0;

            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("MapperOfLoginSign文件中CheckRepeat函数中连接成功！");
                    string sqlInsert;

                    sqlInsert = string.Format("SELECT * FROM logininfo WHERE account= :accountData");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":accountData", account));

                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {

                            if (reader.Read())
                            {
                                // 读取到至少一行数据
                                Console.WriteLine("CheckRepeat函数读取到至少一行数据！");
                                status = -1;
                                // 在这里可以处理读取到的数据
                            }
                            else
                            {
                                // 没有数据
                                Console.WriteLine("CheckRepeat函数没有读取到任何数据！");
                                status = 1;
                            }
                            Console.WriteLine("MapperOfLoginSign文件中CheckRepeat函数中查询成功！");

                        }
                    }

                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("MapperOfLoginSign文件中CheckRepeat函数连接或操作数据库时发生错误：" + ex.Message);

                }
            }
            if (status == 1) { return "OK"; }
            else if (status == -1) { return "NO"; }
            else { return "sqlfindrepeaterr"; }
        }

        //用于登录
        public string Login(string account,string password)
        {
            int status = 0;

            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("MapperOfLoginSign文件中Login函数中连接成功！");
                    string sqlInsert;

                    sqlInsert = string.Format("SELECT * FROM logininfo WHERE account= :accountData AND keyword= :passwordData");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":accountData", account));
                        cmd.Parameters.Add(new OracleParameter(":passwordData", password));


                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("MapperOfLoginSign文件中Login函数中查询成功！");
                            if (reader.Read())
                            {
                                // 读取到至少一行数据
                                Console.WriteLine("Login函数读取到至少一行数据！");
                                status = 1;
                                // 在这里可以处理读取到的数据
                            }
                            else
                            {
                                // 没有数据
                                Console.WriteLine("Login函数没有读取到任何数据！");
                                status = -1;
                            }

                        }
                    }

                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("MapperOfLoginSign文件中Login函数连接或操作数据库时发生错误：" + ex.Message);
                }
            }

            if (status == 1) { return "OK"; }
            else if (status == -1) { return "NO"; }
            else { return "sqlloginerr"; }
        }

        //用于注册
        public string Sign(string account, string password)
        {
            int status = 0;

            using (OracleConnection connection = new OracleConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    Console.WriteLine("MapperOfLoginSign文件中Sign函数中连接成功！");
                    string sqlInsert;

                    sqlInsert = string.Format("insert into logininfo (account,keyword) values(:accountData ,:passwordData)");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":accountData", account));
                        cmd.Parameters.Add(new OracleParameter(":passwordData", password));

                        
                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("MapperOfLoginSign文件中Sign函数中写入成功！");
                            status = 1;

                        }
                    }

                    connection.Close();
                }
                catch (Exception ex)
                {
                    Console.WriteLine("MapperOfLoginSign文件中Sign函数连接或操作数据库时发生错误：" + ex.Message);
                }
            }

            if (status == 1) { return "OK"; }
            else { return "sqlsignerr"; }
        }
    }
}
