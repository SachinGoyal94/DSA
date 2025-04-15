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
    int findmin(vector<int>&visited,vector<int>&dist,int n)
    {
        int maxi=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(dist[i]<maxi && !visited[i])
            {
                maxi=dist[i];
                index=i;
            }
        }
        return index;
    }
    void prism(int n)
    {
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        vector<int>visited(n,false);
        vector<int>parent(n,-1);
        while(1)
        {
            int index=findmin(visited,dist,n);
            if(index==-1)
                break;
            //yahan tak index mil gya is node se span form krna abhi 
            visited[index]=true;
            vector<pair<int,int>>v=mp[index];
            for(int i=0;i<v.size();i++)
            {
                int value=v[i].first;
                int weight=v[i].second;
                if(!visited[value] && weight<dist[value])
                {
                    parent[value]=index;
                    dist[value]=weight;
                }
            }
        }
        cout<<"distance  "<<"visited "<<"parent "<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<dist[k]<<" "<<visited[k]<<" "<<parent[k]<<" "<<endl;
        }
        //finding min weigth
        int sum = 0;
        for(int u = 0; u <n; u++){
            if(parent[u] == -1) 
                continue;
            for(auto &edge: mp[u])
            {
                int v = edge.first;
                int w = edge.second;
                if(v == parent[u]){
                    sum += w;
                }
            }
        }
        cout<<sum<<endl;
    }
};
int main()
{
    graph g;
    g.insert(0,1,2,0);
    g.insert(0,3,6,0);
    g.insert(1,4,5,0);
    g.insert(3,1,8,0);
    g.insert(4,2,7,0);
    g.insert(1,2,3,0);

    g.prism(5);
}