//kadanes algo to find max sum of subarray

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
int Kadanesalgo(vector<int>&arr)
{
    int ans=INT_MIN,sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        ans=max(sum,ans);
        if(sum<0)
        {
            sum=0;
        }
    }
    return ans;
}

int max_SUBarray(vector<int>&arr)
{
    return Kadanesalgo(arr);
}

int main()
{
    vector<int>sub{-4,1,5,6,-7,5,4,-3};
    cout<<max_SUBarray(sub);
}