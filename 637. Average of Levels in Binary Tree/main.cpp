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

class Solution {
   public:
    vector<int> layerSum;
    vector<int> layerCnt;
    vector<double> answer;

    void dfs(int lr, TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        if (lr == layerSum.size()) {
            layerSum.push_back(node->val);
            layerCnt.push_back(1);
        } else if (lr < layerSum.size()) {
            layerSum[lr] += node->val;
            layerCnt[lr] += 1;
        } else {
            // 跳號爆了，但不知道 leetcode 要怎麼插入提示
            cout << "Error: layer record broken!" << endl;
            return;
        }

        if (node->left != nullptr) {
            dfs(lr + 1, node->left);
        }
        if (node->right != nullptr) {
            dfs(lr + 1, node->right);
        }

        return;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        // 因為此題並不是完全二元樹，因此不能用陣列快速反推層數
        // 需要事先遍歷一輪才能紀錄層數
        // 痾似乎也記錄不起來，因為我改不了題目給的 node struct
        // 我在使用 tree traverse 的時候，我也無法得知此節點是 root 陣列的第幾項
        // 好吧這似乎就是非完全二元樹的弊病，能做的很有限。
        dfs(0, root);
        // cout << "layerSum: " << layerSum.size() << endl;
        // cout << "layerCnt: " << layerCnt.size() << endl;
        for (int i = 0; i < layerSum.size(); i++) {
            answer.push_back((double)layerSum[i] / layerCnt[i]);
        }
        return answer;
    }
};

int main() {
    // 建立測試樹: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<double> result = sol.averageOfLevels(root);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}