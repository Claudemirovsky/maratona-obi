#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;
    int desc, parti, maxlvl = 0;
    cin >> desc >> parti;
    unordered_map<int, unordered_set<int>> total;
    unordered_map<int, int> generations;

    for (int i = 1; i <= desc; i++) {
        int a;
        cin >> a;
        total[a].insert(i);
    }

    vector<int> totaldesc(parti, 0);

    stack<pair<int, int>> st;
    st.push({0, 0});

    while (!st.empty()) {
        auto [idx, gen] = st.top();
        st.pop();
        generations[idx] = gen;
        if (total.find(idx) != total.end()) {
            totaldesc[gen] += total[idx].size();
            gen++;
            maxlvl = max(maxlvl, gen);
            for (int i : total[idx]) {
                st.push({i, gen});
            }
        }
    }

    vector<int> attended(parti, 0);

    for (int i = 0; i < parti; i++) {
        int x;
        cin >> x;
        attended[generations[x] - 1]++;
    }

    for (int i = 0; i < maxlvl; i++)
        printf("%.2f ", ((float)attended[i] / totaldesc[i]) * 100);
    return 0;
}
