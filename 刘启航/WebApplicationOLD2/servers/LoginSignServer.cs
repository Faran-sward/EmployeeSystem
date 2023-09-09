using WebApplication2.entities;
using WebApplication2.servers.mapper;

namespace WebApplication2.servers
{
    public class LoginSignServer
    {
        public string SignAndLogin(LoginInfo _logininfo)
        {
            MapperOfLoginSign FUNC= new MapperOfLoginSign();
            if (_logininfo.account.Length > 20) { return "ACCOUNTLENGTHERR"; }
            if(_logininfo.keyword.Length > 20) { return "KEYWORDLENGTHERR"; }
            if (_logininfo.status == "Sign")
            {
                //此时对应的是注册

                /*先判断数据库是否有账号与其重复的，如果有，则返回失败*/
                string resultofcheckrepeat = FUNC.CheckRepeat(_logininfo.account);
                if (resultofcheckrepeat != "OK")
                {
                    if (resultofcheckrepeat == "NO")
                        return "REPEATERR";
                    else
                        return resultofcheckrepeat;
                }


                /*如果没有重复的，我们就直接进行插入*/
                return  FUNC.Sign(_logininfo.account,_logininfo.keyword);
            }
            else if (_logininfo.status == "Login")
            {
                /*先判断数据库是否有账号与密码匹配的，如果没有，则返回失败*/

                /*有，返回成功*/

                string resultoflogin=FUNC.Login(_logininfo.account, _logininfo.keyword);
                if (resultoflogin == "NO")
                    return "ACCOUNTLACKERR";
                else return resultoflogin;

            }
            else
                return "STATUSERR";

        }
    }
}
