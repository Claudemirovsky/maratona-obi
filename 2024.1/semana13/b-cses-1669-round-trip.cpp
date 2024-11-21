#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

#define int int64_t

struct Treco {
    vector<int> arr;
    vector<int> dist;
    vector<vector<int>> adj;
    Treco(int size) {
        arr.resize(size + 1);
        dist.resize(size + 1);
        adj.resize(size + 1);
        for (int i = 0; i <= size; ++i)
            arr[i] = i;
    }

    int find(int num) {
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

    int create_union(int a, int b) {
        int pa = a, pb = b;
        a = find(a);
        b = find(b);

        if (a != b) {
            if (dist[a] < dist[b]) {
                int tmp = dist[a];
                dist[a] = dist[b];
                dist[b] = tmp;
            } else if (dist[a] == dist[b])
                ++dist[a];
            arr[b] = a;
            adj[pa].push_back(pb);
            adj[pb].push_back(pa);
            return 1;
        }
        return 0;
    }

    void dfs(vector<int> &path, int prev) {
        for (auto x : adj[prev]) {
            if (x == path[prev])
                continue;
            path[x] = prev;
            dfs(path, x);
        }
    }

    vector<int> get_path(int start, int end) {
        fill(arr.begin(), arr.end(), 0);
        dfs(arr, start);

        vector<int> path;
        int curr = end;
        while (curr != 0) {
            path.push_back(curr);
            curr = arr[curr];
        }
        path.push_back(end);
        return path;
    }
};

int32_t main() {
    FASTIO;

    int cities, roads;
    cin >> cities >> roads;
    Treco mizera(cities);

    for (int i = 0; i < roads; ++i) {
        int a, b;
        cin >> a >> b;
        if (!mizera.create_union(a, b)) {
            auto path = mizera.get_path(a, b);
            cout << path.size() << endl;
            for (int x : path)
                cout << x << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
