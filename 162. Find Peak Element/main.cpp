#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 162. Find Peak Element
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int left = 1;
        int right = n - 2;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            // review: Binary Search 是當前這區段不行時，直接捨棄，取另一邊
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else if (nums[mid] < nums[mid - 1])
                right = mid - 1;
        }
        return -1;
    }
};