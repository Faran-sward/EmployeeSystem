using Newtonsoft.Json.Linq;
using Newtonsoft.Json;

namespace EmployeeSystem.Models.DataValidator
{
    // 负责将表类 Json 序列化
    public class TypeBasedValueConverter : JsonConverter
    {
        private readonly Dictionary<string, string> types;

        public TypeBasedValueConverter(Dictionary<string, string> types)
        {
            this.types = types;
        }

        public override bool CanConvert(Type object_type)
        {
            return object_type == typeof(string);
        }

        public override object? ReadJson(JsonReader reader, Type object_type, object? existing_value, JsonSerializer serializer)
        {
            JToken token = JToken.Load(reader);  // 使用 JToken.Load(reader) 将整个 JSON 数据加载到一个 JToken 对象中
            return token.Value<string>();  // 将 JToken 转换为字符串类型的值
        }

        public override void WriteJson(JsonWriter writer, object? value, JsonSerializer serializer)
        {
            string? stringValue = value?.ToString();
            if (stringValue == null)
            {
                writer.WriteNull();
                return;
            }

            string property_name = writer.Path;
            if (types.TryGetValue(property_name, out string? type) && type == "Date")
            {
                if (DateTime.TryParse(stringValue, out DateTime dateValue))
                {
                    writer.WriteValue(dateValue);
                    return;
                }
            }
            else if (type == "float")
            {
                if (float.TryParse(stringValue, out float floatValue))
                {
                    writer.WriteValue(floatValue);
                    return;
                }
            }
            else if (type == "int")
            {
                if (int.TryParse(stringValue, out int intValue))
                {
                    writer.WriteValue(intValue);
                    return;
                }
            }

            writer.WriteValue(stringValue);
        }
    }
}
