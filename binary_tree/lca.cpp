/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    //here we are using NLR preorder traversal
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //-- processing current node (N)
        if(root == NULL) return NULL;

        if(root == p) return p;
        if(root == q) return q;

        //-- processing the left node (L)
        TreeNode* lans = lowestCommonAncestor(root->left,p,q);

        //-- processing the right node (R)
        TreeNode* rans = lowestCommonAncestor(root->right,p,q);

        //now perform as per the value is returned from lans and rans
        if(rans == NULL && lans == NULL) return NULL;
        else if(rans == NULL && lans !=NULL) return lans;
        else if(rans != NULL && lans ==NULL) return rans;
        else return root;
    }
};