using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainSalaryTableInfo
    {
        public int BackCode { get; set; }
        public List<GetAllSalaryInOneMonth>? requestResult { get; set; }
    }
}
