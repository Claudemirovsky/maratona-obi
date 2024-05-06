#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> invalid;
        invalid.insert(deadends.begin(), deadends.end());
        queue<string> ihatetheantichrist;
        auto isInvalid = [&](string str) {
            return invalid.find(str) != invalid.end();
        };

        if (isInvalid(target))
            return -1;
        if (target == "0000")
            return 0;
        ihatetheantichrist.push("0000");

        int moves = 0;
        while (!ihatetheantichrist.empty()) {
            moves++;
            int items = ihatetheantichrist.size();
            while (items--) {
                string current = ihatetheantichrist.front();
                if (current == target)
                    return moves;
                ihatetheantichrist.pop();
                if (isInvalid(current))
                    continue;

                invalid.insert(current);

                for (int i = 0; i < 4; i++) {
                    char prev = current[i];
                    if (prev == '9')
                        current[i] = '0';
                    else
                        current[i]++;

                    if (!isInvalid(current)) {
                        if (current == target)
                            return moves;
                        ihatetheantichrist.push(current);
                    }
                    current[i] = prev;
                    if (prev == '0')
                        current[i] = '9';
                    else
                        current[i]--;
                    if (!isInvalid(current)) {
                        if (current == target)
                            return moves;
                        ihatetheantichrist.push(current);
                    }
                    current[i] = prev;
                }
            }
        }

        return -1;
    }
};
