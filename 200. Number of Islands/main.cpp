#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int m = 0;
    int n = 0;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    vector<vector<int>> vis;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islandCnt = 0;
        vis = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] != 0 || grid[i][j] == '0')
                    continue;
                // vis[i][j] = 1;
                islandCnt += 1;
                recursion(i, j, grid);
            }
        }

        return islandCnt;
    }

    void recursion(int a, int b, vector<vector<char>>& grid) {
        if (a < 0 || b < 0 || a >= m || b >= n)
            return;
        if (grid[a][b] != '1')
            return;
        if (vis[a][b] != 0)
            return;

        vis[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            recursion(a + dy[i], b + dx[i], grid);
        }
    }
};