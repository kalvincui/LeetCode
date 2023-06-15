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
    int longestZigZag(TreeNode* root) {
        helper (root, 0, true);
        helper (root, 0, false);
        return ans;
    }
    void helper(TreeNode* node, int counter, bool dir){
        if (node == NULL){
            ans = max(ans, counter-1);
            return;
        }
        counter++;
        if (dir){
            helper(node->right, counter, !dir);
            helper (node->right, 0, dir);
        }else {
            helper(node->left, counter, !dir);
            helper(node->left, 0, dir);
        }
    }
};
