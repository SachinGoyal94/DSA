#include<bits/stdc++.h>
using namespace std;
int fastexponetiation(int x,int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1)
        {
            ans=ans*x;
        }
    x=x*x;
    n>>=1;
    }
    return ans;
}
int main()
{
    int a=2,b=2,c=fastexponetiation(a,b);
    cout<<c;
}