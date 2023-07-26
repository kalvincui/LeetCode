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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Consists of unique values
        //Each value of inorder also appears in preorder
        //Preorder: Middle, Left, Right
        //Inorder: Most Left to Most Right
        //Idea: Root = First element in Pre-order
        //Left of root = first element
        //Root = second element of in order (mid)
        //Right = third element of inorder
        if (preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int splitidx = 0;
        for (int i = 0; i<inorder.size(); i++){
            if (inorder[i] == preorder[0]){
                splitidx = i;
                break;
            }
        }
        auto start = preorder.begin() + 1;
        auto end = preorder.begin() + splitidx+1;
        vector<int> preorderleft(splitidx);
        copy(start, end, preorderleft.begin());

        start = preorder.begin() + splitidx+1;
        end = preorder.end();
        vector<int> preorderright(preorder.size()-splitidx-1);
        copy(start, end, preorderright.begin());


        start = inorder.begin();
        end = inorder.begin() + splitidx;
        vector<int> inorderleft(splitidx);
        copy(start, end, inorderleft.begin());

        start = inorder.begin() + splitidx+1;
        end = inorder.end();
        vector<int> inorderright(inorder.size()-splitidx-1);
        copy(start, end, inorderright.begin());

        root->left = buildTree(preorderleft, inorderleft);
        root->right = buildTree(preorderright, inorderright);
        return root;
    }
};
