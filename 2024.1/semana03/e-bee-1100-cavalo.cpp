#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

bool isInvalid(char x) { return x > 'h' || x < '1' || (x > '8' && x < 'a'); }

int getMoves(string source, string target) {
    if (source == target) {
        return 0;
    }
    queue<string> lequeue;
    unordered_set<string> visited;
    auto hasVisited = [&](string str) {
        return visited.find(str) != visited.end();
    };
    lequeue.push(source);

    int moves = 0;
    vector<pair<char, char>> movmap = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                       {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    while (!lequeue.empty()) {
        moves++;
        int count = lequeue.size();
        while (count--) {
            string current = lequeue.front();

            lequeue.pop();
            if (hasVisited(current))
                continue;
            visited.insert(current);

            for (pair<char, char> &p : movmap) {
                string n = current;
                n[0] += p.first;
                n[1] += p.second;
                if (!isInvalid(n[0]) && !isInvalid(n[1])) {
                    if (n == target)
                        return moves;
                    lequeue.push(n);
                }
            }
        }
    }

    return moves;
}

int main() {
    FASTIO;
    string source, target;
    while (cin >> source) {
        cin >> target;
        cout << "To get from " << source << " to " << target << " takes "
             << getMoves(source, target) << " knight moves." << endl;
    }
    return 0;
}
