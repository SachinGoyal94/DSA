#include<iostream>
#include<algorithm>
using namespace std;
void add(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
}
int unique(int A[],int size)
{
    add(A,size);
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^A[i];
    }
    cout<<ans;
    return ans;
}
int main()
{
    int a[10];//ex a[10]={1,2,2,3,3};
    int size;
    cin>>size;
    unique(a,size);
}