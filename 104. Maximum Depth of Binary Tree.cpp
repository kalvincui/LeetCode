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
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
    int helper (TreeNode* node, int counter){
        if (node == NULL){
            return counter;
        }
        int left = helper (node->left, counter+1);
        int right = helper (node->right, counter+1);
        return max(left, right);
    }
};


//Iterative BFS
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
    int maxDepth(TreeNode* root) {
        int longest = 0;
        if (root){
            queue <TreeNode*> q;
            q.push(root);
            while (!q.empty()){
                int size = q.size();
                for (int i = 0; i<size; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    if (cur->left){
                        q.push(cur->left);
                    }
                    if (cur->right){
                        q.push(cur->right);
                    }
                }
                longest++;
            }
        }
        return longest;
    }
};



//Short and Simple DFS
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
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
