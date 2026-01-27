#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> flat;
        // find 實際上是 O(m*n)，不符合需求，請乖乖做 Binary Search
        // => 兩種方法: 壓平和座標轉換
        int left = 0, right = m * n - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int mid_y = mid / n;
            int mid_x = mid % n;
            if (matrix[mid_y][mid_x] == target) {
                return true;
            } else if (matrix[mid_y][mid_x] < target) {
                left = mid + 1;
            } else if (matrix[mid_y][mid_x] > target) {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> flat;
        flat.reserve(m * n);
        for (auto mat : matrix) {
            // review: push_back 只能推單個元素，多元素要用 insert(位置, 插入起點, 插入終點)
            flat.insert(flat.end(), mat.begin(), mat.end());
        }
        return find(flat.begin(), flat.end(), target) != flat.end();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}};
    int target = 8;
    cout << sol.searchMatrix(matrix, target);
}