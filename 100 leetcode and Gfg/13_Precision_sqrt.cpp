#include <iostream>
#include <algorithm>
using namespace std;



double BSPrecision(int n)
{
    double start = 0;
    double end = n;
    double ans = 0;
    while ((end - start) > 0.000000001)
    {
        double mid = (start + end) / 2;
        double sqr = mid * mid;
        if (sqr <= n)
        {
            ans = mid;
            start = mid ;
        }
        else
            end = mid ;
    }
    return ans;
}

int main()
{
    int n = 63;
    double ans ;
    // cout hota hai, it only print 5 precision.

    // zada kes kre?
    // TC: O(logn) + O(Precision).
    ans = BSPrecision(n);
    printf("Precision Sqrt: %.9f\n", ans);
    return 0;
}