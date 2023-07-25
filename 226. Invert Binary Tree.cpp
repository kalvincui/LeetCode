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
    TreeNode* invertTree(TreeNode* root) {
        //Invert Tree (replace root->left with root->right) (swapping the values essentially)
        //Base case:
        //If (root == NULL), return root
        //At end return root
        //Create temp node set equal to root->left
        //Set root->left = root->right
        //Set root->right = tempNode
        //Call invertTree (root->left)
        //Call invertTree (root->right)
        //return root (original at the end)
        if (!root){
            return root;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
