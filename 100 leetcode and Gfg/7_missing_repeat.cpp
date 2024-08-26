#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;
int main() {
    vector<int> binner{1,1,2,2,3,3,6};
    map<int, int> freqMap;
    int j=1;
    for (int num:binner)
    {
        freqMap[num]++;                
    }
    map<int,int>::iterator it=freqMap.begin();
    while(it!=freqMap.end())
    {
        pair<int,int> p=*it;
        cout<<p.first<<"   "<<p.second<<endl;
        it++;
    }
    map<int,int>::iterator mt=freqMap.begin();
    cout<<"finding missing value"<<endl;
    while(mt!=freqMap.end()) 
    {
        if( mt->first > j)
        {
            cout<<j<<endl;
        }
        else if(mt->first == j)
        {
            mt++;
        }
        j++;
    
    }

    return 0;
}
