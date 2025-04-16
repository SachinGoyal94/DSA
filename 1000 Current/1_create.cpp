#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    unordered_map<int,vector<pair<int,int>>>mp;
    void insert(int i,int j,bool direction ,int distance)
    {
        if(direction)
        {
            mp[i].push_back({j,distance});
            return;
        }
        mp[i].push_back({j,distance});
        mp[j].push_back({i,distance});
    }
    void print(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<" "<<i<<" ";
            for(auto & k:mp[i])
            {
                    int end=k.first;
                    int weight=k.second;
                    cout<<" { "<<end<<" "<<weight<<" } ";
            }
            cout<<endl;
        }
    }
    void bfstraversal(int i,unordered_map<int,int>&visited)
    {
        queue<int>q;
        q.push(i);
        visited[i]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<endl;
            for(auto & k:mp[front])
            {
                if(!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first]=1;
                }
            }
        }
    }
    void dfstraversal(int i,unordered_map<int,int>&visited)
    {
        if(!visited[i])
        {
            cout<<i<<endl;
            visited[i]=1;
            for(auto &k:mp[i])
            {
                dfstraversal(k.first,visited);
            }
        }
    }
    void disconnected(int n,int choice)
    {
        unordered_map<int,int>visited;
        if(choice)
        {
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    bfstraversal(i,visited);
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    dfstraversal(i,visited);
                }
            }
        }
    }
    void djikstra(int n)
    {
        set<pair<int,int>>s;
        s.insert({0,0});
        vector<int>v(n,INT_MAX);
        v[0]=0;
        while(!s.empty())
        {
            auto it=s.begin();
            int node=it->second;
            int distance=it->first;
            s.erase(s.begin());
            vector<pair<int,int>>adj=mp[node];
            for(int i=0;i<adj.size();i++)
            {
                int value=adj[i].first;
                int wt=adj[i].second;
                if(distance+wt<v[value])
                {
                    auto record=s.find({v[value],value});
                    if(record!=s.end())
                        s.erase(record);
                    s.insert({v[value]=distance+wt,value});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<"   ";
        }
    }
};
int main()
{
    Graph g;
    // g.insert(0,1,0,13);
    // g.insert(0,2,0,12);
    // g.insert(0,3,0,11);
    // g.insert(1,4,0,18);
    // g.insert(2,5,0,15);
    // g.insert(4,8,0,16);
    // g.insert(1,6,0,17);
    // g.insert(3,7,0,19);
    // g.insert(9,10,0,24);
    // g.insert(10,11,0,21);
    // g.insert(8,6,0,12);
    
    g.insert(0,1,1,11);
    g.insert(0,2,1,12);
    g.insert(1,3,1,13);
    g.insert(1,4,1,14);
    g.insert(2,5,1,15);
    g.insert(2,6,1,16);
    g.insert(5,1,1,155);
    g.print(7);
    g.disconnected(7,0);
    g.djikstra(7);
}