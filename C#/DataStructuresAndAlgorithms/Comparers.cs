public class IntComparer : IComparer<int>
{
    public int Compare(int x, int y)
    {
        if (x < y)
            return -1;
        else if (x == y)
            return 0;
        else
            return 1;
    }
}

public class DoubleComparer : IComparer<double>
{
    public int Compare(double x, double y)
    {
        if (x < y)
            return -1;
        else if (x == y)
            return 0;
        else
            return 1;
    }
}