//undirected graphs and to find bridges
//notebook
#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<pair<int,int>>>mp;
    public:
    void insert(int u ,int v ,int w,int direction)
    {
        if(direction ==0)
        {
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        else
        {
            mp[u].push_back({v,w});
        }
    }
    
    void fullprint(int n )
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"{";
            vector<pair<int,int>>temp=mp[i];
            for(int j=0;j<temp.size();j++)
            {
                cout<<" ( "<<temp[j].first<<" , "<<temp[j].second<<")";
            }
            cout<<"}"<<endl;
        }
    }
    void tajen(int timer,int n,int source,int parent,unordered_map<int,bool>&visited,vector<int>&dest,vector<int>&low,vector<pair<int,int>>&ans)
    {
        timer++;
        visited[source]=1;
        low[source]=timer;
        dest[source]=timer;
        for(auto & k:mp[source])
        {
            if(k.first==parent)
            {
                continue;
            }
            else
            {
                if(!visited[k.first])
                {
                    tajen(timer,n,k.first,source,visited,dest,low,ans);
                    low[source]=min(low[source],low[k.first]);
                    if(low[k.first]>dest[source])
                    {
                        ans.push_back({source,k.first});
                    }
                }
                else
                {
                    low[source]=min(low[source],low[k.first]);
                }
            }
        }

    }
};
int main()
{
    int n=5;
    vector<int>dest(n,INT_MAX);
    vector<int>low(n,INT_MAX);
    unordered_map<int,bool>visited;
    int timer=0,    source=0,   parent=-1;
    graph g;
    g.insert(0,1,4,0);
    g.insert(1,2,2,0);
    g.insert(2,0,3,0);
    g.insert(0,3,2,0);
    g.insert(3,4,1,0);
    vector<pair<int,int>>ans;
    g.tajen(timer,5,source,parent,visited,dest,low,ans);
    for(auto &k:ans)
    {
        cout<<"   "<<k.first<<"   "<<k.second<<endl;
    }
}
