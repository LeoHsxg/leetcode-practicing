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

// 53. Maximum Subarray
// review: Kadane's Algorithm
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int cur_max = nums[0];
        int max_all = nums[0];
        // for (int n : nums) {
        for (int i = 1; i < nums.size(); i++) {
            cur_max = max(cur_max + nums[i], nums[i]);
            max_all = max(cur_max, max_all);
        }
        return max_all;
    }
};