//creating graphs 
#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<int>>mp;
    public:
    void insert(int u ,int v ,int direction)
    {
        if(direction ==0)
        {
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        else
        {
            mp[u].push_back(v);
        }
    }
    void printgraph()  //this will not the print the nodes which are not pointing to any another node  like 3 here
    {
        for(auto & i:mp)
        {
            cout<<i.first<<"{";
            for(auto j:i.second)
            {
                cout<<" "<<j;
            }
            cout<<"}"<<endl;
        }
    }
    void fullprint(int n )
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"{";
            vector<int>temp=mp[i];
            for(int j=0;j<temp.size();j++)
            {
                cout<<" "<<temp[j];
            }
            cout<<"}"<<endl;
        }
    }
};
int main()
{
    graph g;
    //0 is the source node
    //(u,v,direction)  u,v connecting nodes  direction 1=u->v 0 u<=>v
    g.insert(0,1,1);
    g.insert(0,2,1);
    g.insert(0,3,1);
    g.insert(1,2,1);
    cout<<"printing graph "<<endl;
    g.printgraph();
    cout<<"full graph "<<endl;
    g.fullprint(4);
}
