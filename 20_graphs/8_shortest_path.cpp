//what if different weights are there
#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<pair<int,int>>>mp;
    public:
    void insert(int u ,int v ,int wt,int direction)
    {
        if(direction ==0)
        {
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        else
        {
            mp[u].push_back({v,wt});
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
                cout<<" ( "<<temp[j].first<<" , "<<temp[j].second<<" )   ";
            }
            cout<<"}"<<endl;
        }
    }
    int bfs(int source,int n,int target,vector<pair<int,int>>&path)
    {
        unordered_map<int,int>parent;
        vector<int>distances(n,INT_MAX);
        parent[source]=-1;
        //abb destination se source ki taraf jao here source is 0
        //destination =7 and source =0;
        queue<int>q;
        q.push(source);
        distances[source]=0;
        while(!q.empty())
        {
            int front=q.front();
            int distance=distances[front];
            q.pop();
            vector<pair<int,int>>temp=mp[front];
            for(auto & j:temp)
            {
                int val=j.first;
                int wt=j.second;
                if(distance+wt<distances[val])
                {
                    q.push(val);
                    parent[val]=front;
                    distances[val]=distance+wt;
                }
            }
        }
        int current =target;
        int distance=0;
        while(current!=source)
        {
            if(parent.find(current)==parent.end())
            {
                //source node se target connect hi nahi hai
                return -1;
            }
            int curr_parent=parent[current];
            auto val=mp[curr_parent];
            for(auto& k:val)
            {
                if(k.first==current)
                {
                    distance+=k.second;
                    path.push_back({curr_parent,current});
                }
            }
            current=curr_parent;
        }
        return distance;
    }
};
int main()
{
    graph g;
    g.insert(1,2,2,0);
    g.insert(2,5,5,0);
    g.insert(2,3,4,0);
    g.insert(1,4,1,0);
    g.insert(4,3,3,0);
    g.insert(3,5,1,0);
    cout<<"full graph "<<endl;
    g.fullprint(6);
    int target=4;
    int source=2;
    vector<pair<int,int>>path;
    //now finding the shortest distance using bfs 
    int distance=g.bfs(source,6,target,path);
    cout<<"distance is "<< distance<<endl;
    reverse(path.begin(),path.end());
    for(auto i:path)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}
