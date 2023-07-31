using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WebApplication2.entities;
using WebApplication2.servers;

namespace WebApplication2.Controllers
{
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        [HttpGet]
        public string Test()
        {
            return "OK";
        }

        [HttpPost]
        public string LoginAndSign(LoginInfo _logininfo)
        {
            LoginSignServer loginSignServer = new LoginSignServer();
            return loginSignServer.SignAndLogin(_logininfo);
        }
    }
}
