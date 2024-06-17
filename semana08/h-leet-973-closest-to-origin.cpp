#include <bits/stdc++.h>

using namespace std;

inline int dist(vector<int> &x) { return ((x[0] * x[0]) + (x[1] * x[1])); }

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b) { return dist(a) < dist(b); });

        vector<vector<int>> res(points.begin(), points.begin() + k);
        return res;
    }
};
