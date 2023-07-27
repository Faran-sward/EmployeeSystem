// 数据表类型定义
namespace EmployeeSystem.Models.Tables
{
    // 员工基本信息
    public class BasicInfo
    {
        public string? ID { get; set; }
        public string? Name { get; set; }
        public string? StartWorkingDate { get; set; }
        public string? BasicSalary { get; set; }
        public string? Sex { get; set; }
        public string? Birth { get; set; }
        public string? PhoneNumber { get; set; }
        public string? HomeAddress { get; set; }
        public string? ImageURL { get; set; }
        public string? WorkState { get; set; }
    }
    // 员工工作经历
    public class DeployInfo
    {
        public string? BusinessID { get; set; }
        public string? BusinessEnterpriseName { get; set; }
        public string? BusinessDepartmentName { get; set; }
        public string? BusinessPostName { get; set; }
        public string? StartTime { get; set; }
        public string? EndTime { get; set; }
    }
}
