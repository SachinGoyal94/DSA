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
    void printgraph()  //this will not the print the nodes which are not pointing to any another node  like 3 here
    {
        for(auto & i:mp)
        {
            cout<<i.first<<"{";
            for(auto j:i.second)
            {
                cout<<" ("<<j.first<<","<<j.second<<")";
            }
            cout<<"}"<<endl;
        }
    }
    void lineardata(int n,vector<vector<int>>&edges)
    {
        for(int u = 1; u <=n; u++){
            for(auto edge: mp[u]){
                int v = edge.first;
                int w = edge.second;
                edges.push_back({u,v,w});
            }
        }
    }
    
};
static bool myCmp(vector<int>&a, vector<int>&b)
{
    return a[2] < b[2];
}
int findParent(vector<int>&parent, int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = findParent(parent,parent[node]); 
    }

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank)
{
    if(rank[u] < rank[v])
        parent[u] = v;
    else    if(rank[u] > rank[v])
                parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    graph g;
    g.insert(1,4,1,0);
    g.insert(1,2,2,0);
    g.insert(4,2,3,0);
    g.insert(2,3,3,0);
    g.insert(1,5,4,0);
    g.insert(4,3,5,0);
    g.insert(2,6,7,0);
    g.insert(3,6,8,0);
    g.insert(5,4,9,0);
    int n=6;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    for(int u = 1; u <= n; u++)
    {
        parent[u] = u;
    }
    //now graph is made so we need a linear data structure to store the nodes and weight
    vector<vector<int>> edges;
    g.lineardata(n,edges);
    // sort the edges linear data structure
    sort(edges.begin(), edges.end(), myCmp);

    int ans = 0;    //min weight in mst 
    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        u = findParent(parent, u);
        v = findParent(parent, v);
        if(u!=v) //if parent of 2 is and parent of 3 is also 1 then why to unite already connected 
        {
            // union
            unionSet(u, v, parent, rank);
            ans += w;   //as already min weigth ke acc nodes coming so mst me yahi united hongi toh inka wt add krdo
        }
    }
    //printing min mst
    for(int i=1;i<=n;i++)
    {
        cout<<"parent of "<< i<<" = "<<findParent(parent,i)<<endl;
    }
    cout<<"min wt in mst is "<<ans;
}

//for diconnected graph
/*
#include <bits/stdc++.h>
using namespace std;

class graph {
    unordered_map<int, vector<pair<int, int>>> mp;

public:
    void insert(int u, int v, int w, int direction) {
        if (direction == 0) {
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        } else {
            mp[u].push_back({v, w});
        }
    }

    void printgraph(int n) {
        for (int i = 1; i <= n; i++) {
            cout << i << " {";
            if (mp.find(i) != mp.end()) {
                for (auto j : mp[i]) {
                    cout << " (" << j.first << "," << j.second << ")";
                }
            }
            cout << " }" << endl;
        }
    }

    void lineardata(int n, vector<vector<int>>& edges) {
        for (int u = 1; u <= n; u++) {
            if (mp.find(u) != mp.end()) {
                for (auto edge : mp[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    edges.push_back({u, v, w});
                }
            }
        }
    }
};

// Sorting function for Kruskal's Algorithm
static bool myCmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2]; // Sort edges by weight in ascending order
}

// Find function with path compression
int findParent(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]); // Path compression
    return parent[node];
}

// Union function without redundant parent finding
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    graph g;
    
    // Graph with disconnected components
    g.insert(1, 2, 1, 0);
    g.insert(2, 3, 2, 0);
    g.insert(3, 4, 3, 0);
    
    g.insert(5, 6, 4, 0);
    g.insert(6, 7, 5, 0);

    int n = 7; // Number of nodes
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Initialize DSU (Disjoint Set Union)
    for (int u = 1; u <= n; u++) {
        parent[u] = u;
    }

    // Convert graph into linear edge list
    vector<vector<int>> edges;
    g.lineardata(n, edges);
    
    // Sort edges based on weight
    sort(edges.begin(), edges.end(), myCmp);

    int mst_weight = 0; // Store total weight of MST
    int components = n; // Initially, each node is its own component

    // Kruskal's Algorithm for Minimum Spanning Forest
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u != v) { // If not in the same set, unite them
            unionSet(u, v, parent, rank);
            mst_weight += w; 
            components--; // One less component after union
        }
    }

    // Identify distinct components
    unordered_map<int, vector<int>> mst_components;
    for (int i = 1; i <= n; i++) {
        int root = findParent(parent, i);
        mst_components[root].push_back(i);
    }

    // Print MST for each component
    cout << "\nMinimum Spanning Forest (MSF):\n";
    for (auto& comp : mst_components) {
        cout << "Component with root " << comp.first << ": { ";
        for (int node : comp.second)
            cout << node << " ";
        cout << "}\n";
    }

    // Print total weight of MST
    cout << "\nTotal Minimum Spanning Forest Weight: " << mst_weight << endl;

    return 0;
}

*/