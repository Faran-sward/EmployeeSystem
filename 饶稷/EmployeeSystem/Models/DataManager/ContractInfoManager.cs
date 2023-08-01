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
        // private DatabaseLink link = new DatabaseLink("192.168.88.153", "1521", "employee_system", "SYSTEM", "ORACLEsystem0");

        public bool Get(string json, out List<ContractInfo> ret)
        {
            ret = new List<ContractInfo> ();
            if(!string.IsNullOrEmpty(json)) 
            {
                ContractInfo temp = new ContractInfo ();  // 新建表用于存储 json 中属性及值
                temp.SetValuesThroughJson(json);  // 从 json 转化为表类(model)
                temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // 得到搜索码

                string[] result_names = { "*" };  // 默认返回整个元组
                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Search(temp.table_name, search_key_names, search_key_params, result_names);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // 创建OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // 添加参数
                Console.WriteLine(cmd.CommandText);
                cmd.ExecuteNonQuery();
                OracleDataReader reader = cmd.ExecuteReader();
                while (true)  // 循环读入
                {
                    ContractInfo contract = new ContractInfo();
                    // 使用 SetValuesThroughOrclReader 函数从 OracleDataReader 中读取一行值并设置到 ContractInfo 实例中
                    if (contract.SetValuesThroughOrclReader(reader))
                    {
                        Console.WriteLine("read successfully! ");
                        ret.Add(contract);
                    }
                    else
                        break;
                }

                link.DisConnect();  // 关闭数据库连接
                return true;
            }
            return false;
        }


    }
}
