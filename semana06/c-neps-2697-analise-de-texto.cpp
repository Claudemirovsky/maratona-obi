#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;
    unordered_set<char> letters;
    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }
    for (char &ch : words.back())
        letters.insert(ch);
    words.pop_back();

    int count = 0;
    for (string &word : words) {
        for (char &ch : word) {
            if (letters.find(ch) != letters.end()) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}
