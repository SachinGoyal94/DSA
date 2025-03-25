// TC O(E log V)
//non negative weighed directed/undirected only
//in standard djikstra updation and reinsertion of pairs in sets not allowed and its TC is O(V^2) but  
//to reduce TC we use this method
//gives min distance of every node from source node

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
    void djik(int n)
    {
        set<pair<int,int>>s;
        vector<int>v(n,INT_MAX);
        s.insert(make_pair(0,0));
        v[0]=0;
        while(!s.empty())
        {
            auto it=s.begin();//gives min distance value first 
            int dist=it->first;
            int val=it->second;
            s.erase(s.begin());
            vector<pair<int,int>>vect=mp[val];
            for(int i=0;i<vect.size();i++)
            {
                int value=vect[i].first;
                int w=vect[i].second;
                if(dist+w<v[value])
                {
                    auto record=s.find(make_pair(v[value],value));
                    if(record!=s.end())
                        s.erase(record);
                    v[value]=w+dist;
                    s.insert(make_pair(dist + w,value));
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }
    }
};
int main()
{
    graph g;
    g.insert(0,3,6,1);
    g.insert(0,5,9,1);
    g.insert(5,4,2,1);
    g.insert(3,4,11,1);
    g.insert(5,1,14,1);
    g.insert(4,1,9,1);
    g.insert(4,2,10,1);
    g.insert(3,2,15,1);
    g.insert(1,2,7,1);
    g.djik(6);
}