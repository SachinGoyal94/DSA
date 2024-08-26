#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
    vector<int>nums{3,1,2,3,4};
    while(nums[0]!=nums[nums[0]])
    {
        swap(nums[0],nums[nums[0]]);
    }
    cout<<nums[0];
}