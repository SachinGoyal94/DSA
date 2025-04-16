//must refer notes
#include<bits/stdc++.h>
using namespace std;
int evenorodd(int n)
{
    if(n & 1)
        return 1;
    return 0;
}
void getith(int n)
{
    //10=1010  total 4 bits baki 0 hai so chahe 1000 bits lelo 4 bits ko chor sab 0 aayenge
    for(int i=3;i>=0;i--)
    {
        int mask=1<<i;
        if(mask & n)
            cout<<1;
        else
            cout<<0;
    }
    cout<<endl;
}
void setith(int n)
{
    //if i want to set any ith bit to  0
    //n=9 1001
    for(int i=0;i<4;i++)
    {
        int mask=1<<i;
        int result=n | mask;
        cout<<result<<endl;
    }
}
void clearith(int n)
{
    cout<<"clearing"<<endl; 
    //if i want to clear any ith bit to 0
    //n=9 1001
    for(int i=0;i<4;i++)
    {
        int mask=1<<i;
        int result=n & ~(mask);
        cout<<result<<endl;
    }
}
void updatebit(int n)
{
    cout<<"updating"<<endl;
    //if i want to make any bit to 1 or 0 
    // n=9 1001
    int updateto=1;
    for(int i=0;i<4;i++)
    {
        //clear that ith bit
        int mask=1<<i;
        int result=n & ~mask;
        
        //now update
        int target=updateto<<i;  //to set ith bit=0 or 1
        result=result | target;
        cout<<result<<endl;
    }
}
void clearlastibits()
{
    cout<<"clearing last i bits"<<endl;
    int n=31; //1 1 1 1 1
    //let's clear last 3 bits from right
    int mask=(-1<<3);
    cout<<(n & mask)<<endl;
}
void countsetbits()
{
    int n=31; //setbits=no of ones =5
    int count=0;
    while(n!=0)
    {
        count++;
        n=n&(n-1);
    }
    cout<<"no of setbits "<<count<<endl;
}
void poweroftwo()
{
    int n=8,count=0;
    //just count no of set bits
    while(n!=0)
    {
        count++;
        n=n&(n-1);
    }
    if(count==1)
        cout<<"power of 2"<<endl;
    else
        cout<<"not power of 2"<<endl;

}
void exponential(int m ,int n)//m^n
{
    int ans=1;
    while(n>0)
    {
        if(n & 1)
            ans*=m;
        m*=m;
        n>>=1;
    }
    cout<<"exponentian of m ^n "<<ans<<endl;
}
void clearbitsinrange()
{
    int n=127,j=2,i=4;//clear 2 to 4 th bit
    int a=-1<<(i+1);
    int b=~(-1<<j);
    int mask=a|b;
    n=n&mask;
    cout<<"clearing bits in range "<<n<<endl;
}
int main()
{
    int n=10;

    //even or odd even 8= 1 0 0 0    7 = 1 1 1
    if(evenorodd(n))
        cout<<"odd"<<endl;
    else    
        cout<<"even"<<endl;
         
    getith(n);
    setith(9);
    clearith(9);
    updatebit(9);
    clearlastibits();
    countsetbits();
    poweroftwo();
    exponential(5,3);
    clearbitsinrange();
}