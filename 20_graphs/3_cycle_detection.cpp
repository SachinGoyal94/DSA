//cycle detection directed graphs
//cycle means atleast 1 node get repeats  
/*
    A-->B               A->B->C->D->A  cycle
    -    |
    |    -
    D<-- C    
*/
/*
    A-->B               A->B->C->D  and A->D  closed loop but not a cycle 
    |    |                                    as no node repeats in path
    -    -
    D<-- C    
*/
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
    void dfsdisconnectedgraph(int n)
    {
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[n])
            {
                dfshelper(i,visited);
            }
        }
        
    }
    bool dfsHelper(int node, unordered_map<int,bool>& vis,unordered_map<int,bool>& dfsTracker) 
    {    
        vis[node] = true;
        dfsTracker[node] = true;
        
        for(auto nbr: mp[node]) 
        {
            if(!vis[nbr.first]) 
            {
                bool ans = dfsHelper(nbr.first, vis,dfsTracker);
                if(ans == true)
                    return true;
            }
            else if(dfsTracker[nbr.first] == true) 
            {
                return true;
            }
        }
        dfsTracker[node] = false;
        return false;
    }
    bool isCyclic(int n) 
    {
        bool ans = false;
        unordered_map<int,bool> vis;
        unordered_map<int,bool> dfsTracker;
        
        for(int i=0; i<n; i++) 
        {
            if(!vis[i]) 
            {
                ans = dfsHelper(i,vis,dfsTracker);                    
                if(ans == true) 
                    break;
            }
        }
        return ans;
    }
};
int main()
{
    graph g;
    g.insert(1,0,3,1);
    g.insert(0,2,2,1);
    g.insert(0,3,11,1);
    g.insert(2,5,15,1);
    g.insert(2,1,1,1);
    g.insert(1,4,18,1);
    g.insert(4,8,15,1);
    g.insert(1,6,17,1);
    g.insert(3,7,13,1);
    g.insert(9,10,13,1);
    g.insert(10,11,13,1);
    g.printgraph();
    if(g.isCyclic(13))
        cout<<"cycle present"<<endl;
    else    
        cout<<"cycle not present"<<endl;
}
