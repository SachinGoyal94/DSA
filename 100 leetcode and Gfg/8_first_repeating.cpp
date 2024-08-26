#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
vector<int> binner{1,1,2,2,3,3,6};
    map<int, int> freqMap;
    int j=1,i=0;
    for (int num:binner)
    {
        freqMap[num]++;
        
        if(freqMap[num]>1)
        {
            cout<<"first repeating element is  "<<num<<" at "<<i<<"   ";
            return 0;
        }
        i++;                
    }
}