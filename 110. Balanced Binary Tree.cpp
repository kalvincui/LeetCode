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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        checkBalanced(root);
        return res;
    }
    int checkBalanced(TreeNode* root){
        if (!root){
            return 0;
        }
        int leftSubTree = checkBalanced(root->left);
        int rightSubTree = checkBalanced(root->right);
        if (abs(leftSubTree - rightSubTree) > 1){
            res = false;
        }
        return 1+max(leftSubTree, rightSubTree);
    }
};
