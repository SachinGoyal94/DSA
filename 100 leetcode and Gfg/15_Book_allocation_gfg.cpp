#include <iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
bool possible(int n,int sol,vector<int>& arr,int m)
{
    int pagesum=0;
    int c=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>sol)
        {
            return false;
        }
        if(pagesum+arr[i]>sol)
        {
            c++;
            pagesum=arr[i];
            if(c>m)
            {
                return false;
            }
        }
        else
        {
            pagesum+=arr[i];
        }
    }
    return true;
}
int main()
{
    vector<int>arr{12,34,67,90};
    int books=arr.size();
    int students=2;
    int pages=accumulate(arr.begin(),arr.end(),0);
    int s=0,e=pages;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        cout<<mid<<endl;
        if(possible(books,mid,arr,students))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<"min pages allocated is "<<ans<<endl;
    return 0;

}