//setbit=> 1 not 0
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int setbitcount=0;
    while(n!=0)
    {
        int lastbit=(n&1);
        if(lastbit==1)
        {
            setbitcount++;
        }
        n=n>>1;
    }
    cout<<setbitcount;
}