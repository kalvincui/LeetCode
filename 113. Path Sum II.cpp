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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }
    void dfs(TreeNode* root, int targetSum, vector<int> path){
        if (!root){
            return;
        }
        if (!root->left && !root->right){
            if (targetSum - root->val == 0){
                path.push_back(root->val);
                res.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, targetSum-root->val, path);
        dfs(root->right, targetSum-root->val, path);
    }
};
