#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 沒說不能用 sort 啊，不用自負手腳，直接兩個合併就可以直接 sort 了

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        sort(nums1.begin(), nums1.end());
    }
};

// python
// nums1[m:] = nums2
// nums1.sort()