#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int xorr(vector<int>&nums)
    {
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            ans^=nums[i];
        }
        for(int i=0;i<=nums.size();i++)
        {
            ans^=i;
        }
        return ans;
    }
int missingNumber(vector<int>& nums) 
    {
        return xorr(nums);
    }

int main()
{
    vector<int>binner{0,1,3};
    cout<<missingNumber(binner);   
}

/*
working check xor table and convert each no into binary form then apply xor 
ex xor of 3 and 2 is
1 1
1 0
for 1^1=>0 1^0=>1
for loop 1
xor of 0 0=>0 as conversion of zero in binary
0^1=1
1^3=2
now xor all the index value including one more like size is 3 so
indexes are 0 1 2 but we will check up to 3 so that in case 0 1 2 is input then 
output must be 3 
so for loop 2
2^0=2
2^1=3
3^2=1
1^3=2
*/