using EmployeeSystem.Models.Connection;
using EmployeeSystem.Models.Tables;
using Oracle.ManagedDataAccess.Client;

namespace EmployeeSystem.Models.DataManager
{
    // 负责 model 与 Controller 间的交互
    // 更新数据库 或者 从数据库获得所需要的信息并存放在model中
    public class ContractInfoManager
    {
        private DatabaseLink link = new DatabaseLink("localhost", "1521", "orcl", "TESTER", "123456");  // TODO

        // 根据表的主码，获取表中指定的一行，结果存放在ret中
        public bool GetOneTuple(string employee_id, string contract_id, out ContractInfo ret)
        {
            ret = new ContractInfo();  // 表，也可看作model
            if(!string.IsNullOrEmpty(employee_id) && !string.IsNullOrEmpty(contract_id))
            {
                link.Connect();  // 开启数据库连接

                string sql = "SELECT * " +
                             "FROM ContractInfo " +
                             "WHERE EmployeeID = :employee_id AND ContractID = :contract_id";


                using (OracleCommand cmd = new OracleCommand(sql, link.connection))
                {
                    cmd.Parameters.Add(new OracleParameter("employeeID", employee_id));
                    cmd.Parameters.Add(new OracleParameter("contract_id", contract_id));
                    cmd.ExecuteNonQuery();
                    OracleDataReader reader = cmd.ExecuteReader();
                    bool result =  ret.SetValuesThroughOrclReader(reader);  // 调用表的方法，从reader中读取数据

                    link.DisConnect();  // 关闭数据库连接
                    return result;
                }
            }
            return false;
        }

        public bool UpdateOneTuple(string employee_id, string contract_id, out ContractInfo ret)
        {
            ret = new ContractInfo();  // 表，也可看作model
            if (!string.IsNullOrEmpty(employee_id) && !string.IsNullOrEmpty(contract_id))
            {
                link.Connect();  // 开启数据库连接

                string sql = "SELECT * " +
                             "FROM ContractInfo " +
                             "WHERE EmployeeID = :employee_id AND ContractID = :contract_id";

                using (OracleCommand cmd = new OracleCommand(sql, link.connection))
                {
                    cmd.Parameters.Add(new OracleParameter("employeeID", employee_id));
                    cmd.Parameters.Add(new OracleParameter("contract_id", contract_id));
                    cmd.ExecuteNonQuery();
                    OracleDataReader reader = cmd.ExecuteReader();
                    bool result = ret.SetValuesThroughOrclReader(reader);  // 调用表的方法，从reader中读取数据

                    link.DisConnect();  // 关闭数据库连接
                    return result;
                }
            }
            return false;
        }

    }
}
