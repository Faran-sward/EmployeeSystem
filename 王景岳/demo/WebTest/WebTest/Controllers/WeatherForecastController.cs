using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace WebTest.Controllers
{
    //·������
    [Route("api/[controller]/[action]")]
    [ApiController]
    public class ValuesController : ControllerBase
    {
        /// <summary>
        /// ��ȡ�ı�
        /// </summary>
        /// <returns></returns>
        [HttpGet]
        public ActionResult<string> Get()
        {
            return "Hello World!";
        }
        /// <summary>
        /// �������
        /// </summary>
        /// <param name="num1">��һ����</param>
        /// <param name="num2">�ڶ�����</param>
        /// <returns></returns>
        [HttpGet]
        public ActionResult<int> Sum(int num1, int num2)
        {
            return num1 + num2;
        }
        /// <summary>
        /// �������
        /// </summary>
        /// <param name="param">����</param>
        /// <returns></returns>
        [HttpPost]
        public ActionResult<int> Subtract(Param param)
        {
            int result = param.num1 - param.num2;
            return result;
        }
    }
    /// <summary>
    /// ����
    /// </summary>
    public class Param
    {
        /// <summary>
        /// ��һ����
        /// </summary>
        public int num1 { get; set; }
        /// <summary>
        /// �ڶ�����
        /// </summary>
        public int num2 { get; set; }
    }

    //·������
    [Route("api/[controller]/[action]")]
    public class DeptController : ControllerBase
    {
        /// <summary>
        /// ��ȡĳһ¥�ϵ����в�����Ϣ
        /// </summary>
        /// <dept name="building">��һ����</dept>
        /// <returns></returns>
        [HttpGet]
        public IEnumerable<DeptInfo> Get(string building)
        {
            return Enumerable.Range(1, 19).Select(index => new DeptInfo
            {
                ID = index.ToString(),
                Name = "����" + index.ToString(),
                Buliding = building,
                Layer = ((index+1) / 2).ToString() + "¥"
            })
            .ToArray();

        }
    }
    /// <summary>
    /// ����
    /// </summary>
    public class Dept
    {
        /// <summary>
        /// ��������¥
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