//try to use this with some other containers also 
#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    set<pair<int,int>>ans;
    pair<int,int>res;
    int j=0,i=10,k=100;
    while(j!=3)
    {
        res.first=i++;
        res.second=k++;
        ans.insert(res);
        j++;
    }
    auto it=ans.begin();
    while(it!=ans.end())
    {
        cout<<it->first<<"   "<<it->second<<"   "<<endl;
        it++;
    }
}