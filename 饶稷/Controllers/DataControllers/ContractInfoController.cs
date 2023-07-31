using Microsoft.AspNetCore.Mvc;
using EmployeeSystem.Controllers.DataControllers;
using EmployeeSystem.Models.DataManager;
using EmployeeSystem.Models.Tables;

namespace EmployeeSystem.Controllers.DataControllers
{
    // 负责后端Controller与前端view的交互
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ContractInfoController : ControllerBase
    {
        [HttpGet("{employee_id}/{contract_id}")]
        public IActionResult GetOneTuple(string employee_id, string contract_id)
        {
            try
            {
                ContractInfoManager manager = new ContractInfoManager();  // 负责与数据库交互的manager
                manager.GetOneTuple(employee_id, contract_id, out ContractInfo table);  // 获取数据存放在table中
                string result = table.GetValuesAsJson();  // 将结果转化为Json格式

                return Ok(result);
            }
            catch (Exception ex){ return StatusCode(500, $"连接到 Oracle 数据库时出错: {ex.Message}"); }

        }
    }
}
