//tells no of stronger compnents (where any node can travel to any other in a component)
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
    void toposort(int i,stack<int>&s,unordered_map<int,bool>&visited)
    {
        visited[i]=true;
        for(auto & k:mp[i])
        {
            if(!visited[k.first])
            {
                toposort(k.first,s,visited);
            }
        }
        s.push(i);
    }
    void dfs(int i,unordered_map<int,vector<pair<int,int>>>&mpnew,unordered_map<int,bool>&visited)
    {
        visited[i]=1;
        for(auto&k:mpnew[i])
        {
            if(!visited[k.first])
            {
                dfs(k.first,mpnew,visited);
            }
        }
    }
    int kosaraju(int n)
    {
        stack<int>s;
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                toposort(i,s,visited);
        }
        unordered_map<int,vector<pair<int,int>>>mpnew; //creating graph with reverse edges
        for(auto &k:mp)
        {
            int node=k.first;
            for(auto &d:mp[node])
            {
                int val=d.first;
                int wt=d.second;
                mpnew[val].push_back({node,wt});
            }
        }
        unordered_map<int,bool>visit;
        int count=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            //dfs traversal
            if(!visit[node])
            {
                dfs(node,mpnew,visit);
                count++;
            }
        }
        return count;
    }
};
int main()
{
    graph g;
    g.insert(0,3,4,1);
    g.insert(3,2,2,1);
    g.insert(2,1,3,1);
    g.insert(1,0,2,1);
    g.insert(2,4,1,1);
    g.insert(4,5,1,1);
    g.insert(5,6,1,1);
    g.insert(6,4,1,1);
    g.insert(5,7,1,1);
    cout<<"no of stronger components are  : "<<g.kosaraju(7);
}
