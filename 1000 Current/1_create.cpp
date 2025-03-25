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
    void bfstraversal(int i,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        q.push(i);
        cout<<q.front()<<"   ";
        while(!q.empty())
        {
            visited[q.front()]=true;
            vector<pair<int,int>>v=mp[q.front()];
            q.pop();
            for(auto &k:v)
            {
                if(!visited[k.first])
                {
                    cout<<k.first<<"   ";
                    q.push(k.first);
                    visited[k.first]=1;
                }
            }
        }
    }
    void dfstraversal(int i,unordered_map<int,bool>&visited)
    {
        if(!visited[i])
        {
            cout<<i<<"   ";
            visited[i]=true;
            vector<pair<int,int>>v=mp[i];
            for(auto & k:v)
            {
                dfstraversal(k.first,visited);
            }
        } 
    }
    void helper(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                // bfstraversal(i,visited);
                dfstraversal(i,visited);
            }
        }
    }

    //undirected
    int cyclebfs(int i,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(i);
        parent[i]=-1;
        visited[i]=true;
        while(!q.empty())
        {
            int front=q.front();
            vector<pair<int,int>>v=mp[front];
            q.pop();
            for(auto &k:v)
            {
                if(!visited[k.first])
                {
                    parent[k.first]=front;
                    q.push(k.first);
                    visited[k.first]=1;
                }
                else
                {
                    if(parent[front]!=k.first)
                        return true;
                }
            }
        }
        return false;
    }
    bool iscyclebfs(int n)
    {
        unordered_map<int,bool>visited;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans=cyclebfs(i,visited);
                if(ans==true)
                    return ans;
            }
            
        }
        return false;
    }

    int dfscycle(int i,unordered_map<int,bool>&visited,int lastnode)
    {
        visited[i]=true;
        vector<pair<int,int>>v=mp[i];
        for(auto & k:v)
        {
            if(!visited[k.first])
            {
                if(dfscycle(k.first,visited,i))
                    return true;
            }
            else
            {
                if(k.first!=lastnode)
                    return true;
            }
        }
        return false;
    }
    int iscycledfs(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfscycle(i,visited,-1))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph g;
    g.insert(0,1,0,13);
    g.insert(0,2,0,12);
    g.insert(0,3,0,11);
    // g.insert(1,4,0,18);
    // g.insert(2,5,0,15);
    // g.insert(4,8,0,16);
    // g.insert(1,6,0,17);
    // g.insert(3,7,0,19);
    // g.insert(9,10,0,24);
    // g.insert(10,11,0,21);
    // g.insert(8,6,0,12);
    g.print(12);
    g.helper(12);
    bool cycleinbfs=g.iscyclebfs(12);
    cout<<endl<<cycleinbfs<<endl;
    
    bool cycleindfs=g.iscycledfs(12);
    cout<<endl<<cycleindfs<<endl;
}