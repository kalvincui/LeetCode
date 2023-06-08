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

//Alternative solution, just keeping track of max value rather than entire path
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
    int goodNodes(TreeNode* root) {
        //Record path to every node? 
        //Find max element in path, if it is equal to current node, then it is a good node
        //DFS
        helper (root, root->val);
        return ans;
    }
    void helper (TreeNode* node, int maxval){
        if (node == NULL){
            return;
        }
        if (maxval <= node->val){
            ans++;
            maxval = node->val;
        }
        helper (node->left, maxval);
        helper (node->right, maxval);
    }
};
