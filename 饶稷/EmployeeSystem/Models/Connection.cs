// 简要说明：
// 命名方式：
//           类名中单词首字母均大写，其余小写，包含多个单词时不出现下划线
//           例：public class ConfigReader
//           函数名中单词首字母均大写，其余小写，包含多个单词不需要出现下划线
//           例：public Configuration? ReadConfig()
//           变量均小写，包含多个单词时需要出现下划线
//           例：private string connection_string = "";
//           常量均大写，包含多个单词时需要出现下划线
//           例：const string CONFIG_PATH = "./config.json";
// 函数要求：
//           鼓励函数体内容控制在25行以内（不需要滚轮就能查看整个函数），函数体内容不允许超过50行
//           输入：
//           输出：
//           功能简介：
// 类  要求：
//           类内成员：同函数输入
//           类内方法：同函数要求
// 注释标准：
//           注释语句与被注释语句在同一行：
//           例：int i = 1;  // comment
//           注释符号与被注释语句间相距两个空格、注释内容与注释符号间相距一个空格
//
//           注释语句在被注释语句的前一行：
//           注释语句与被注释语句缩进相同，注释内容与注释符号间相距一个空格
// 其他要求：
//           只实现了部分功能时，应在相应位置注释  TODO  字样，方便其他人员CTRL+F查找并完善
using Oracle.ManagedDataAccess.Client;
// using System.Text.Json;

namespace EmployeeSystem.Models.Connection  // 负责数据库连接
{
    public class Configuration  // 连接数据库的属性
    {
        public string hostname { get; set; } = string.Empty;
        public string port { get; set; } = string.Empty;
        public string service_name { get; set; } = string.Empty;
        public string user_id { get; set; } = string.Empty;
        public string password { get; set; } = string.Empty;
    }

    /*****************************************************************************************************************
         public class ConfigReader  // 负责从CONFIG_PATH中提取连接数据库属性的值
    {
        const string CONFIG_PATH = "./config.json";  // CONFIG_PATH : 存储访问数据库的配置文件

        public Configuration? ReadConfig()  // 从配置文件中提取连接数据库的属性值
        {
            if (!File.Exists(CONFIG_PATH))  // 生成一个空的配置文件
            {
                File.WriteAllText(CONFIG_PATH, "");
                throw new FileNotFoundException("Config file not found.");
            }

            string json = File.ReadAllText(CONFIG_PATH);  // 读取配置文件内容

            try  // 转换为对象Configuration的实例并返回
            {
                Configuration? config = JsonSerializer.Deserialize<Configuration>(json);
                return config;
            }
            catch (JsonException ex)  // 转换失败则抛出异常
            {
                throw new Exception("Error deserializing config file.", ex);
            }
        }
    }
     *********************************************************************************************************************/

    public class DatabaseLink : IDisposable  // 负责数据库的连接类
    {
        public OracleConnection? connection;  // Oracle的连接类的实例
        private string connection_string = "";  // 连接Oracle数据库的字符串

        // 手动指定连接数据库的属性，并设置连接字符串，并返回设置是否成功
        public bool SetConnectionString(string hostname, string port, string service_name, string user_id, string password)
        {
            connection_string = $"Data Source=" +
                                $"(DESCRIPTION=" +
                                    $"(ADDRESS=(PROTOCOL=TCP)(HOST={hostname})(PORT={port}))" +
                                    $"(CONNECT_DATA=" +
                                        $"(SERVICE_NAME={service_name})));" +
                               $"User Id={user_id};" +
                               $"Password={password};";
            return true;
        }

        /*****************************************************************************************************************
        // 从配置文件中读取数据库的属性，并设置连接字符串，并返回设置是否成功
        public bool SetConnectionString()
        {
            ConfigReader ConfigReader = new ConfigReader();
            Configuration? config = ConfigReader.ReadConfig();
            if (config == null) { return false; }
            // 如果config的对应属性不存在，将会报错 TODO
            return SetConnectionString(config.hostname, config.port, config.service_name, config.user_id, config.password);
        }

        public DatabaseLink()  // 由配置文件执行连接数据库
        {
            if (!SetConnectionString()) Console.WriteLine("connection failed ! ");
            connection = new OracleConnection(connection_string);
            Connect();
        }
         ******************************************************************************************************************/

        // 手动指定并执行连接数据库
        public DatabaseLink(string hostname, string port, string service_name, string user_id, string password)
        {
            try
            {
                if (!SetConnectionString(hostname, port, service_name, user_id, password))
                    Console.WriteLine("connection failed ! ");
                connection = new OracleConnection(connection_string);
                Connect();
            }
            catch(Exception ex) { Console.WriteLine("An error occurred during database connection: " + ex.Message); }
        }

        public void Connect()  // 未连接数据库时可以调用Connect函数连接数据库
        {
            if (connection?.State != System.Data.ConnectionState.Open)
            {
                connection?.Open();
                Console.WriteLine("connect successfully !");
            }
        }
        public void DisConnect()  // 连接数据库时可以调用DisConnect函数断开数据库连接
        {
            if (connection?.State != System.Data.ConnectionState.Closed)
            {
                connection?.Close();
                Console.WriteLine("connection closed ! ");
            }
        }

        public void Dispose()  // 当实例释放时，自动执行DisConnect关闭数据库连接
        {
            DisConnect();
        }
    }
    }
