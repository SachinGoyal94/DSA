
#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int binarysearch(vector<int>&arr,int s,int e,int x)
{
    int mid=s+((e-s)/2);
    int ans=0;
    while(s<=e)
    {
        int mid=s+((e-s)/2);
        if(arr[mid]>=x)
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
int expsearch(vector<int>&nums,int i,int j,int x)
{
    if(nums[0]==x)
    {
        return 0;
    }
    while(j<nums.size() && nums[j]<x)
    {
        i=j;
        j=j*2;  //finding sub array containg target as given array is large
    }
    int k=nums.size()-1;
    return binarysearch(nums,i,min(j,k),x);  //suppose target at 8 size is 10(k=9) then8*2=16
}                                            //so end index=min(9,16)
int main()
{
    vector<int>nums{1,2,10,15,20,25,31,45,50,51,52,53, 56,70};
    int target=56;
    int i=0,j=1;
    cout<<"exponential search"<<endl;
    cout<<expsearch(nums,i,j,target);
}

//T.C. of exponential search is log(2^((logm)-1))
//application->when given range is too much large then used to make more efficient T.C. 
//then Binary Search and when target is at initital positions then it's more faster 
//than BS
