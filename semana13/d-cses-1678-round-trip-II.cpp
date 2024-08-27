#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

#define int int64_t

struct CycleFinder {
    vector<vector<int>> graph;
    vector<int> prev;
    vector<int> status;
    int start;
    int end;

    CycleFinder(vector<vector<int>> x) : graph(x) {
        start = end = -1;
        prev.resize(x.size());
        status.resize(x.size());
    }

    enum { UNVISITED, VISITING, VISITED };
    bool dfs(int vertex) {
        status[vertex] = VISITING;

        for (int adj : graph[vertex]) {
            if (status[adj] == UNVISITED) {
                prev[adj] = vertex;
                if (dfs(adj))
                    return true;
            } else if (status[adj] == VISITING) {
                start = adj;
                end = vertex;
                return true;
            }
        }

        status[vertex] = VISITED;
        return false;
    }

    vector<int> findCycle() {
        bool hasCycle = false;
        for (int i = 0; i < graph.size(); ++i)
            if ((hasCycle = dfs(i)))
                break;
        if (!hasCycle)
            return {};

        vector<int> cycle = {start};
        for (int i = end; i != start; i = prev[i])
            cycle.push_back(i);
        cycle.push_back(start);

        return cycle;
    }
};

int32_t main() {
    FASTIO;
    int cities, roads;
    cin >> cities >> roads;

    vector<vector<int>> adj(cities + 1);
    while (roads--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    auto cycle = CycleFinder(adj).findCycle();
    if (cycle.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << cycle.size() << endl;
    for (auto x = cycle.rbegin(); x != cycle.rend(); ++x)
        cout << *x << " ";
    return 0;
}
