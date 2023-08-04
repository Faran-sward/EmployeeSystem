using EmployeeSystemBackends.Models.DataValidator;
using Newtonsoft.Json;
using Oracle.ManagedDataAccess.Client;

namespace EmployeeSystemBackends.Models.Tables
{
    public class DeptPost
    {
        public string table_name = AttributeNames.DeptPostTableName;

        private Dictionary<string, string?> values = new Dictionary<string, string?>();

        private Dictionary<string, string> types = new Dictionary<string, string>();

        public DeptPost() // 初始化字典 types
        {
            for (int i = 0; i < AttributeNames.DeptPostAttributeNames.Length; i++)
            {
                string name = AttributeNames.DeptPostAttributeNames[i];
                string type = AttributeNames.DeptPostAttributeTypes[i];
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

        public bool SetValuesThroughOrclReader(OracleDataReader reader)  // 从 OracleReader 中读取一行值并设置
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

        public bool SetValuesThroughArray(string[] names, string[] values)  // 将 names 对应的属性值设置为 values
        {
            try
            {
                if (names.Length != values.Length)
                    return false;
                for (int i = 0; i < names.Length; i++) { this.values[names[i]] = values[i]; }
                return true;
            }
            catch (Exception ex) { Console.WriteLine("写入数据出错：" + ex.Message); return false; }
        }

        public void GetValuesAsArray(out string[] names, out string[] values)  // 将 values 字典中不为空的内容转化为数组
        {
            List<string> nonNullNames = new List<string>();
            List<string> nonNullValues = new List<string>();

            foreach (var kvp in this.values)
            {
                if (kvp.Value != null)
                {
                    nonNullNames.Add(kvp.Key);
                    nonNullValues.Add(kvp.Value);
                }
            }

            names = nonNullNames.ToArray();
            values = nonNullValues.ToArray();
        }

        public bool SetValuesThroughJson(string json)  // 从 json 语句中读取并设置属性值
        {
            try
            {
                Dictionary<string, string?>? jsonValues =
                    JsonConvert.DeserializeObject<Dictionary<string, string?>>(json);

                if (jsonValues == null) { return false; }

                // 将从 JSON 中获取的属性值设置到 values 字典中
                foreach (var kvp in jsonValues)
                {
                    values[kvp.Key] = Convert.ToString(kvp.Value);
                }

                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine("解析 JSON 出错：" + ex.Message);
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

        public bool IsEmpty()  // 判断目前存储的属性值是否为空
        {
            foreach (KeyValuePair<string, string?> kvp in values)
            {
                if (kvp.Value != null) return false;
            }
            return true;
        }
    }
}
