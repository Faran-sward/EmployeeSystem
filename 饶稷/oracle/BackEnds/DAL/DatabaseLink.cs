using System.Text.Json;
using Oracle.ManagedDataAccess.Client;
namespace BackEnds.DAL
{
    class LINK
    {
        public class CONFIGURATION
        {
            public string Hostname { get; set; } = string.Empty;
            public string Port { get; set; } = string.Empty;
            public string ServiceName { get; set; } = string.Empty;
            public string UserId { get; set; } = string.Empty;
            public string Password { get; set; } = string.Empty;
        }

        public class CONFIG_READER
        {
            const string configPath = "config.json";

            public CONFIGURATION? ReadConfig()
            {
                if (!File.Exists(configPath))
                {
                    throw new FileNotFoundException("Config file not found.");
                }

                string json = File.ReadAllText(configPath);

                try
                {
                    CONFIGURATION? config = JsonSerializer.Deserialize<CONFIGURATION>(json);
                    return config;
                }
                catch (JsonException ex)
                {
                    throw new Exception("Error deserializing config file.", ex);
                }
            }
        }

        public class DBLINK : IDisposable
        {
            private OracleConnection connection;
            private string connectionString = "";

            bool GetConnectionString(string hostname, string port, string service_name, string user_id, string password)
            {
                connectionString = $"Data Source=" +
                                    $"(DESCRIPTION=" +
                                        $"(ADDRESS=(PROTOCOL=TCP)(HOST={hostname})(PORT={port}))" +
                                        $"(CONNECT_DATA=" +
                                            $"(SERVICE_NAME={service_name})));" +
                                   $"User Id={user_id};" +
                                   $"Password={password};";
                return true;
            }

            bool GetConnectionString()
            {
                CONFIG_READER config_reader = new CONFIG_READER();
                CONFIGURATION? config = config_reader.ReadConfig();
                if (config == null) { return false; }
                return GetConnectionString(config.Hostname, config.Port, config.ServiceName, config.UserId, config.Password);
            }

            public DBLINK()
            {
                if(!GetConnectionString()) Console.WriteLine("connection failed ! ");
                connection = new OracleConnection(connectionString);
                Connect();
            }

            public void Connect()
            {
                if (connection.State != System.Data.ConnectionState.Open)
                {
                    connection.Open();
                    Console.WriteLine("connect successfully !");
                }
            }

            public void DisConnect()
            {
                if (connection.State != System.Data.ConnectionState.Closed)
                {
                    connection.Close();
                    Console.WriteLine("connection closed ! ");
                }
            }

            public void Dispose()
            {
                DisConnect();
            }
        }

        static void Main(string[] args)
        {
            DBLINK es = new DBLINK();
            Console.ReadKey();
        }
    }
}
