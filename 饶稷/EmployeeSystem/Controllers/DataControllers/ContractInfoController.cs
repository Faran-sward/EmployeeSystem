using Microsoft.AspNetCore.Mvc;
using EmployeeSystem.Controllers.DataControllers;
using EmployeeSystem.Models.DataManager;
using EmployeeSystem.Models.Tables;
using Newtonsoft.Json;

namespace EmployeeSystem.Controllers.DataControllers
{
    // 负责后端Controller与前端view的交互
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ContractInfoController : ControllerBase
    {
        [HttpGet("{json}")]
        public IActionResult Get(string json)
        {
            try
            {
                ContractInfoManager manager = new ContractInfoManager();  // 负责与数据库交互的manager
                manager.Get(json, out List<ContractInfo> tables);  // 获取数据存放在table中

                List<object> jsonResults = new List<object>();

                foreach (ContractInfo table in tables)
                {
                    string result = table.GetValuesAsJson();  // 将结果转化为 JSON 格式
                    object? jsonObject = JsonConvert.DeserializeObject(result); // 反序列化 JSON 字符串为对象
                    if (jsonObject == null)
                        throw new JsonSerializationException("JSON反序列化异常");
                    jsonResults.Add(jsonObject);
                }

                // 将对象列表序列化为 JSON 数组
                string finalJson = JsonConvert.SerializeObject(jsonResults, Formatting.Indented);

                return Ok(finalJson);
            }
            catch (Exception ex){ return StatusCode(500, $"属性不匹配而异常: {ex.Message}"); }  // TODO: 错误码设置
            // localhost:1522/api/ContractInfo/Get/{"EmployeeID": "E0001", "ContractID": "A0001"}
            // 8.130.119.222:1522/api/ContractInfo/Get/{"EmployeeID": "E0001", "ContractID": "A0001"}
        }
    }
}
