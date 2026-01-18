#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 35. Search Insert Position
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        // 這題要求要回傳 index，因此無法用 set 或 map 解題
        // 因為它們的底層是由紅黑樹實現，而 *it 是無法反推 order 的
        // 可以直接用 lower bound 速解
        // 而 lbd 的底層是由二分搜去實現的，因此也可以手幹
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            // review: 二分搜尋法，期望能直接找到 target
            // 若找不到，則是找到 target 期望的位置，也就是比 target 大的那個 index
            // 最終態要是 left 先大於 target => left 優先級比 right 大
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return left;
    }

    int searchInsert2(vector<int>& nums, int target) {
        // review: 能隨機存取的容器才能 O(1) 用 it 反推得到 index, 如 vector, deque
        // distance 可以求兩個迭代器的距離，求與 begin 之差得 index
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), it);
    }
};