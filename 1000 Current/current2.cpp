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
    bool cycleDetectionUndirectedBFS(int src,unordered_map<int,bool>& visited) {
        queue<int> q;
        unordered_map<int,int> parent;
        
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
  
        while(!q.empty()) {
          int frontNode = q.front();
          q.pop();
  
          for(auto nbr: mp[frontNode]) {
            if(!visited[nbr.first]) {
              q.push(nbr.first);
              visited[nbr.first] = true;
              parent[nbr.first] = frontNode;
            }
            //cycle detection case
            else if(visited[nbr.first] == true && nbr.first != parent[frontNode]) {
              //cycle present
              return true;
            } 
          }
        }
        return false;
      }
      bool isCycle(int n) 
      {
          bool ans = false;
            unordered_map<int,bool> visited;
            for(int i=0; i<n; i++) {
              if(!visited[i]) {
                 ans = cycleDetectionUndirectedBFS(i,visited);
                if(ans == true) {
                  break;
                }
              }
            }
          return ans;
      }
};
int main()
{
    // graph g;
    // g.insert(0,1,3,0);
    // g.insert(0,2,2,0);
    // g.insert(0,3,11,0);
    // g.insert(2,5,15,0);
    // // g.insert(2,1,1,0);
    // g.insert(1,4,18,0);
    // g.insert(4,8,15,0);
    // g.insert(1,6,17,0);
    // g.insert(3,7,13,0);
    // g.insert(9,10,13,0);
    // g.insert(10,11,13,0);
    // if(g.isCycle(13))
    //     cout<<"cycle present"<<endl;
    // else    
    //     cout<<"cycle not present"<<endl;
    for(int i=0;i<5;i++)
    {
      if(i==3)
        continue;
      cout<<i<<endl;
    }
}
