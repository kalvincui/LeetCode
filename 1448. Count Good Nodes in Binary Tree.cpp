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
    int goodNodes(TreeNode* root) {
        //Record path to every node? 
        //Find max element in path, if it is equal to current node, then it is a good node
        //DFS
        vector <int> path;
        int ans = 0;
        helper (root, path, ans);
        return ans;
    }
    void helper (TreeNode* node, vector<int> path, int& ans){
        if (node == NULL){
            return;
        }
        path.push_back(node->val);
        auto maxvalitr = max_element(std::begin(path), std::end(path));
        if (*maxvalitr == node->val){
            ans++;
        }
        helper (node->left, path, ans);
        helper (node->right, path, ans);
        return;
    }
};
