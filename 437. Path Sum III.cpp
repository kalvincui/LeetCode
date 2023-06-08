/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper (root, targetSum, path);
        return ans;
    }
    void helper (TreeNode* node, int targetSum, vector<int> path){
        if (node == NULL){
            return;
        }
        path.push_back(node->val);
        long sum = 0;
        for (int i = path.size()-1; i>=0; i--){
            sum += path[i];
            if (sum == targetSum){
                ans++;
            }
        }
        helper (node->left, targetSum, path);
        helper (node->right, targetSum, path);
    }
};
