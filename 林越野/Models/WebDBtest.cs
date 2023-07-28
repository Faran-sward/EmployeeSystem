namespace WebApplication1.Models
{
    public class WebDBtest
    {
        public int ID { get; set; }

        public string? name { get; set; }

        public string? text { get; set; }
    }

    public class Contract
    {
        public string? EmployeeID { get; set; }
        public string? ContractId { get; set; }
        public string? ContractType { get; set; }
        public string? ContractState { get; set; }
        public string? EffectiveDate { get; set; }
        public string? InoperativeDate { get; set; }
        public string? DocumentLink { get; set; }
    }
}