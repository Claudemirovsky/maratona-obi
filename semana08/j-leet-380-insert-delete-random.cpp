#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> numbers;
    vector<int> random;
    int randlim = 0;

  public:
    RandomizedSet() {}

    bool insert(int val) {
        if (numbers.find(val) == numbers.end()) {
            if (numbers.size() >= random.size()) {
                numbers[val] = random.size();
                random.push_back(val);
                randlim = random.size();
            } else {
                numbers[val] = randlim;
                random[randlim++] = val;
            }
            return true;
        }

        return false;
    }

    bool remove(int val) {
        if (numbers.find(val) != numbers.end()) {
            int idrem = numbers[val];
            int idlast = random[randlim - 1];
            numbers[idlast] = idrem;
            random[idrem] = idlast;
            randlim--;
            numbers.erase(val);
            return true;
        }

        return false;
    }

    int getRandom() { return random[rand() % randlim]; }
};

int main() {
    RandomizedSet *rand = new RandomizedSet();
    rand->insert(1);
    rand->insert(20);
    rand->insert(30);
    rand->insert(10);

    for (int i = 0; i < 20; ++i) {
        cout << i + 1 << ") -> " << rand->getRandom() << endl;
    }

    delete rand;
}
