using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainOrgInfo
    {
        public int BackCode { get; set; }
        public List<GetOrgInfo>? requestResult { get; set; }

    }
}
