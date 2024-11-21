//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int find(int num, vector<int> &arr) {
        int root = num;
        while (arr[root] != root)
            root = arr[root];

        while (arr[num] != num) {
            int next = arr[num];
            arr[num] = root;
            num = next;
        }

        return root;
    }

    bool merge(int a, int b, vector<int> &arr, vector<int> &dist) {
        a = find(a, arr);
        b = find(b, arr);
        if (a != b) {
            if (dist[a] < dist[b]) {
                int temp = dist[a];
                dist[a] = dist[b];
                dist[b] = temp;
            } else if (dist[a] == dist[b])
                ++dist[a];
            arr[b] = a;
            return false;
        }

        return true;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> dist(V), arr(V);
        for (int i = 0; i < V; ++i)
            arr[i] = i;

        set<pair<int, int>> visited;

        for (int i = 0; i < V; ++i) {
            vector<int> v = adj[i];
            for (int j = 0; j < v.size(); ++j) {
                if (visited.count({i, v[j]}) || visited.count({v[j], i}))
                    continue;
                visited.insert({i, v[j]});
                if (merge(i, v[j], arr, dist))
                    return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
