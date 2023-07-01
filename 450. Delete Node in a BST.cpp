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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Find node to delete, if node has no children, just delete it
        //If node has 1 child, replace the node connection with that child and delete the node
        //If node has 2 children, replace the node connection with the biggest value of the child on the left, then delete that leaf node 
        //ensuring you don't have to reorganize the tree too much
        if (root){
            if (key < root->val){
                root->left = deleteNode(root->left, key);
            }else if (key > root->val){
                root->right = deleteNode(root->right, key);
            }else {
                //2 children
                if (root->left && root->right){
                    TreeNode* temp = root->left;
                    while (temp->right != NULL){
                        temp = temp->right;
                    }
                    root->val = temp->val;
                    root->left = deleteNode(root->left, temp->val);
                }
                //1 Children
                else if (root->left){
                    return root->left;
                }
                else if (root->right){
                    return root->right;
                //No children
                }else {
                    return NULL;
                }
            }
        }
        return root;
    }
};
