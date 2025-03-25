//can't use dfs  to find  shortest distance bcoz here as dfs recieve target node it will terminate 
//although there may be case where from alternate nodes from source distance may be shorter
//in bfs we have queue which holds nodes from source and we traverse till queue is not empty so every 
//possibility is checked
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
    void dfshelper(int source,int target,unordered_map<int,int>&parent,vector<int>&distance)
    {
        vector<pair<int,int>>temp=mp[source];
        for(int i=0;i<temp.size();i++)
        {
            int k=temp[i].first;
            int wt=temp[i].second;
            if(distance[k]>wt+distance[source])
            {
                distance[k]=wt+distance[source];
                parent[k]=source;
                dfshelper(temp[i].first,target,parent,distance);
            }
        }
    }
    int dfshelpers(int source,int target,int n,vector<pair<int,int>>&ans)
    {
        unordered_map<int,int>parent;
        unordered_map<int,bool>visited;
        vector<int>distance(n,INT_MAX);
        distance[source]=0;
        for(int i=0;i<n;i++)
        {
            dfshelper(source,target,parent,distance);
        }
        int current=target;
        int distances=0;
        while(current!=source)
        {
            if(parent.find(current)==parent.end())
                return -1;
            int curr=parent[current];
            for(auto & k:mp[curr])
            {
                if(k.first==current)
                {
                    distances+=k.second;
                    ans.push_back({curr,current});
                }
            }
            current=curr;
        } 
        return distances;
    }
};
int main()
{
    graph g;
    g.insert(0,2,13,1);
    g.insert(0,1,5,1);
    g.insert(4,1,1,1);
    g.insert(0,4,3,1);
    g.insert(1,2,7,1);
    g.insert(3,2,2,1);
    g.insert(4,3,6,1);
    cout<<endl<<"full graph "<<endl;
    g.fullprint(5);
    cout<<endl<<"bfs traversal"<<endl;
    g.bfsdisconnected(5);
    cout<<endl;
    vector<pair<int,int>>ans;
    int mindistance=g.dfshelpers(0,2,5,ans);
    cout<<mindistance<<endl;
    reverse(ans.begin(),ans.end());
    for(auto &k:ans)
    {
        cout<<k.first<<"-->";
    }
}
