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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root){
            if (root->val == val){
                return root;
            }
            if (val < root->val){
                return searchBST(root->left, val);
            }else if (val > root ->val){
                return searchBST(root->right, val);
            }else {
                return NULL;
            }
        }else {
            return root;
        }
    }
};



class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root){
            if (root->val < val){
                root = searchBST(root->right, val);
            }else if (root->val > val){
                root = searchBST(root->left, val);
            }
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root){
            if (root->val < val){
                return searchBST(root->right, val);
            }else if (root->val > val){
                return searchBST(root->left, val);
            }
        }
        return root;
    }
};
