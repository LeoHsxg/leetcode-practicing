#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 198. House Robber
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // begin from 0 or 1
        vector<int> dp(n + 5, -1);
        queue<int> q;
        dp[0] = nums[0];
        dp[1] = nums[1];
        q.push(0);
        q.push(1);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 2; i <= 3; i++) {
                int nxt = cur + i;
                if (nxt >= n)
                    continue;
                int nxtMon = dp[cur] + nums[nxt];
                if (nxtMon > dp[nxt]) {
                    q.push(nxt);
                    dp[nxt] = nxtMon;
                }
            }
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums);
}