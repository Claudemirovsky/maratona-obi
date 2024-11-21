//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    enum { UNVISITED, VISITING, VISITED };
    vector<char> status;
    vector<int> *graph;

    bool dfs(int node) {
        status[node] = VISITING;
        for (int adj : graph[node]) {
            if (status[adj] == UNVISITED) {
                if (dfs(adj))
                    return true;
            } else if (status[adj] == VISITING)
                return true;
        }
        status[node] = VISITED;
        return false;
    }
    bool isCyclic(int V, vector<int> *adj) {
        graph = adj;
        status.resize(V);
        for (int i = 0; i < V; ++i)
            if (status[i] == UNVISITED && dfs(i))
                return true;
        // code here
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
