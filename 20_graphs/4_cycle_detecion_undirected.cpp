//cycle detection undirected graphs
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
    void printgraph()  //this will not the print the nodes which are not pointing to any another node  like 3 here
    {
        for(auto & i:mp)
        {
            cout<<i.first<<"{";
            for(auto j:i.second)
            {
                cout<<" ("<<j.first<<","<<j.second<<")";
            }
            cout<<"}"<<endl;
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
    void bfstraversal(int n)
    {
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(n);
        visited[n]=true;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<"   ";
            vector<pair<int,int>>temp=mp[front];
            for(int i=0;i<temp.size();i++)
            {
                if(!visited[temp[i].first])
                {
                    q.push(temp[i].first);
                    visited[temp[i].first]=true;
                }
            }
        }
    }
    void dfshelper(int n,unordered_map<int,bool>& visited)
    {
        if(!visited[n])
        {
            cout<<n<<" ";
            visited[n]=true;
            vector<pair<int,int>>temp=mp[n];
            for(int i=0;i<temp.size();i++)
            {
                dfshelper(temp[i].first,visited);
            }
        }
    }
    void dfstraversal()
    {
        unordered_map<int,bool> visited;
        dfshelper(0,visited);
    }
    void bfstraversaldisconnected(int n,unordered_map<int,bool>&visited)
    {
        queue<int>q;
        q.push(n);
        visited[n]=true;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<"   ";
            vector<pair<int,int>>temp=mp[front];
            for(int i=0;i<temp.size();i++)
            {
                if(!visited[temp[i].first])
                {
                    q.push(temp[i].first);
                    visited[temp[i].first]=true;
                }
            }
        }
    }
    void bfsdisconnected(int n)
    {
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfstraversaldisconnected(i,visited);
            }
        }
    }
    
    
    bool cycleDetectionUndirectedBFS(int src,unordered_map<int,bool>& visited) {
        queue<int> q;
        unordered_map<int,int> parent;
        
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
  
        while(!q.empty()) 
        {
            int frontNode = q.front();
            q.pop();    
            for(auto k: mp[frontNode]) 
            {
                if(!visited[k.first]) 
                {
                    q.push(k.first);
                    visited[k.first] = true;
                    parent[k.first] = frontNode;
                }
                else if(visited[k.first] == true &&   k.first != parent[frontNode]) 
                {
                    return true;
                } 
            }
        }
        return false;
      }
    bool isCycle(int n) 
      {
          bool ans = false;
            unordered_map<int,bool> visited;
            for(int i=0; i<n; i++) 
            {
                if(!visited[i]) 
                {
                    ans = cycleDetectionUndirectedBFS(i,visited);
                    if(ans == true) 
                        break;
                }
            }
          return ans;
      }
    bool checkCycleDfsHelper(int src, unordered_map<int,bool>& vis, int parent) 
      {
        vis[src] = true;
        
        for(auto k: mp[src]) 
        {
            if(!vis[k.first]) 
            {
                bool ans = checkCycleDfsHelper(k.first, vis,src);
                if(ans == true) 
                    return true;
            }
            else if(vis[k.first] == true && k.first != parent) 
            {
                return true;
            }
        }
        return false;
    }
    bool isCycledfs(int n) 
    {
        bool ans = false;
        unordered_map<int,bool> visited;
        int parent = -1;
        for(int i=0; i<n; i++) 
        {
            if(!visited[i]) 
            {
                ans = checkCycleDfsHelper(i,visited, parent);
                if(ans) 
                    break;
            }
        }
        return ans;
    }
};
int main()
{
    graph g;
    g.insert(0,1,3,0);
    g.insert(0,2,2,0);
    g.insert(0,3,11,0);
    g.insert(2,5,15,0);
    // g.insert(2,1,1,0);
    g.insert(1,4,18,0);
    g.insert(4,8,15,0);
    g.insert(1,6,17,0);
    g.insert(3,7,13,0);
    g.insert(9,10,13,0);
    g.insert(10,11,13,0);

    if(g.isCycle(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;
    if(g.isCycledfs(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;
}
