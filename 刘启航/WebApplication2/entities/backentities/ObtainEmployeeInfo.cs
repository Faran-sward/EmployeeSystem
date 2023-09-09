using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainEmployeeInfo
    {
        public int BackCode { get; set; }
        public List<GetEmployeeInfo>? requestResult { get; set; }
    }
}
