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
    //Root to leaf, a leaf is a node with no children
    bool res = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root){
            return res;
        }
        dfs(root, targetSum);
        return res;
    }
    void dfs(TreeNode* root, int targetSum){
        if (!root){
            return;
        }
        if (!root->left && !root->right){
            if (targetSum - root->val == 0){
                res = true;
            }
            return;
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
    }
};
