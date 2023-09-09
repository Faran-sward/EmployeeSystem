using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainPersonalSalary
    {
        public int BackCode { get; set; }
        public List<GetPersonalSalary>? requestResult { get; set; }
    }
}
