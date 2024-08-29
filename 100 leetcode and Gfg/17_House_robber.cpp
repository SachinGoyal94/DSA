//LC House robber 198 will be done in dp without TLE
#include<bits/stdc++.h>
using namespace std;

int robber(vector<int>nums,int index)
{
    if(index>=nums.size())
    {
        return 0;
    }
    int includer=nums[index]+robber(nums,index+2);
    int excluder=0+robber(nums,index+1);
    return max(includer,excluder);
}
int main()
{
    vector<int>nums{2,7,9,10,2};
    cout<<robber(nums,0);
}
