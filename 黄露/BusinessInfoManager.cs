using DB_project.Models.Connection;
using Oracle.ManagedDataAccess.Client;

namespace DB_project.Models.DataManager
{
    // ���� model �� Controller ��Ľ���
    // �������ݿ� ���� �����ݿ�������Ҫ����Ϣ�������model��
    public class BusinessInfoManager
    {
        // private DatabaseLink link = new DatabaseLink("localhost", "1521", "orcl", "TESTER", "123456");  // TODO
        private DatabaseLink link = new DatabaseLink("localhost", "1521", "orcl", "sys_developer", "1738477932");

        // ����JSON��Ϣ�������ݿ��ȡ��Ӧֵ��Ĭ�Ϸ�������Ԫ��
        public bool Get(string json, out List<BusinessInfo> ret)
        {
            ret = new List<BusinessInfo>();
            if (!string.IsNullOrEmpty(json))
            {
                BusinessInfo temp = new BusinessInfo();  // �½������ڴ洢 json �����Լ�ֵ
                temp.SetValuesThroughJson(json);  // �� json ת��Ϊ����(model)
                temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // �õ�������

                string[] result_names = { "*" };  // Ĭ�Ϸ�������Ԫ��
                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Search(temp.table_name, search_key_names, search_key_params, result_names);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // ����OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // ��Ӳ���
                Console.WriteLine(cmd.CommandText);
                cmd.ExecuteNonQuery();
                OracleDataReader reader = cmd.ExecuteReader();
                while (true)  // ѭ������
                {
                    BusinessInfo contract = new BusinessInfo();
                    // ʹ�� SetValuesThroughOrclReader ������ OracleDataReader �ж�ȡһ��ֵ�����õ� BusinessInfo ʵ����
                    if (contract.SetValuesThroughOrclReader(reader))
                    {
                        Console.WriteLine("read successfully! ");
                        ret.Add(contract);
                    }
                    else
                        break;
                }

                link.DisConnect();  // �ر����ݿ�����
                return true;
            }
            return false;
        }

        public bool Insert(string json)
        {
            if (!string.IsNullOrEmpty(json))
            {
                BusinessInfo temp = new BusinessInfo();  // �½������ڴ洢 json �����Լ�ֵ
                temp.SetValuesThroughJson(json);  // �� json ת��Ϊ����(model)
                temp.GetValuesAsArray(out string[] attributes, out string[] values);  // �õ�������Ķ�Ӧ���Ժ�ֵ

                string[] attributes_params = attributes.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Insert(temp.table_name, attributes, attributes_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // ����OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, attributes_params, values);  // ��Ӳ���
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// ִ�н��
                link.DisConnect();  // �ر����ݿ�����
                return true;
            }
            return false;
        }

        public bool Update(string set_json, string search_json)
        {
            if (!string.IsNullOrEmpty(set_json) && !string.IsNullOrEmpty(search_json))
            {
                BusinessInfo set_temp = new BusinessInfo(), search_temp = new BusinessInfo();  // �½������ڴ洢 json �����Լ�ֵ
                set_temp.SetValuesThroughJson(set_json);  // �� json ת��Ϊ����(model)
                set_temp.GetValuesAsArray(out string[] attributes, out string[] values);  // �õ�������Ķ�Ӧ���Ժ�ֵ

                set_temp.SetValuesThroughJson(search_json);  // �� json ת��Ϊ����(model)
                set_temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // �õ�������Ķ�Ӧ���Ժ�ֵ

                string[] attribute_params = attributes.Select(item => "param" + item).ToArray();
                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();

                string sql = SqlGenerator.Update(set_temp.table_name, attributes,
                    attribute_params, search_key_names, search_key_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // ����OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, attribute_params, values);  // ��Ӳ���
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // ��Ӳ���
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// ִ�н��
                link.DisConnect();  // �ر����ݿ�����
                return true;
            }
            return false;
        }

        public bool Delete(string json)
        {
            if (!string.IsNullOrEmpty(json))
            {
                BusinessInfo temp = new BusinessInfo();  // �½������ڴ洢 json �����Լ�ֵ
                temp.SetValuesThroughJson(json);  // �� json ת��Ϊ����(model)
                temp.GetValuesAsArray(out string[] search_key_names, out string[] search_key_values);  // �õ�������Ķ�Ӧ���Ժ�ֵ

                string[] search_key_params = search_key_names.Select(item => "param" + item).ToArray();
                string sql = SqlGenerator.Delete(temp.table_name, search_key_names, search_key_params);

                link.Connect();
                OracleCommand cmd = new OracleCommand(sql, link.connection);  // ����OracleCommand
                cmd = SqlGenerator.SqlAddParam(cmd, search_key_params, search_key_values);  // ��Ӳ���
                Console.WriteLine(cmd.CommandText);
                if (cmd.ExecuteNonQuery() == 0) return false;// ִ�н��
                link.DisConnect();  // �ر����ݿ�����
                return true;
            }
            return false;
        }

    }
}
