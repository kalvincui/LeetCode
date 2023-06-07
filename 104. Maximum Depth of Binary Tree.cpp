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
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
    int helper (TreeNode* node, int counter){
        if (node == NULL){
            return counter;
        }
        int left = helper (node->left, counter+1);
        int right = helper (node->right, counter+1);
        return max(left, right);
    }
};
