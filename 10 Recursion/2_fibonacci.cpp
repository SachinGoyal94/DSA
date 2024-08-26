//for explanation check one note
#include<bits/stdc++.h>
using namespace std;
int recursive(int n)
{
    if(n==1 || n==0)
    {
        return n;
    }
    int recursum=recursive(n-1)+recursive(n-2);
    return recursum;
}
int main()
{
    int n=4;
    cout<<recursive(n);
}