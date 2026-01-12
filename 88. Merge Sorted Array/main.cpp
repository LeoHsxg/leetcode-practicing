#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        if (nums1.empty() || nums2.empty()) {
            nums1 = nums1.empty() ? nums2 : nums1;
            return;
        }
        for (int i = 0, j = 0; i < m || j < n;) {
            if (j >= n) {
                ans.push_back(nums1[i]);
                i++;
                continue;
            } else if (i >= m) {
                ans.push_back(nums2[j]);
                j++;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = ans;
        return;
    }
};