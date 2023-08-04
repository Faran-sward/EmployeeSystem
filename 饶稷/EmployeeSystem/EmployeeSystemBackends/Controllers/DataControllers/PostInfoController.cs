using Microsoft.AspNetCore.Mvc;
using EmployeeSystemBackends.Models.DataManager;
using EmployeeSystemBackends.Models.Tables;
using Newtonsoft.Json;
using EmployeeSystemBackends.Models.DataValidator;

namespace EmployeeSystem.Controllers.DataControllers
{
    // 负责后端Controller与前端view的交互
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class PostInfoController : ControllerBase
    {

        // localhost:1522/api/PostInfo/Get/{"PostID":"CS001"}
        // 8.130.119.222:1522/api/PostInfo/Get/{"PostID":"CS001"}
        [HttpGet("{json}")]
        public IActionResult Get(string json)
        {
            try
            {
                // json = Base64ForJson.Base64Decode(json);  // 将前端传来的数据解码

                PostInfoManager manager = new PostInfoManager();  // 负责与数据库交互的manager
                if (!manager.Get(json, out List<PostInfo> tables))
                    return StatusCode(500, $"读取数据失败:");  // 获取数据存放在table中

                List<object> jsonResults = new List<object>();

                foreach (PostInfo table in tables)
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

        // localhost:1522/api/PostInfo/Insert/{"PostID":"CS001"}
        //  8.130.119.222:1522/api/PostInfo/Insert/{"PostID":"CS001"}

        [HttpGet("{json}")]
        public IActionResult Insert(string json)
        {
            // json = Base64ForJson.Base64Decode(json);  // 将前端传来的数据解码

            PostInfoManager manager = new PostInfoManager();  // 负责与数据库交互的manager
            if (!manager.Insert(json))
                return StatusCode(500, $"写入数据失败:");  // 获取数据存放在table中
            return Ok("写入数据成功");

        }

        // localhost:1522/api/PostInfo/Update/{"PostID":"CS001"}
        [HttpGet("{set_json}/{search_json}")]
        public IActionResult Update(string set_json, string search_json)
        {
            // set_json = Base64ForJson.Base64Decode(set_json);  // 将前端传来的数据解码
            // search_json = Base64ForJson.Base64Decode(search_json);  // 将前端传来的数据解码

            PostInfoManager manager = new PostInfoManager();  // 负责与数据库交互的manager
            if (!manager.Update(set_json, search_json))
                return StatusCode(500, $"更新数据失败:");  // 获取数据存放在table中
            return Ok("更新数据成功");

        }

        // localhost:1522/api/PostInfo/Delete/{"PostID":"CS001"}
        [HttpGet("{json}")]
        public IActionResult Delete(string json)
        {
            // json = Base64ForJson.Base64Decode(json);  // 将前端传来的数据解码

            PostInfoManager manager = new PostInfoManager();  // 负责与数据库交互的manager
            if (!manager.Delete(json))
                return StatusCode(500, $"删除数据失败:");  // 获取数据存放在table中
            return Ok("删除数据成功");

        }
    }
}
