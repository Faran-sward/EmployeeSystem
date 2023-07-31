namespace EmployeeSystem.Models.Tables
{
    public static class AttributeNames
    {
        public static string[] EmployeeInfoArrributeNames =
        {
            "EmployeeID",
            "CurrentPostID",
            "CurrentCity",
            "StartWorkingDate",
            "BasicSalary",
            "ImageUrl",
            "Password"
        };

        public static string[] EmployeeInfoArrributeTypes =
        {
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "float",
            "varchar",
            "varchar"
        };

        public static string[] ContractInfoAttributeNames =
        {
            "EmployeeID",
            "ContractID",
            "ContractType",
            "ContractState",
            "EffectiveDate",
            "InoperativeDate",
            "DocumentHLink"
        };

        public static string[] ContractInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "Date",
            "varchar"
        };

        public static string[] BusinessInfoAttributeNames =
        {
            "EmployeeID",
            "BusinessID",
            "BusinessEnterpriseName",
            "BusinessDepartmentName",
            "BusinessPostName",
            "StartTime",
            "EndTime"
        };

        public static string[] BusinessInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "Date"
        };

        public static string[] EmpSalaryAttributeNames =
        {
            "EmployeeID",
            "Date",
            "Bonus",
            "Commission",
            "OverallSalary"
        };

        public static string[] EmpSalaryAttributeTypes =
{
            "varchar",
            "Date",
            "float",
            "float",
            "float"
        };

        public static string[] PostInfoAttributeNames =
        {
            "PostID",
            "PostTitle",
            "PostType",
            "PostLevel"
        };

        public static string[] PostInfoAttributeTypes =
        {
            "varchar",
            "varchar",
            "varchar",
            "varchar"
        };

        public static string[] DeptPostAttributeNames =
        {
            "DepartmentID",
            "PostID",
            "CurrentScale",
            "EmulatedScale"
        };

        public static string[] DeptPostAttributeTypes =
{
            "varchar",
            "varchar",
            "int",
            "int"
        };

        public static string[] DepartmentInfoAttributeNames =
        {
            "DepartmentID",
            "DepartmentTitle",
            "Building",
            "Layer"
        };

        public static string[] DepartmentInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "int"
        };

        public static string[] WorkScheduleAttributeNames =
        {
            "PostID",
            "ScheduleType",
            "ScheduleCode"
        };

        public static string[] WorkScheduleAttributeTypes =
        {
            "varchar",
            "varchar",
            "varchar"
        };

        public static string[] ExperienceInfoAttributeNames =
        {
            "ID",
            "ExperienceNo",
            "EnterpriseName",
            "EnterpriseCity",
            "DepartmentTitle",
            "JobTitle",
            "StartTime",
            "EndTime"
        };

        public static string[] ExperienceInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "Date"
        };

        public static string[] EducationInfoAttributeNames =
        {
            "ID",
            "EducationNo",
            "EducationType",
            "InstitutionName",
            "Degree",
            "JobTitle",
            "StartTime",
            "EndTime"
        };

        public static string[] EducationInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "Date"
        };

        public static string[] CommuteAttributeNames =
        {
            "EmployeeID",
            "StartTime",
            "EndTime",
            "CommuteType"
        };

        public static string[] CommuteAttributeTypes =
        {
            "varchar",
            "Date",
            "Date",
            "varchar"
        };

        public static string[] FundamentalInfoAttributeNames =
        {
            "ID",
            "EmployeeID",
            "Name",
            "Sex",
            "Birth",
            "PhoneNumber",
            "HomeAddress",
            "ImageURL",
            "WorkState"
        };

        public static string[] FundamentalInfoAttributeTypes =
{
            "varchar",
            "varchar",
            "varchar",
            "varchar",
            "Date",
            "varchar",
            "varchar",
            "varchar",
            "varchar"
        };
    }
}
