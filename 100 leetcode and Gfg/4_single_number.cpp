
#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;
int findSingle(vector<int>& nums) {
    unordered_map<int, int>countMap;
    for (int num : nums) {
            countMap[num]++;
        }
        for (auto& pair : countMap) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1; // or throw an exception if no single number is found
    }

int main()
{
    vector<int>binner{1,2,3,1,2,3,4,5,5};
    cout<<findSingle(binner);
    
}