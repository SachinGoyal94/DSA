//Gap method ->in place merge sort
//No extra space as in merge sort

#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums,int i,int mid,int j)
{
    int length=j-i+1;
    int gap=(length/2)+(length%2);
    while(gap>0)
    {
        int start=i,end=gap+i;
        while(end<=j)
        {
            if(nums[start]>nums[end])
                swap(nums[start],nums[end]);
            ++start,++end;
        }
        gap= gap<= 1 ? 0 : (gap/2)+(gap%2);
    }
}
void solve(vector<int>& nums,int i,int j)
{
    if(i>=j)
        return;
    int mid=(i+j)/2;
    solve(nums,i,mid);
    solve(nums,mid+1,j);
    merge(nums,i,mid,j);
}
int main() {
    vector<int> nums={5,2,8,1,9};
    solve(nums,0,nums.size()-1);
    for(auto it:nums)
        cout<<it<<"   ";
}
