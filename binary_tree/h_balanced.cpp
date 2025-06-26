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

    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1+ max(height(root->right),height(root->left));
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(rh-lh)>1) return false;

        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        return true;
    }
};