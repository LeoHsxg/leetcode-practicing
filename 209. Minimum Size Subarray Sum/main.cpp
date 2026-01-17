#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// 209. Minimum Size Subarray Sum
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 求大於 target 的最短子集合，好拗口
        // 挖操？sliding window 的核心似乎是：不滿足需求就加長，滿足了就縮短
        // review: queue 是用 front 跟 back 進行操作
        queue<int> q;
        int sum = 0;
        int ansCnt = 100005;

        for (int num : nums) {
            if (sum < target) {
                q.push(num);
                sum += num;
            }
            /// 這裡不能用 else!
            while (sum >= target) {
                // save
                if (q.size() < ansCnt)
                    ansCnt = q.size();
                // pop
                int tmp = q.front();
                q.pop();
                sum -= tmp;
            }
        }
        if (ansCnt == 100005)
            return 0;
        return ansCnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums);
}