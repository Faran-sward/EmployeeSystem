using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class WebDBtestController : ControllerBase
    {
        private readonly ILogger<WebDBtestController> _logger;

        public WebDBtestController(ILogger<WebDBtestController> logger)
        {
            _logger = logger;
        }

        [HttpGet("{EmployeeID}/{ContractID}/{ContractType}/{ContractState}/{EffectiveDate}/{InoperativeDate}/{DocumentLink}")]
        public void GetText([FromBody]  Contract contract)
        {
            
        }
        [HttpPut]
        public string? GetTextTest()
        {
            return "Hello World!";
        }
        [HttpGet("[action]")]
       
        public Contract  GetText2(string Employee_ID, string Contract_ID)
        {
            ContractManagement t = new ContractManagement();

            Contract V=t.SignContract(Employee_ID,Contract_ID);
            return V;
        }
    }
}