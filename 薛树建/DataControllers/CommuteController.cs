using Microsoft.AspNetCore.Mvc;
using EmployeeSystem.Models.DataManager;
using EmployeeSystem.Models.Tables;
using Newtonsoft.Json;
using OracleInternal.SqlAndPlsqlParser.LocalParsing;

namespace EmployeeSystem.Controllers.DataControllers
{
    // 负责后端Controller与前端view的交互
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class CommuteController : ControllerBase
    {
        // localhost:1522/api/Commute/Get/{"EmployeeID": "E0001", "ContractID": "A0001"}
        // 8.130.119.222:1522/api/Commute/Get/{"EmployeeID": "E0001", "ContractID": "A0001"}
        [HttpGet("{json}")]
        public IActionResult Get(string json)
        {
            try
            {
                CommuteManager manager = new CommuteManager();  // 负责与数据库交互的manager
                if (!manager.Get(json, out List<Commute> tables))
                    return StatusCode(500, $"读取数据失败:");  // 获取数据存放在table中

                List<object> jsonResults = new List<object>();

                foreach (Commute table in tables)
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
            catch (Exception ex) { return StatusCode(500, $"属性不匹配而异常: {ex.Message}"); }  // TODO: 错误码设置
        }

        // localhost:1522/api/Commute/Insert/{"EmployeeID": "E0001", "ContractID": "A0002"}
        // 8.130.119.222:1522/api/Commute/Insert/{"EmployeeID": "E0001", "ContractID": "A0002"}
        [HttpGet("{json}")]
        public IActionResult Insert(string json)
        {
            CommuteManager manager = new CommuteManager();  // 负责与数据库交互的manager
            if (!manager.Insert(json))
                return StatusCode(500, $"写入数据失败:");  // 获取数据存放在table中
            return Ok("写入数据成功");

        }

        // localhost:1522/api/Commute/Update/{"EmployeeID": "E0001", "ContractID": "A0003"}/{"EmployeeID": "E0001", "ContractID": "A0002"}
        // 8.130.119.222:1522/api/Commute/Update/{"EmployeeID": "E0001", "ContractID": "A0003"}/{"EmployeeID": "E0001", "ContractID": "A0002"}
        [HttpGet("{set_json}/{search_json}")]
        public IActionResult Update(string set_json, string search_json)
        {
            CommuteManager manager = new CommuteManager();  // 负责与数据库交互的manager
            if (!manager.Update(set_json, search_json))
                return StatusCode(500, $"更新数据失败:");  // 获取数据存放在table中
            return Ok("更新数据成功");

        }

        // localhost:1522/api/Commute/Delete/{"EmployeeID": "E0001", "ContractID": "A0002"}
        // 8.130.119.222:1522/api/Commute/Delete/{"EmployeeID": "E0001", "ContractID": "A0002"}
        [HttpGet("{json}")]
        public IActionResult Delete(string json)
        {
            CommuteManager manager = new CommuteManager();  // 负责与数据库交互的manager
            if (!manager.Delete(json))
                return StatusCode(500, $"删除数据失败:");  // 获取数据存放在table中
            return Ok("删除数据成功");

        }
    }
}
