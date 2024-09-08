//sort 2 arrays

#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums,vector<int>& arr)
{
    int a=nums.size();
    int b=arr.size();
    int length=a+b;
    int gap=(length/2)+(length%2);
    while(gap>0)
    {
        int start=0,end=gap;
        while(end<length)
        {
            if(end<a && nums[start]>nums[end])
                swap(nums[start],nums[end]);
            else if(end>=a && start<a && nums[start]>arr[end-a])
                swap(nums[start],arr[end-a]);
            else if(end>=a && start>=a && arr[start-a]>arr[end-a])
                swap(arr[start-a],arr[end-a]);
            ++start,++end;
        }
        gap= gap<= 1 ? 0 : (gap/2)+(gap%2);
    }
}
int main() {
    vector<int> nums={21,8,100};
    vector<int> arr={4,19,11};
    merge(nums,arr);
    for(auto it:nums)
        cout<<it<<"   ";
    cout<<endl;
    for(auto it:arr)
        cout<<it<<"   ";
}