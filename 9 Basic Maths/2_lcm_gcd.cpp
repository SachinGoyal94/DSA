#include<bits/stdc++.h>
using namespace std;
int gcd_(int a,int b)
{
    if(a==0) return a;
    if(b==0) return b;
    while(a>0 && b>0)
    {
        if(a>b) 
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
    }
    if(a==0)
    {
        return b;
    }
    return  a;
}
int lcm(int a,int b)
{
    int c=gcd_(a,b);
    return (a*b)/c;
}
int main()
{
    int a=72,b=24,c=gcd_(a,b),d=lcm(a,b);
    cout<<c<<"   "<<d;
}