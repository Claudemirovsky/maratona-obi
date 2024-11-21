#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
  private:
    static const int capacity = 7243;
    vector<list<int>> buckets;

    int hash(int key) { return key % this->capacity; }

  public:
    MyHashSet() { this->buckets.resize(this->capacity); }

    inline void add(int key) {
        int hash = this->hash(key);
        if (this->contains(-hash))
            return;
        this->buckets[hash].push_back(key);
    }

    inline void remove(int key) {
        int hash = this->hash(key);
        list<int> &bucket = buckets[hash];
        if (bucket.empty())
            return;
        bucket.remove(key);
    }

    inline bool contains(int key) {
        int hash = key >= 0 ? this->hash(key) : -key;
        list<int> &bucket = buckets[hash];

        if (bucket.empty())
            return false;

        return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

int32_t main() {
    MyHashSet *h = new MyHashSet();
    h->add(1000000);
    h->contains(1000000);
    delete h;
    return 0;
}
