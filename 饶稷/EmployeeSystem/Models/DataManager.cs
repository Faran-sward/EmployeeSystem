using Microsoft.AspNetCore.Authorization.Infrastructure;
using System.Text;

namespace EmployeeSystem.Models.DataManager
{
    // 查询生成器
    public class SqlGenerator
    {
        // 对单个表的查询生成Sql语句
        // table_name为待查表的名字
        // primary_key_names为待查表的主码属性
        // primary_key_values为用于where子句中的主码对应的值
        // result_names为表中待查属性
        // 不检查primary_key_names、result_names的合法性，只是单纯生成字符串
        string Search(string table_name, string[] search_key_names, string[] search_key_values, string[] result_names)
        {
            StringBuilder sqlBuilder = new StringBuilder();

            sqlBuilder.Append("SELECT ");
            for (int i = 0; i < result_names.Length; i++)
            {
                sqlBuilder.Append(result_names[i]);
                if (i < result_names.Length - 1)
                {
                    sqlBuilder.Append(", ");
                }
            }

            sqlBuilder.Append(" FROM ");
            sqlBuilder.Append(table_name);
            sqlBuilder.Append(" WHERE ");

            for (int i = 0; i < search_key_names.Length; i++)
            {
                sqlBuilder.Append(search_key_names[i]);
                sqlBuilder.Append(" = : ");
                sqlBuilder.Append(search_key_values[i]);

                if (i < search_key_names.Length - 1)
                {
                    sqlBuilder.Append(" AND ");
                }
            }

            return sqlBuilder.ToString();
        }

        // 对单个表的插入生成Sql语句
        // table_name为待插入表的名字
        // attributes为待插入表的对应属性
        // values为待插入表的对应的值
        // 不检查attributes、table_name的合法性，只是单纯生成字符串
        // 由于只输入了一组值，所以Sql的插入结果只包含一个元组
        /*
        string Insert(string table_name, string[] attributes, string[] values)
        {

        }

        // 对单个表的更新生成Sql语句
        // table_name为待更新表的名字
        // attributes为待更新表的对应属性
        // values为待更新表的对应的值
        // primary_key_names为待更新表的主码属性
        // primary_key_values为用于where子句中的主码对应的值
        string Update(string table_name, string[] attributes, string[] values, string[] search_key_names, string[] search_key_values)
        {

        }

        string Delete(string table_name, string[] search_key_names, string[] search_key_values)
        {
            
        }
        */
    }
}
