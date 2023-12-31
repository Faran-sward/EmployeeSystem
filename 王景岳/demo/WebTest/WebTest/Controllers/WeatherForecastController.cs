using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace WebTest.Controllers
{
    //路由设置
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        /// <summary>
        /// 获取文本
        /// </summary>
        /// <returns></returns>
        [HttpGet]
        public ActionResult<string> Get()
        {
            return "Hello World!";
        }
        /// <summary>
        /// 两数相加
        /// </summary>
        /// <param name="num1">第一个数</param>
        /// <param name="num2">第二个数</param>
        /// <returns></returns>
        [HttpGet]
        public ActionResult<int> Sum(int num1, int num2)
        {
            return num1 + num2;
        }
        /// <summary>
        /// 两数相减
        /// </summary>
        /// <param name="param">参数</param>
        /// <returns></returns>
        [HttpPost]
        public ActionResult<int> Subtract(Param param)
        {
            int result = param.num1 - param.num2;
            return result;
        }
    }
    /// <summary>
    /// 参数
    /// </summary>
    public class Param
    {
        /// <summary>
        /// 第一个数
        /// </summary>
        public int num1 { get; set; }
        /// <summary>
        /// 第二个数
        /// </summary>
        public int num2 { get; set; }
    }

    //路由设置
    [Route("api/[controller]/[action]")]
    public class DeptController : ControllerBase
    {
        /// <summary>
        /// 获取某一楼上的所有部门信息
        /// </summary>
        /// <dept name="building">第一个数</dept>
        /// <returns></returns>
        [HttpGet]
        public IEnumerable<DeptInfo> Get(string building)
        {
            return Enumerable.Range(1, 19).Select(index => new DeptInfo
            {
                ID = index.ToString(),
                Name = "部门" + index.ToString(),
                Buliding = building,
                Layer = ((index+1) / 2).ToString() + "楼"
            })
            .ToArray();

        }
    }
    /// <summary>
    /// 参数
    /// </summary>
    public class Dept
    {
        /// <summary>
        /// 部门所在楼
        /// </summary>
        public string? building { get; set; }
    }

    public class DeptInfo
    {
        public string ID { get; set; }
        public string Name { get; set; }
        public string Buliding { get; set; }
        public string Layer { get; set; }
    }
}