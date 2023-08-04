using Oracle.ManagedDataAccess.Client;
using System.Text;

namespace EmployeeSystemBackends.Models.DataManager
{
    // 查询生成器
    public static class SqlGenerator
    {
        // 对单个表的查询生成Sql语句
        // table_name为待查表的名字
        // search_key_names为用于where子句中的属性
        // search_key_values为用于where子句中的属性对应的值
        // result_names为表中待查属性
        // 不检查search_key_names、result_names的合法性，只是单纯生成字符串
        public static string Search(string table_name, string[] search_key_names, string[] search_key_params, string[] result_names)
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
                sqlBuilder.Append(" = :");
                sqlBuilder.Append(search_key_params[i]);

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
        public static string Insert(string table_name, string[] attributes, string[] attribute_params)
        {
            StringBuilder sqlBuilder = new StringBuilder();

            sqlBuilder.Append("INSERT INTO ");
            sqlBuilder.Append(table_name);
            sqlBuilder.Append(" (");

            for (int i = 0; i < attributes.Length; i++)
            {
                sqlBuilder.Append(attributes[i]);

                if (i < attributes.Length - 1)
                {
                    sqlBuilder.Append(", ");
                }
            }

            sqlBuilder.Append(") VALUES (");

            for (int i = 0; i < attribute_params.Length; i++)
            {
                sqlBuilder.Append(":");
                sqlBuilder.Append(attribute_params[i]);

                if (i < attribute_params.Length - 1)
                {
                    sqlBuilder.Append(", ");
                }
            }

            sqlBuilder.Append(")");

            return sqlBuilder.ToString();
        }

        // 对单个表的更新生成Sql语句
        // table_name为待更新表的名字
        // attributes为待更新表的对应属性
        // values为待更新表的对应的值
        // search_key_names为用于where子句中的属性
        // search_key_values为用于where子句中的属性对应的值
        public static string Update(string table_name, string[] attributes, string[] attribute_params, string[] search_key_names, string[] search_key_values)
        {
            StringBuilder sqlBuilder = new StringBuilder();

            sqlBuilder.Append("UPDATE ");
            sqlBuilder.Append(table_name);
            sqlBuilder.Append(" SET ");

            for (int i = 0; i < attributes.Length; i++)
            {
                sqlBuilder.Append(attributes[i]);
                sqlBuilder.Append(" = :");
                sqlBuilder.Append(attribute_params[i]);

                if (i < attributes.Length - 1)
                {
                    sqlBuilder.Append(", ");
                }
            }

            sqlBuilder.Append(" WHERE ");

            for (int i = 0; i < search_key_names.Length; i++)
            {
                sqlBuilder.Append(search_key_names[i]);
                sqlBuilder.Append(" = :");
                sqlBuilder.Append(search_key_values[i]);

                if (i < search_key_names.Length - 1)
                {
                    sqlBuilder.Append(" AND ");
                }
            }

            return sqlBuilder.ToString();
        }

        // 对单个表的元组删除生成Sql语句
        // table_name为待更新表的名字
        // search_key_names为用于where子句中的属性
        // search_key_values为用于where子句中的属性对应的值
        public static string Delete(string table_name, string[] search_key_names, string[] search_key_values)
        {
            StringBuilder sqlBuilder = new StringBuilder();

            sqlBuilder.Append("DELETE FROM ");
            sqlBuilder.Append(table_name);
            sqlBuilder.Append(" WHERE ");

            for (int i = 0; i < search_key_names.Length; i++)
            {
                sqlBuilder.Append(search_key_names[i]);
                sqlBuilder.Append(" = :");
                sqlBuilder.Append(search_key_values[i]);

                if (i < search_key_names.Length - 1)
                {
                    sqlBuilder.Append(" AND ");
                }
            }

            return sqlBuilder.ToString();
        }

        // 用于在sql语句中 把以:开头的变量 替换为实际的值
        // 如果 names 与 values 的长度不等则抛出异常
        public static OracleCommand SqlAddParam(OracleCommand cmd, string[] names, string[] values)
        {
            if (names.Length != values.Length)
            {
                throw new ArgumentException("参数 names 和 values 的长度不相等。");
            }

            // 遍历 names 和 values 数组，将变量名以 ":" 开头的部分替换为参数，并添加到 OracleCommand 对象中
            for (int i = 0; i < names.Length; i++)
            {
                string param_name = ":" + names[i]; // 构造参数名，例如 ":param1"
                string param_value = values[i]; // 获取对应的值

                if (float.TryParse(param_value, out float float_value))
                {
                    cmd.Parameters.Add(new OracleParameter(param_name, float_value));
                }
                else if (int.TryParse(param_value, out int int_value))
                {
                    cmd.Parameters.Add(new OracleParameter(param_name, int_value));
                }
                else
                {
                    cmd.Parameters.Add(new OracleParameter(param_name, param_value));
                }
            }

            return cmd;
        }
        
    }
}
