#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 909. Snakes and Ladders
// review: 909 正解在這裡
class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> map(n + 5, vector<int>(n + 5, 0));  // map[y][x]
        // vector<vector<int>> adj;              // adj[u][num] = v
        vector<int> adj((n + 5) * (n + 5), -1);  // adj[u] = v, one snack at most, 1-based indexing

        // init
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // board mapping
                if (i % 2 == 0) {
                    map[i][j] = n % 2 == 0 ? n * (n - i) - j : n * (n - i - 1) + j + 1;
                } else if (i % 2 == 1) {
                    map[i][j] = n % 2 == 0 ? n * (n - i - 1) + j + 1 : n * (n - i) - j;
                }
                // record snack
                if (board[i][j] != -1) {
                    adj[map[i][j]] = board[i][j];
                }
            }
        }

        // 肯定不能用貪婪演算法，假設有 15->35, 14->20 就有機會炸開了
        // 所以是要反著去推算？
        // 不對，應該是說要做 dp，計算路程並鬆弛。
        // 每次走路代價為 1，但可以決定走 1~6 距離
        // 所以應該是取前六項的最小值 +1

        // 忘記處理無解情形了...似乎還是要用 visited 去檢測是環？

        // 幹還要處理梯子不能連跳的問題...這要和回跳綁再一起考慮...

        // 你媽的這題用 BFS 就好了，根本不需要套顯式圖演算法跑舒張
        // 但使用的 queue 搞不好可以用自定義 priority queue 加速
        // => 在無權圖 BFS 中，第一個到達該點的就一定是最短路徑。
        // => 因此如果使用優先序列，反而會因為 logN 維護而降速

        // bfs
        vector<int> dist((n + 5) * (n + 5), INT_MAX);  // 1-based indexing
        queue<pair<int, int>> q;                       // place, step
        if (n == 2 && adj[3] == -1)
            return 1;
        else if (n == 2 && adj[3] != -1)
            return -1;

        q.push({1, 0});
        dist[1] = 0;
        while (!q.empty()) {
            int cur = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 1; i <= 6; i++) {
                int target = cur + i;
                if (target > n * n)
                    continue;

                // dice move
                if (adj[target] == -1) {
                    if (step + 1 < dist[target]) {
                        q.push({target, step + 1});
                        dist[target] = step + 1;
                    }
                }
                // climb snake/ladder
                else {
                    if (step + 1 < dist[adj[target]]) {
                        q.push({adj[target], step + 1});
                        dist[adj[target]] = step + 1;
                    }
                }
            }
        }
        return dist[n * n] == INT_MAX ? -1 : dist[n * n];
    };
};

int main() {
    Solution sol;
    vector<vector<int>> board6 = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                                  {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    // 給我一個 5*5 的 board2
    vector<vector<int>> board5 = {{2, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}};
    // [[-1,1,2,-1],[2,13,15,-1],[-1,10,-1,-1],[-1,6,2,8]]
    vector<vector<int>> board4 = {{-1, 1, 2, -1}, {2, 13, 15, -1}, {-1, 10, -1, -1}, {-1, 6, 2, 8}};
    // [[-1,-1,-1],[-1,9,8],[-1,8,9]]
    vector<vector<int>> board3 = {{-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};
    cout << sol.snakesAndLadders(board6);
}