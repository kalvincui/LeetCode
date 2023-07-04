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
    int minDepth(TreeNode* root) {
        int level = 0;
        if (root){
            queue <TreeNode*> q;
            q.push(root);
            while (!q.empty()){
                int len = q.size();
                for (int i = 0; i<len; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    if (!cur->left && !cur->right){
                        return level+1;
                    }
                    if (cur->left){
                        q.push(cur->left);
                    }
                    if (cur->right){
                        q.push(cur->right);
                    }
                }
                level++;
            }
        }
        return level;
    }
};
