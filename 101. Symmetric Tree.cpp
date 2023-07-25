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
    bool isSymmetric(TreeNode* root) {
        //Idea: Use recursion?
        //Split into subtrees (root->left && root->right)
        //root->left->left == root->right->right
        //root->left->right == root->right->right
        //Can do recursively
        //Return true if left == NULL == right
        //Return false if left || right == NULL
        //Return false if left->val != right->val
        //Return left->left, right->right && left->right, right->left
        if (root == NULL){
            return true;
        }
        return checkSymmetric(root->left, root->right);
    }
    bool checkSymmetric (TreeNode* left, TreeNode* right){
        if (left == NULL && right == NULL){
            return true;
        }
        if (!left || !right){
            return false;
        }
        if (left->val != right->val){
            return false;
        }
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
};
