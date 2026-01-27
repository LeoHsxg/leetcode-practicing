#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 918. Maximum Sum Circular Subarray
// review: Circular Subarray
/*
    在求解環形陣列時，最大和只有兩種可能的情況：
    A. 最大和不跨越邊界。這就是標準的 Kadane 問題。
    B. 最大和跨越了邊界（頭尾相連）。這代表中間有一段「連續的子陣列」被捨棄了。
    ---
    逆向思考：如果最大子陣列跨越了頭尾，那麼中間沒被選中的部分，就是最小的連續子陣列
    一條陣列肯定是 最大合陣列 + 最小合陣列，而兩個陣列一定會有一個被分成前後兩段。
    而 Kadane 只能求一條直線，所以要馬假設 最大合 是連續的，要馬假設 最小合 是連續的
    ---
    因此，環形陣列的最大和就是下面兩者的最大值：
    標準 Kadane：找最大子陣列和（max_sum）。
    逆向 Kadane：用「總和」減去「最小子陣列和」（total_sum - min_sum）。
 */
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max = nums[0];
        int max_all = nums[0];
        int cur_cnt = 1;
        int max_cnt = 1;
        int round = 0;
        // for (int n : nums) {
        for (int i = 1; i <= nums.size() && round < 2; i++) {
            // 邊界
            if (i == nums.size()) {
                round++;
                i = 0;
                continue;
            }
            // 完蛋啦，因為有限制長度，所以直接給他跑兩圈的做法不可行...
            // 假設 1~n 的解很優，他不會判斷與放棄現有解去求解 2~n+2 組
            if (cur_cnt > nums.size()) {
                break;
            }
            // 處理
            // cur_max = max(cur_max + nums[i], nums[i]); 拆成兩行
            if (cur_max >= 0) {
                cur_max = cur_max + nums[i];
                cur_cnt++;
            } else {
                cur_max = nums[i];
                cur_cnt = 0;
            }
            if (cur_max >= max_all) {
                max_all = cur_max;
                cur_cnt++;
                max_cnt = max(max_cnt, cur_cnt);
            }
        }
        return max_all;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, -3, 5};
    cout << sol.maxSubarraySumCircular(nums);
}