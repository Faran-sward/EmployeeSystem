using Microsoft.AspNetCore.Mvc;
using EmployeeSystemBackends.Models.DataManager;
using EmployeeSystemBackends.Models.Tables;
using Newtonsoft.Json;

namespace EmployeeSystemBackends.Controllers.DataControllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class BusinessInfoController : ControllerBase
    {
        public IActionResult GetAll()
        {
            try
            {
                // json = Base64ForJson.Base64Decode(json);  // add: 将前端传来的数据解码

                BusinessInfoManager manager = new BusinessInfoManager();  // 负责与数据库交互的manager
                if (!manager.GetAll(out List<BusinessInfo> tables))
                    return StatusCode(500, $"读取数据失败:");  // 获取数据存放在table中

                List<object> jsonResults = new List<object>();

                foreach (BusinessInfo table in tables)
                {
                    string result = table.GetValuesAsJson();  // 将结果转化为 JSON 格式
                    object? jsonObject = JsonConvert.DeserializeObject(result); // 反序列化 JSON 字符串为对象
                    if (jsonObject == null)
                        throw new JsonSerializationException("JSON反序列化异常");
                    jsonResults.Add(jsonObject);
                }

                // 将对象列表序列化为 JSON 数组
                string finalJson = JsonConvert.SerializeObject(jsonResults, Formatting.Indented);
                if (finalJson != "[]")  // 没查到相应信息
                {
                    // finalJson = Base64ForJson.Base64Encode(finalJson);  // add: 将准备发给前端的数据进行编码
                    return Ok(finalJson);
                }
                else
                    return StatusCode(500, "未查找到相应信息");
            }
            catch (Exception ex) { return StatusCode(500, $"属性不匹配而异常: {ex.Message}"); }  // TODO: 错误码设置
        }

        [HttpGet("{json}")]
        public IActionResult Get(string json)
        {
            try
            {
                // json = Base64ForJson.Base64Decode(json);  // add: 将前端传来的数据解码

                BusinessInfoManager manager = new BusinessInfoManager();  // 负责与数据库交互的manager
                if (!manager.Get(json, out List<BusinessInfo> tables))
                    return StatusCode(500, $"读取数据失败:");  // 获取数据存放在table中

                List<object> jsonResults = new List<object>();

                foreach (BusinessInfo table in tables)
                {
                    string result = table.GetValuesAsJson();  // 将结果转化为 JSON 格式
                    object? jsonObject = JsonConvert.DeserializeObject(result); // 反序列化 JSON 字符串为对象
                    if (jsonObject == null)
                        throw new JsonSerializationException("JSON反序列化异常");
                    jsonResults.Add(jsonObject);
                }

                // 将对象列表序列化为 JSON 数组
                string finalJson = JsonConvert.SerializeObject(jsonResults, Formatting.Indented);
                if (finalJson != "[]")  // 没查到相应信息
                {
                    // finalJson = Base64ForJson.Base64Encode(finalJson);  // add: 将准备发给前端的数据进行编码
                    return Ok(finalJson);
                }
                else
                    return StatusCode(500, "未查找到相应信息");
            }
            catch (Exception ex) { return StatusCode(500, $"属性不匹配而异常: {ex.Message}"); }  // TODO: 错误码设置
        }

        // localhost:1522/api/BusinessInfo/Insert/{"EmployeeID": "E0001", "ContractID": "A0002"}
        // 8.130.119.222:1522/api/BusinessInfo/Insert/{"EmployeeID": "E0001", "ContractID": "A0002"}
        [HttpPost("{json}")]
        public IActionResult Insert(string json)
        {
            // json = Base64ForJson.Base64Decode(json);  // add: 将前端传来的数据解码

            BusinessInfoManager manager = new BusinessInfoManager();  // 负责与数据库交互的manager
            if (!manager.Insert(json))
                return StatusCode(500, $"写入数据失败:");  // 获取数据存放在table中
            return Ok("写入数据成功");

        }

        // localhost:1522/api/BusinessInfo/Update/{"EmployeeID": "E0001", "FundamentalID": "A0003"}/{"EmployeeID": "E0001", "FundamentalID": "A0002"}
        // 8.130.119.222:1522/api/BusinessInfo/Update/{"EmployeeID": "E0001", "FundamentalID": "A0003"}/{"EmployeeID": "E0001", "FundamentalID": "A0002"}
        [HttpPost("{set_json}/{search_json}")]
        public IActionResult Update(string set_json, string search_json)
        {
            // set_json = Base64ForJson.Base64Decode(set_json);  // add: 将前端传来的数据解码
            // search_json = Base64ForJson.Base64Decode(search_json);  // add: 将前端传来的数据解码

            BusinessInfoManager manager = new BusinessInfoManager();  // 负责与数据库交互的manager
            if (!manager.Update(set_json, search_json))
                return StatusCode(500, $"更新数据失败:");  // 获取数据存放在table中
            return Ok("更新数据成功");
        }

        // localhost:1522/api/BusinessInfo/Delete/{"EmployeeID": "E0001", "ContractID": "A0002"}
        // 8.130.119.222:1522/api/BusinessInfo/Delete/{"EmployeeID": "E0001", "ContractID": "A0002"}
        [HttpPost("{json}")]
        public IActionResult Delete(string json)
        {
            // json = Base64ForJson.Base64Decode(json);  // add: 将前端传来的数据解码

            BusinessInfoManager manager = new BusinessInfoManager();  // 负责与数据库交互的manager
            if (!manager.Delete(json))
                return StatusCode(500, $"删除数据失败:");  // 获取数据存放在table中
            return Ok("删除数据成功");

        }
    }
}