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
    void djik()
    {
        set<pair<int,int>>s;
        vector<int>v(9,INT_MAX);
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
    g.insert(0,1,4,0);
    g.insert(0,7,8,0);
    g.insert(7,1,11,0);
    g.insert(2,1,8,0);
    g.insert(2,8,2,0);
    g.insert(2,5,4,0);
    g.insert(2,3,7,0);
    g.insert(7,8,7,0);
    g.insert(7,6,1,0);
    g.insert(8,6,6,0);
    g.insert(6,5,2,0);
    g.insert(5,3,14,0);
    g.insert(5,4,10,0);
    g.insert(3,4,9,0);
    g.djik();
}