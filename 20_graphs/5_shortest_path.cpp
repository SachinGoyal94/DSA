//creating graphs 
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
    void bfstraversal(int n,int destination)
    {
        unordered_map<int,int>parent;
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(n);
        visited[n]=true;
        parent[0]=-1;
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
                    parent[temp[i].first]=front;
                    q.push(temp[i].first);
                    visited[temp[i].first]=true;
                }
            }
        }
        vector<int>ans;
        ans.push_back(destination);
        int current=destination;
        while(current!=0)
        {
            current=parent[current];
            ans.push_back(current);
        } 
        reverse(ans.begin(),ans.end());
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[j]<<"->";
        }
        cout<<endl;
    }
};
int main()
{
    graph g;
    g.insert(0,1,11,1);
    g.insert(0,2,2,1);
    g.insert(0,3,11,1);
    g.insert(1,4,11,1);
    g.insert(1,6,11,1);
    g.insert(4,8,11,1);
    g.insert(2,8,1,1);
    g.insert(3,7,13,1);
    
    cout<<endl<<"full graph "<<endl;
    g.fullprint(8);
    
    cout<<endl<<"bfs traversal"<<endl;
    g.bfstraversal(0,8);

    //g.shortestpath();

}
