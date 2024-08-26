#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int checkbloom(vector<int>& bloomDay, int m, int k,int day)
{
    int count=0;
    for(int i=0;i<bloomDay.size();i++)
    {
        if(bloomDay[i]<=day)
        {
            count ++;
        }
        if(count==k)
        {
            m--;
            count=0;
            if(m==0)
            {
                break;
            }
        }
        if(bloomDay[i]>day)
        {
            count=0;
        }
    }
    return m==0;
}
int minDays(vector<int>& bloomDay, int m, int k) 
{
    long long int total_flowers = m * k;
    if(total_flowers>bloomDay.size())
    {
        return -1;
    }
    int count = 0;
    int ans=-1;
    int s = *min_element(bloomDay.begin(), bloomDay.end());
    int e = *max_element(bloomDay.begin(), bloomDay.end());
    while (s<=e)
    {
        long long int mid=(s+e)/2;
        long long int day=mid;
        if(checkbloom(bloomDay,m,k,day))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>bloom{7,7,7,7,12,7,7};
    int m=2,k=3;
    cout<<minDays(bloom,m,k);
}