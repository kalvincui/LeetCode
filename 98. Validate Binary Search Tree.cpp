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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root, long left, long right){
        if (root == NULL){
            return true;
        }
        if (!(root->val > left && root->val < right)){
            return false;
        }
        return isValid(root->left, left, root->val) && isValid(root->right, root->val, right);
    }
};
