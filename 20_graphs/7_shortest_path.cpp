//single source shortest path 
//if undirected graph and we have to calc short. path on the basis of 
//distance/weight and if weights are not given assume every node has same weight
//only works for uniform weights only

//bfs use krenge toh target node jab first time visit hogi vahi shortest distance hoga
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
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        parent[source]=-1;
        //abb destination se source ki taraf jao here source is 0
        //destination =7 and source =0;
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            visited[front]=1;
            vector<pair<int,int>>temp=mp[front];
            for(auto & j:temp)
            {
                int val=j.first;
                if(!visited[val])
                {
                    q.push(val);
                    parent[val]=front;
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
                    cout<<distance<<"   "<<current<<"   "<<curr_parent<<"   "<<endl;
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
    g.insert(0,1,1,0);
    g.insert(1,2,1,0);
    g.insert(2,3,1,0);
    g.insert(3,4,1,0);
    g.insert(4,6,1,0);
    g.insert(6,7,1,0);
    g.insert(7,3,1,0);
    g.insert(3,5,1,0);
    g.insert(9,10,1,0);
    g.insert(10,11,1,0);
    cout<<"full graph "<<endl;
    g.fullprint(12);
    int target=7;
    int source=0;
    vector<pair<int,int>>path;
    //now finding the shortest distance using bfs 
    int distance=g.bfs(source,11,target,path);
    cout<<"distance is "<< distance<<endl;
    reverse(path.begin(),path.end());
    for(auto i:path)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}
