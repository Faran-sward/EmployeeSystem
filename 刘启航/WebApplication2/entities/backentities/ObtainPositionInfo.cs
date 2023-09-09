using WebApplication2.entities.backentities.listentities;

namespace WebApplication2.entities.backentities
{
    public class ObtainPositionInfo
    {
        public int BackCode { get; set; }
        public List<GetPostionInfo>? requestResult { get; set; }
    }
}
