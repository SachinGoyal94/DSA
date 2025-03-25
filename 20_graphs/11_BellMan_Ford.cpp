//for -ve weights not -ve cycle 
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
    int bellman(int n)
    {
        vector<int>dist(n,INT_MAX);
        int source=0;
        dist[source]=0;
        for(int i=0;i<n;i++)
        {
            for(auto& k:mp)
            {
                int node=k.first;
                //k=int,vector<pair<intint>>
                for(auto & l:k.second)
                {
                    int val=l.first;
                    int wt=l.second;
                    if(dist[node]!=INT_MAX &&  wt+dist[node]<dist[val])//relaxation step
                    {
                        dist[val]=wt+dist[node];
                    }
                }
            }
        }
        //to check if given graph is not a -ve cycle
        bool cyclepresent=0;
        for(auto& k:mp)
        {
            int node=k.first;
            //k=int,vector<pair<intint>>
            for(auto & l:k.second)
            {
                int val=l.first;
                int wt=l.second;
                if(dist[node]!=INT_MAX &&  wt+dist[node]<dist[val])//relaxation step
                {
                    dist[val]=wt+dist[node];
                    cyclepresent=1;
                    return cyclepresent;
                }
            }
        }
        //printing every distance now
        for(auto &d:dist)
        {
            cout<<d<<"   "<<endl;
        }
        return cyclepresent;
    }  
};
int main()
{
    graph g;
    g.insert(0,1,-1,1);
    g.insert(1,4,2,1);
    g.insert(0,2,4,1);
    g.insert(3,2,5,1);
    g.insert(4,3,-3,1);
    g.insert(3,1,1,1);
    g.insert(1,3,2,1);
    g.insert(1,2,3,1);


    // g.insert(0,1,-1,1);
    // g.insert(1,0,-2,1);
    cout<<"is -ve cycled graph "<<g.bellman(5);
}
