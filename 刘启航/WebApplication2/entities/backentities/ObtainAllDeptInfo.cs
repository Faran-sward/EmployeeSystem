using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainAllDeptInfo
    {
        public int BackCode { set; get; }
        public int nums { set; get; }
        public List<GetDeptInfo>infos { set; get; }

    }
}
