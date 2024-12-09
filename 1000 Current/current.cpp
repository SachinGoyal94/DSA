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

    void djik() {
        set<pair<int, int>> s; // {distance, node}
        vector<int> v(9, INT_MAX); // Distance array initialized to infinity
        v[0] = 0; // Starting node distance is 0
        s.insert({0, 0}); // Insert starting node into the set

        while (!s.empty()) {
            auto it = s.begin();
            int dist = it->first;
            int val = it->second;
            s.erase(it);

            // Get the adjacency list of the current node
            vector<pair<int, int>> vect = mp[val];
            for (int i = 0; i < vect.size(); i++) {
                int value = vect[i].first; // Neighbor node
                int w = vect[i].second;   // Edge weight

                // Relaxation: Check if we found a shorter path
                if (dist + w < v[value]) {
                    // Remove the old distance if it exists in the set
                    auto record = s.find({v[value], value});
                    if (record != s.end())
                        s.erase(record);

                    // Update the distance and reinsert into the set
                    v[value] = dist + w;
                    s.insert({v[value], value});
                }
            }
        }

        // Print the shortest distances
        cout << "Shortest distances from node 0:" << endl;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == INT_MAX) {
                cout << i << ": INF" << endl;
            } else {
                cout << i << ": " << v[i] << endl;
            }
        }
    }
};

int main() {
    graph g;
    g.insert(0, 1, 4, 0);
    g.insert(0, 7, 8, 0);
    g.insert(7, 1, 11, 0);
    g.insert(2, 1, 8, 0);
    g.insert(2, 8, 2, 0);
    g.insert(2, 5, 4, 0);
    g.insert(2, 3, 7, 0);
    g.insert(7, 8, 7, 0);
    g.insert(7, 6, 1, 0);
    g.insert(8, 6, 6, 0);
    g.insert(6, 5, 2, 0);
    g.insert(5, 3, 14, 0);
    g.insert(5, 4, 10, 0);
    g.insert(3, 4, 9, 0);

    g.djik();
}
