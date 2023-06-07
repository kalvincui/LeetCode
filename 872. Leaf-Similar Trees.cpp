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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> root1values;
        vector <int> root2values;
        traverse (root1, root1values);
        traverse (root2, root2values);
        return (root1values == root2values);
    }
    void traverse (TreeNode* node, vector<int>& leafvalues){
        if (node == NULL){
            return;
        }
        if (node->left == NULL && node->right == NULL){
            leafvalues.push_back(node->val);
            return;
        }
        traverse(node->left, leafvalues);
        traverse(node->right, leafvalues);
    }
};
