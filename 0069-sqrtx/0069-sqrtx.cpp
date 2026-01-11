class Solution {
public:
    int mySqrt(int x)
{
    if (x == 0 || x == 1) return x;

    int e = x / 2;
    int s = 0 ;
    while (s <= e)
    {
        int m = s + (e - s) / 2;

        long long sq = (long long) m * m;
        if ( sq == x)
        {
            return m ;
        }
        else if (sq< x)
        {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return e;
}
};