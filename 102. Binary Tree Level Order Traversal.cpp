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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> level;
            int length = q.size();
            for (int i = 0; i<length; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node){
                    level.push_back(node->val);
                    if (node->left){
                        q.push(node->left);
                    }
                    if (node->right){
                        q.push(node->right);
                    }
                }
            }
            if (!level.empty()){
                ans.push_back(level);
            }
        }
        return ans;
    }
};
