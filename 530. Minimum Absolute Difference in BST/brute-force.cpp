#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// 530. Minimum Absolute Difference in BST
// 這東西是 BST，實際性質上就是排序過的陣列，可以直接取得最小差值
class Solution {
   public:
    vector<int> arr;
    void dfs(int lr, TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // review: vector 沒有 append()/push()，用 push_back()
        // append() ：python 的 list, c++ 的 string 有這個方法
        // 補充：vector 的 insert() 是插入到指定位置「之前」，
        // 第二個參數以後可以用多個元素或者是範圍 (其時間複雜度極高)
        arr.push_back(node->val);

        if (node->left != nullptr) {
            dfs(lr + 1, node->left);
        }
        if (node->right != nullptr) {
            dfs(lr + 1, node->right);
        }
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(0, root);
        sort(arr.begin(), arr.end());
        // cout << "arr size: " << arr.size() << endl;
        // cout << "arr: ";
        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        int ans = 1000000;
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) < ans)
                ans = abs(arr[i] - arr[i - 1]);
        }
        return ans;
    }
};

int main() {
    // 建立測試樹: [543,384,652,null,445,null,699]
    TreeNode* root = new TreeNode(543);
    root->left = new TreeNode(384);
    root->right = new TreeNode(652);
    root->left->right = new TreeNode(445);
    root->right->right = new TreeNode(699);

    Solution sol;
    int result = sol.getMinimumDifference(root);

    cout << result << endl;

    return 0;
}