using Oracle.ManagedDataAccess.Client;
using Newtonsoft.Json;
using EmployeeSystem.Models.DataValidator;

namespace EmployeeSystem.Models.Tables
{
    public class EmployeeInfo
    {
        private Dictionary<string, string?> values = new Dictionary<string, string?>();

        private Dictionary<string, string> types = new Dictionary<string, string>();

        public EmployeeInfo() // 初始化字典 types
        {
            for (int i = 0; i < AttributeNames.EmployeeInfoArrributeNames.Length; i++)
            {
                string name = AttributeNames.EmployeeInfoArrributeNames[i];
                string type = AttributeNames.EmployeeInfoArrributeTypes[i];
                types[name] = type;
                values[name] = null;
            }
        } 

        public string? GetValue(string name)  // 输入属性名 name ，获取对应值
        {
            if (values.TryGetValue(name, out var value))
            {
                return value;
            }
            else// 如果字典中不存在指定的键，返回一个默认值或者进行其他处理
            {
                Console.WriteLine($"键 '{name}' 不存在于字典中。");
                return string.Empty;
            }
        }

        public bool SetValue(string name, string value)  // 输入属性名 name 设置对应值 value
        {
            if (values.ContainsKey(name))
            {
                values[name] = value;
                return true; // 表示设置成功
            }
            else
            {
                Console.WriteLine($"键 '{name}' 不存在于字典中，无法设置值。");
                return false;  // 表示设置失败
            }
        }

        public bool SetValuesThroughOrclReader(OracleDataReader reader)  // 从OracleReader中读取一行值并设置
        {
            try
            {
                if (reader.Read())
                {
                    foreach (var kvp in values)
                    {
                        string name = kvp.Key;
                        if (!reader.IsDBNull(reader.GetOrdinal(name)))
                        {
                            string value = reader.GetString(reader.GetOrdinal(name));
                            values[name] = value;
                        }
                    }
                    return true;
                }
                return false;
            }
            catch (Exception ex)
            {
                Console.WriteLine("读取数据出错：" + ex.Message);
                return false;
            }
        }

        public string GetValuesAsJson()  // 将 values 字典的内容序列化为 JSON 字符串
        {
            try
            {
                Dictionary<string, string?> j_values = 
                    values.Where(kvp => kvp.Value != null).ToDictionary(kvp => kvp.Key, kvp => kvp.Value);

                string jsonString = JsonConvert.SerializeObject(j_values, new JsonSerializerSettings
                {
                    Converters = new List<JsonConverter> { new TypeBasedValueConverter(types) },
                    Formatting = Formatting.Indented,
                    DefaultValueHandling = DefaultValueHandling.Ignore // 忽略 null 值
                });
                return jsonString;
            }
            catch (Exception ex)
            {
                Console.WriteLine("序列化数据出错：" + ex.Message);
                return string.Empty;
            }
        }
    }
}
