#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<pair<int,int>>>mp;
    public:
    void insert(int i,int j,bool d,int w)
    {
        mp[i].push_back({j,w});
        if(d)
            mp[j].push_back({i,w});
    }
    void fullprint(int n)
    {
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>>v=mp[i];
            cout<<i<<" { ";
            for(int j=0;j<v.size();j++)
            {
                int val=v[j].first;
                int dist=v[j].second;
                cout<<" ( "<<val <<"  , "<<dist <<"  ) ";
            }
            cout<<" } "<<endl;
        }
    }
    void bfs(int i,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<"   ";
            vector<pair<int,int>>v=mp[front];
            for(int j=0;j<v.size();j++)
            {
                if(!visited[v[j].first])
                {
                    q.push(v[j].first);
                    visited[v[j].first]=1;
                }
            }
        }
        cout<<endl;
    }
    void bfshelper(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                bfs(i,visited);
        }
    }
    void dfs(int i,unordered_map<int,bool>&visited)
    {
        if(!visited[i])
        {
            cout<<i<<"   ";
            visited[i]=1;
            vector<pair<int,int>>v=mp[i];
            for(int j=0;j<v.size();j++)
            {
                dfs(v[j].first,visited);
            }
        }
        
    }
    int dfscycle(int i,unordered_map<int,bool>&visited,unordered_map<int,bool>&track)
    {
        if(!visited[i])
        {
            track[i]=1;
            cout<<i<<"   ";
            visited[i]=1;
            vector<pair<int,int>>v=mp[i];
            for(int j=0;j<v.size();j++)
            {
                return dfscycle(v[j].first,visited,track);
            }
            track[i]=0;
        }
        else 
        {
            if(track[i]==1)
                return 1;
        }
        return 0;
    }
    int iscycle(int n)
    {
        unordered_map<int,bool>visited,track;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfscycle(i,visited,track))
                    return true;
            }
        }
        return false;
    }
    void dfshelper(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i,visited);
        }
    }
};
int main()
{
    graph g;
    g.insert(0,1,0,3);
    g.insert(0,2,0,5);
    g.insert(1,3,0,3);
    g.insert(1,4,0,7);
    g.insert(1,5,0,9);
    g.insert(2,3,0,1);
    g.insert(2,6,0,3);
    g.insert(3,7,0,5);
    g.insert(3,8,0,3);
    g.insert(6,9,0,5);
    
    g.fullprint(10);

    g.bfshelper(10);

    g.dfshelper(10);
}