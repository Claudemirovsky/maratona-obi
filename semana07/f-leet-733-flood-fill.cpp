#include <bits/stdc++.h>

using namespace std;

const int mx[] = {1, -1, 0, 0};
const int my[] = {0, 0, 1, -1};
class Solution {
  public:
    void transverse(vector<vector<int>> &grid, int limitX, int limitY, int x,
                    int y, int orig, int target) {
        if (grid[x][y] != orig || grid[x][y] == target)
            return;
        grid[x][y] = target;

        for (int i = 0; i < 4; i++) {
            int cx = x + mx[i];
            int cy = y + my[i];
            if (cx >= 0 && cx < limitX && cy >= 0 && cy < limitY)
                transverse(grid, limitX, limitY, cx, cy, orig, target);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        transverse(image, image.size(), image[0].size(), sr, sc, image[sr][sc],
                   color);

        return image;
    }
};
