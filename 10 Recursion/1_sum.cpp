#include<bits/stdc++.h>
using namespace std;
int summer(int n)
{
    if(n==1)
    {
        return 1;
    }
    int sum=summer(n-1)+n;
    return sum;
}
int main()
{
    int n=5;
    cout<<summer(n);
}