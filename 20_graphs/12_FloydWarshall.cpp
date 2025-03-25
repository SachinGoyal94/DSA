//for -ve cycle 
//notebook
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
    void Floyd(int n)
    {
        //TC O(n^3)
        vector<vector<int>>dist(n,vector<int>(n,1e9));//as INT_MAX+k=INT_MIN

        for(int source=0;source<n;source++)
        {
            dist[source][source]=0;
        }
        for(auto &k:mp)
        {
            int node=k.first;
            for(auto &l:k.second)
            {
                int val=l.first;
                int wt=l.second;
                dist[node][val]=wt;
            }
        }
        
        for(int helper=0;helper<n;helper++)
        {
            for(int source=0;source<n;source++)
            {
                for(int dest=0;dest<n;dest++)
                {
                    dist[source][dest]=min(dist[source][dest],dist[source][helper]+dist[helper][dest]);
                }
            }
        }

        //printing the distances
        for(int dest=0;dest<n;dest++)
        {
            cout<<"     "<<dest<<"    ";
        }
        cout<<endl;
        for(int source=0;source<n;source++)
        {
            cout<<source<<"    ";
            for(int dest=0;dest<n;dest++)
            {
                cout<<dist[source][dest]<<"       ";
            }
            cout<<endl;
        }
    }  
};
int main()
{
    graph g;
    g.insert(1,0,4,1);
    g.insert(0,2,-2,1);
    g.insert(1,2,3,1);
    g.insert(2,3,2,1);
    g.insert(3,1,-1,1);
    g.Floyd(4);


}
