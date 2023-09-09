namespace WebApplication2.entities.backentities.listentities
{
    public class GetPersonalSalary
    {
        public String year { get; set; }
        public String month { get; set; }
        public float Bonus { get; set; }


        public float BasicSalary { get; set; }
        public float Commission { get; set; }
        public float OverallSalary { get; set; }
    }
}
