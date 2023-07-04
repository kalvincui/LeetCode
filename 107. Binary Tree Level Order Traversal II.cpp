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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack <vector<int>> s;
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        if (root){
            q.push(root);
            while (!q.empty()){
                int len = q.size();
                vector <int> curlevelvalues;
                for (int i = 0; i<len; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    curlevelvalues.push_back(cur->val);
                    if (cur->left){
                        q.push(cur->left);
                    }
                    if (cur->right){
                        q.push(cur->right);
                    }
                }
                s.push(curlevelvalues);
            }
            while (!s.empty()){
                vector<int> cur = s.top();
                s.pop();
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
