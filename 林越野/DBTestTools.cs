using Oracle.ManagedDataAccess.Client;
using WebApplication1.Models;
using Microsoft.AspNetCore.Mvc;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Database;
using System.Reflection.PortableExecutable;

namespace WebApplication1
{
    public class ContractManagement
    {
        //使用时，需要四个nuget包
        private static string connectionString = "Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=8.130.115.212)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=ORCL)));Persist Security Info=True;User ID=TESTER;Password=123456;";
        //private static string connectionString = "Data Source=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=ORCL)));Persist Security Info=True;User ID=system;Password=1234;";
        public Contract SignContract(string Employee_ID, string Contract_ID)
        {
            Contract contract = new Contract { };
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
                    sqlInsert = string.Format("SELECT * FROM contractinfo WHERE EmployeeID= :employeeID AND ContractID= :contractId");
                    using (OracleCommand cmd = new OracleCommand(sqlInsert, connection))
                    {
                        cmd.Parameters.Add(new OracleParameter(":employeeID", Employee_ID));
                        cmd.Parameters.Add(new OracleParameter(":contractId", Contract_ID));

                        using (OracleDataReader reader = cmd.ExecuteReader())
                        {
                            Console.WriteLine("查询成功！");
                            while (reader.Read())
                            {
                                for (int i = 0; i < reader.FieldCount; i++)
                                {
                                    Console.WriteLine(reader.GetString(i));


                                    contract.EmployeeID = reader.GetString(0);
                                    contract.ContractId = reader.GetString(1);
                                    contract.ContractType = reader.GetString(2);
                                    contract.ContractState = reader.GetString(3);
                                    contract.EffectiveDate = reader.GetString(4);
                                    contract.InoperativeDate = reader.GetString(5);
                                    contract.DocumentLink = reader.GetString(6);

                                }
                                //string result = reader.GetString(0); // 根据您的查询结果进行调整
                                //Console.WriteLine("{0}", result);
                                //results.Add(result);
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
            return contract;
        }
    }
}
