#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<pair<int,int>>>mp;
    public:
    void insert(int i,int j,int wt,int direction)
    {
        if(direction==1)
            mp[i].push_back({j,wt});
        else
        {
            mp[i].push_back({j,wt});
            mp[j].push_back({i,wt});
        }    
    }
    void printer(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"   ";
            vector<pair<int,int>>temp=mp[i];
            for(auto & k:temp)
            {
                cout<<"{ "<<k.first<<" , "<<k.second<<" } ";
            }
            cout<<endl;
        }
    }
    //bsf traversal
    void bfs(int n,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        q.push(n);
        visited[n]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<"   ";
            vector<pair<int,int>>temp=mp[front];
            for(auto & k:temp)
            {
                if(!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first]=1;
                }
            }
        }
    }
    void bfshelper(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(i,visited);
            }
        }
    }
    //dfs travel
    void dfs(int n,unordered_map<int,bool>&visited)
    {
        visited[n]=1;
        cout<<n<<"   ";
        vector<pair<int,int>>temp=mp[n];
        for(auto & k:temp)
        {
            if(!visited[k.first])
            {
                dfs(k.first,visited);
            }
        }
    }
    void dfshelper(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited);
            }
        }
    }
    //bfs cycle undirected
    bool bfscycle(int n,unordered_map<int,bool>&visited,unordered_map<int,int>&parent)
    {
        queue<int>q;
        q.push(n);
        visited[n]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<"   ";
            vector<pair<int,int>>temp=mp[front];
            for(auto & k:temp)
            {
                if(!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first]=1;
                    parent[k.first]=front;
                }
                else
                {
                    if(parent[front]!=k.first)
                        return 1;
                }
            }
        }
        return 0;
    }
    bool bfshelpercycle(int n)
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        parent[0]=-1;
        bool iscycle=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                iscycle=bfscycle(i,visited,parent);
                if(iscycle)
                    return true;
            }
        }
        return 0;
    }
    bool dfscycle(int n,unordered_map<int,bool>&visited,int prev)
    {
        visited[n]=1;
        vector<pair<int,int>>temp=mp[n];
        for(auto & k:temp)
        {
            if(!visited[k.first])
            {
                if(dfscycle(k.first,visited,n))
                    return 1;
            }
            else if(visited[k.first] && prev!=k.first)
            {
                return true;
            }
        }
        visited[n]=0;
        return false;
    }
    bool dfshelpercycle(int n)
    {
        unordered_map<int,bool>visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool iscycle=dfscycle(i,visited,-1);
                if(iscycle)
                    return true;
            }
       }
        return 0;
    }
    bool dfsHelper(int node, unordered_map<int,bool>& vis,unordered_map<int,bool>& dfsTracker) {
            
            vis[node] = true;
            dfsTracker[node] = true;
            
            for(auto nbr: mp[node]) {
                if(!vis[nbr.first]) {
                    bool ans = dfsHelper(nbr.first, vis, dfsTracker);
                    if(ans == true) {
                        return true;
                    }
                }
                else if(vis[nbr.first] == true && dfsTracker[nbr.first] == true) {
                    //cycle present
                    return true;
                }
            }
            
            //backtrack
            dfsTracker[node] = false;
            return false;
        }
        bool isCyclic(int V) {
            bool ans = false;
            int n = V;
            unordered_map<int,bool> vis;
            unordered_map<int,bool> dfsTracker;
            
            for(int i=0; i<n; i++) {
                if(!vis[i]) {
                    ans = dfsHelper(i,vis, dfsTracker);
                    if(ans == true) {
                        break;
                    }
                }
            }
            return ans;
        }
};
int main()
{
    graph g;
    g.insert(0,1,3,1);
    g.insert(0,2,2,1);
    g.insert(0,3,11,1);
    g.insert(2,1,1,1);
   


    // g.insert(1,0,3,1);
    // g.insert(0,2,2,1);
    // g.insert(2,1,1,1);
    // g.insert(1,4,18,1);
    g.printer(4);
    if(g.bfshelpercycle(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;
    if(g.dfshelpercycle(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;
    if(g.isCyclic(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;

}