//use topo sort to find shortest distance in directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
class graph
{
    public:
    unordered_map<int,vector<pair<int,int>>>mp;
    void insert(int i,int j,int weight,int direction)
    {
        if(direction==1)
        {
            mp[i].push_back({j,weight});
        }
        else
        {
            mp[j].push_back({i,weight});
            mp[i].push_back({j,weight});
        }
    }
    void toposort(int i,unordered_map<int,bool>&visited,stack<int>&ans)
    {
        visited[i]=1;
        for(auto & k:mp[i])
        {
            if(!visited[k.first])
            {
                toposort(k.first,visited,ans);
            }
        }
        ans.push(i);
    }
    int shortest(int source)
    {
        unordered_map<int,bool>visited;
        stack<int>ans;
        toposort(source,visited,ans);
        unordered_map<int,int>parent;
        parent[source]=-1;
        int n=ans.size();
        
        vector<int>distance(n,INT_MAX);
        source=ans.top();//source toh topo sort ke top pe bhi vahi hoga 
        ans.pop();
        distance[source]=0;
        for(auto & k:mp[source])
        {
            if(k.second+distance[source]<distance[k.first])
            {
                distance[k.first]=k.second+distance[source];
                parent[k.first]=source;
            }
        }
        while(!ans.empty())
        {
            int node=ans.top();
            ans.pop();
            for(auto & k:mp[node])
            {
                if(k.second+distance[node]<distance[k.first])
                {
                    distance[k.first]=k.second+distance[node];
                    parent[k.first]=node;
                }
            }
        }
        int target=3;
        int current=target;
        //finding path and distance
        while(current!=-1)
        {
            if(parent.find(current)==parent.end())
                return -1;
            cout<<current<<" <--  ";
            current=parent[current];
        }
        cout<<endl;
        return distance[target];
    }
};
int main()
{
    graph g;
    g.insert(0,2,13,1);
    g.insert(0,1,5,1);
    g.insert(0,4,3,1);
    g.insert(1,2,7,1);
    g.insert(4,3,6,1);
    g.insert(1,4,1,1);
    g.insert(3,2,2,1);
    cout<<"distance of target from source "<<g.shortest(2);
}