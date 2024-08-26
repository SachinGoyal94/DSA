#include<iostream>
#include<algorithm>  //to use inbuilt libraries 
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int l=0,h=n-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(l<h)
    {
        swap(a[l++],a[h--]);  //don't use this bcs it has high time complexity of NlogN use simple for loop of TC O(N)
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}