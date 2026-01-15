#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    struct Point {
        int x, y, dist;
    };
    // 比較器：距離小的優先 (Min-Heap)
    struct CompareDist {
        bool operator()(Point const& p1, Point const& p2) {
            // review: priority_queue 的比較邏輯是反的，
            // 假設 true 就把東西往後丟，跟 c 的 qsort 同套模式
            return p1.dist > p2.dist;
        }
    };
    priority_queue<Point, vector<Point>, CompareDist> pq_point;

    // ------------------------------------------------

    struct comp {
        bool operator()(int const& a, int const& b) { return b > a; }
    };
    priority_queue<int, vector<int>, comp> pq_diy;

    // ------------------------------------------------

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        // review: queue didn't have front() function, use top() instead
        return pq.top();
    }
};