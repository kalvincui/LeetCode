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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper (root, targetSum, path);
        return ans;
    }
    void helper (TreeNode* node, int targetSum, vector<int> path){
        if (node == NULL){
            return;
        }
        path.push_back(node->val);
        long sum = 0;
        for (int i = path.size()-1; i>=0; i--){
            sum += path[i];
            if (sum == targetSum){
                ans++;
            }
        }
        helper (node->left, targetSum, path);
        helper (node->right, targetSum, path);
    }
};


//Alternative Solution
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
