#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 909. Snakes and Ladders
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
                    map[i][j] = n * (n - i) - j;
                } else if (i % 2 == 1) {
                    map[i][j] = n * (n - i - 1) + j + 1;
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

        // dp & relaxing
        vector<int> dist((n + 5) * (n + 5), INT_MAX);  // 1-based indexing
        vector<bool> isJump((n + 5) * (n + 5), false);
        if (n == 2)
            return 1;
        for (int i = 1; i < 7; i++) {
            dist[i] = 1;
            if (adj[i] != -1) {
                dist[adj[i]] = 1;
                if (adj[i] < i)
                    dist[i] = INT_MAX;
            }
        }
        for (int i = 6; i <= n * n; i++) {
            // review: c++ min() 在多參數比較時，需要用 {} 包成 list 的方式傳入;
            // review: 在做 dp 或鬆弛時，要注意把原始數值丟進去比較;
            int minDist = min({dist[i - 1], dist[i - 2], dist[i - 3], dist[i - 4], dist[i - 5], dist[i - 6]}) + 1;
            // 這裡有更新也要處理啦啦啦
            dist[i] = min(dist[i], minDist);

            // 爬梯子
            if (adj[i] != -1) {
                if (dist[adj[i]] <= dist[i])
                    continue;
                // 確認紀錄此格跳格子
                int minDist = min(dist[i], dist[i]);  // 把原本的 dist[i] 也放進去比較
                // 如果被迫回跳，就設為無限大。還是說要有更新時再改狀態？
                isJump[adj[i]] = true;
                dist[adj[i]] = minDist;
                if (adj[i] < i)
                    dist[i] = INT_MAX;
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
    vector<vector<int>> board5 = {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, 19, -1, -1, -1}, {25, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}};
    // [[-1,1,2,-1],[2,13,15,-1],[-1,10,-1,-1],[-1,6,2,8]]
    vector<vector<int>> board4 = {{-1, 1, 2, -1}, {2, 13, 15, -1}, {-1, 10, -1, -1}, {-1, 6, 2, 8}};
    // [[-1,-1,-1],[-1,9,8],[-1,8,9]]
    vector<vector<int>> board3 = {{-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};
    cout << sol.snakesAndLadders(board4);
}