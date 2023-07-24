namespace DataType
{
    [System.Serializable]
    public enum WORKSTATE
    {
        WORKING;
        RETIREED;
        LEAVE;  // TODO
    }

    public enum COMMUTETYPE
    {
        LEAVING;
        OVERWORK;  // TODO
    }

    public enum DEPARTMENT
    {
        // TODO
    }

    public enum JOB
    {
        // TODO
    }

    public enum SCHEDULE
    {
        // TODO
    }

    public enum CONTRACTTYPE
    {
        // TODO
    }

    public class PERSON
    {
        public string id {get; set}
        public string eid {get; set;}
        public string name {get; set;}
        public bool sex {get; set;}
        public string phonenum {get; set;}
        public ADDRESS address;
        public IMAGE image;
        public WORKSTATE workstate {get; set;};
    }

    public class ADDRESS
    {
        public string country {get; set;}
        public string province {get; set;}
        public string state {get; set;}
        public string detail {get; set;}
    }

    public class IMAGE
    {
        public uint height {get; set;}
        public uint weight {get; set;}
        public string url {get; set;}
    }

    public class TIME
    {
        // TODO
    }

    public class SALARYLIST
    {
        public string eid {get; set;}
        public int* salarylist; // TODO
        public TIME start;
        public TIME end;
    }

    public class CONTRACT
    {
        public CONTRACTTYPE type {get; set;}
    }

}
