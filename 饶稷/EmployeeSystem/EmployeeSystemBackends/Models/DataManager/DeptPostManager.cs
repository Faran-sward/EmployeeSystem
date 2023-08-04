using EmployeeSystemBackends.Models.Connection;
using EmployeeSystemBackends.Models.Tables;
using Oracle.ManagedDataAccess.Client;

namespace EmployeeSystemBackends.Models.DataManager
{
    // 负责 model 与 Controller 间的交互
    // 更新数据库 或者 从数据库获得所需要的信息并存放在model中
    public class DeptPostManager
    {
        // private DatabaseLink link = new DatabaseLink("localhost", "1521", "orcl", "TESTER", "123456");  // TODO
        private DatabaseLink link = new DatabaseLink();  // 如需修改，请在DatabaseLink类中直接指定你需要的参数，请勿再此修改

        // 根据JSON信息，从数据库获取对应值，默认返回整个元组
        public bool Get(string json, out List<DeptPost> ret)
        {
            ret = new List<DeptPost>();
            if (!string.IsNullOrEmpty(json))
            {
                DeptPost temp = new DeptPost();  // 新建表用于存储 json 中属性及值
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
                    DeptPost contract = new DeptPost();
                    // 使用 SetValuesThroughOrclReader 函数从 OracleDataReader 中读取一行值并设置到 DeptPost 实例中
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

        public bool Insert(string json)
        {
            if (!string.IsNullOrEmpty(json))
            {
                DeptPost temp = new DeptPost();  // 新建表用于存储 json 中属性及值
                temp.SetValuesThroughJson(json);  // 从 json 转化为表类(model)
                temp.GetValuesAsArray(out string[] attributes, out string[] values);  // 得到待插入的对应属性和值

                string[] attributes_params = attributes.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Insert(temp.table_name, attributes, attributes_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // 创建OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, attributes_params, values);  // 添加参数
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// 执行结果
                link.DisConnect();  // 关闭数据库连接
                return true;
            }
            return false;
        }

        public bool Update(string set_json, string search_json)
        {
            if (!string.IsNullOrEmpty(set_json) && !string.IsNullOrEmpty(search_json))
            {
                DeptPost set_temp = new DeptPost(), search_temp = new DeptPost();  // 新建表用于存储 json 中属性及值
                set_temp.SetValuesThroughJson(set_json);  // 从 json 转化为表类(model)
                set_temp.GetValuesAsArray(out string[] attributes, out string[] values);  // 得到待插入的对应属性和值

                set_temp.SetValuesThroughJson(search_json);  // 从 json 转化为表类(model)
                set_temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // 得到待插入的对应属性和值

                string[] attribute_params = attributes.Select(item => "param" + item).ToArray();
                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();

                string sql = SqlGenerator.Update(set_temp.table_name, attributes,
                    attribute_params, search_key_names, search_key_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // 创建OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, attribute_params, values);  // 添加参数
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // 添加参数
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// 执行结果
                link.DisConnect();  // 关闭数据库连接
                return true;
            }
            return false;
        }

        public bool Delete(string json)
        {
            if (!string.IsNullOrEmpty(json))
            {
                DeptPost temp = new DeptPost();  // 新建表用于存储 json 中属性及值
                temp.SetValuesThroughJson(json);  // 从 json 转化为表类(model)
                temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // 得到待插入的对应属性和值

                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Delete(temp.table_name, search_key_names, search_key_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // 创建OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // 添加参数
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// 执行结果
                link.DisConnect();  // 关闭数据库连接
                return true;
            }
            return false;
        }

    }
}
