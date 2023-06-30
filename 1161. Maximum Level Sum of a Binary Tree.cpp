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
    int max = INT_MIN;
    int maxLevel = 0;
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()){
            level++;
            vector <int> cur_level;
            int sum = 0;
            int len = q.size();
            for (int i = 0; i<len; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node){
                    sum += node->val;
                    if (node ->left){
                        q.push(node->left);
                    }
                    if (node->right){
                        q.push(node->right);
                    }
                }
            }
            if (sum > max){
                max = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};
