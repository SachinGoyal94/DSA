#include<bits/stdc++.h>
using namespace std;
class graph
{
    unordered_map<int,vector<pair<int,int>>>mp;
    public:
    void insert(int i,int j,int wt,int direction)
    {
        if(direction==1)
            mp[i].push_back({j,wt});
        else
        {
            mp[i].push_back({j,wt});
            mp[j].push_back({i,wt});
        }    
    }
    void printer(int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"   ";
            vector<pair<int,int>>temp=mp[i];
            for(auto & k:temp)
            {
                cout<<"{ "<<k.first<<" , "<<k.second<<" } ";
            }
            cout<<endl;
        }
    }
    //bfs traversal to find topological sorting
    void bfs(int n,unordered_map<int,bool>&visited,unordered_map<int,int>&indegree)
    {
        queue<int>q;
        q.push(n);
        visited[n]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            vector<pair<int,int>>temp=mp[front];
            for(auto & k:temp)
            {
                indegree[k.first]++;
                if(!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first]=1;
                }
            }
        }
    }
    void topsort(int n,unordered_map<int,bool>&visited,unordered_map<int,int>&indegree,vector<int>&ans)
    {
        queue<int>q;
        q.push(n);
        visited[n]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            ans.push_back(front);
            vector<pair<int,int>>temp=mp[front];
            for(auto & k:temp)
            {
                indegree[k.first]--; 
                if(!visited[k.first] && indegree[k.first]==0)
                {
                    q.push(k.first);
                    visited[k.first]=1;
                }
            }
        }
    }
    vector<vector<int>> bfshelper(int n)
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>indegree;
        indegree[0]=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(i,visited,indegree);
            }
        }
        //abb indegree bhi mil gaye
        //start topological sorting
        unordered_map<int,bool>visit;
        vector<vector<int>>result;
        for(int i=0;i<n;i++)
        {
            vector<int>ans;
            if(!visit[i] && indegree[i]==0 )
            {
                topsort(i,visit,indegree,ans);
                result.push_back(ans);
            }
        }
        return result;
    }
    //dfs travel to find topological sorting 
    void dfs(int n,unordered_map<int,bool>&visited,stack<int>&s)
    {
        visited[n]=1;
        vector<pair<int,int>>temp=mp[n];
        for(auto & k:temp)
        {
            if(!visited[k.first])
            {
                dfs(k.first,visited,s);
            }
        }
		s.push(n);
    }
    stack<int> dfshelper(int n)
    {
        unordered_map<int,bool>visited;
		stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,s);
            }
        }
		return s;
    }
};
int main()
{
    graph g;
    g.insert(0,1,3,1);
    g.insert(1,2,2,1);
    g.insert(2,3,11,1);
    g.insert(2,4,1,1);
	g.insert(3,5,1,1);
	g.insert(4,5,1,1);
	g.insert(5,6,1,1);
    g.insert(7,8,1,1);
    g.insert(9,10,1,1);
    g.printer(11);
	cout<<endl;
    vector<vector<int>>ans=g.bfshelper(11);
    for(auto & i:ans)
    {
        for(auto& j:i)
        {
            cout<<j<<"->";
        }
        cout<<endl;
    }
    cout<<endl;
    stack<int>s=g.dfshelper(11);
	while(!s.empty())
	{
		cout<<s.top()<<"   ";
		s.pop();
	}
    //9   10   7   8   0   1   2   4   3   5   6 
    // output for dfs can be 0 1 2 4 3 5 6   
    //                       9 10  
    //                       7 8
}