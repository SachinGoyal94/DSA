#include<bits/stdc++.h>
using namespace std;

int bs(int l ,int h,int target,vector<int>&nums)
{
    if(l>h)
    {
        return -1;
    }
    int mid=(l+h)/2;
    if(nums[mid]==target)
    {
        return mid;
    }
    else
    {
        if(nums[mid]>target)
        {
            return bs(l,mid-1,target,nums);
        }
        else
        {
            return bs(mid+1,h,target,nums);
        }
    }
    return -1;
}
void digitsi(int k)
{
    if(k==0)
    {
        return;
    }
    int m=k%10;//113   3-113   1-11   1   
    k=k/10;/// 113     11      1
    if(k!=0)
    {
        digitsi(k);
    }
    cout<<m<<"   ";
}
int checksorted(vector<int>nums,int pos)
{
    if(pos==4)
    {
        return 1;
    }
    if(nums[pos]<nums[pos+1])
    {
        return checksorted(nums,pos+1);
    }
    else
    {
        return -1;
    }
    return 1;
}
int main()
{
    vector<int>nums{10,20,30,40,50,60,70};
    int l=0,h=nums.size()-1;
    //cout<<bs(l,h,50,nums);
    //digitsi(113);
    cout<<checksorted(nums,0);
}
