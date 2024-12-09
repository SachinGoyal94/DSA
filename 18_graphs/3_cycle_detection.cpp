//cycle detection directed graphs
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
    
    //what if there are disconnected components also
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
    int cycledetection()//using bfs
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;        
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            vector<pair<int,int>>temp=mp[front];
            for(int i=0;i<temp.size();i++)
            {
                int node=temp[i].first;
                if(visited[node])
                {
                    if(parent[node]!=front)
                    {
                        //cycle detected
                        return 1;
                    }
                }
                else
                {
                    parent[node]=front;
                    visited[node]=true;
                    q.push(node);
                }
            }
        }
        return 0;
    }
};
int main()
{
    graph g;
    //0 is the source node
    //(u,v,weight,direction)  u,v connecting nodes weight=distance of one node to another direction 1=u->v 0 u<=>v
    g.insert(0,1,3,1);
    g.insert(1,2,18,1);
    g.insert(1,3,15,1);
    g.insert(2,3,1,1);
    
    cout<<endl<<"full graph "<<endl;
    g.fullprint(4);
    
    cout<<endl<<"bfs traversal"<<endl;
    g.bfstraversal(0);
    cout<<endl<<"dfs traversal"<<endl;
    g.dfstraversal();
    cout<<endl;

    g.insert(9,10,4,1);
    g.fullprint(10);
    cout<<endl<<"bfs traversal for disconnected graphs"<<endl;
    g.bfsdisconnected(10);
    cout<<endl<<"dfs traversal for disconnected graphs"<<endl;//same can be applied for bfs traversal
    g.dfsdisconnectedgraph(10);

    cout<<"checking cycle detection"<<endl;
    int cycle=g.cycledetection();
    cout<<cycle;
}
