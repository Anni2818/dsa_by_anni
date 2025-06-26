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
    bool solve(TreeNode* root,int target,int pathsum)
    {
        if(root == NULL) return false;
        pathsum += root->val;
        if(!root->left && !root->right) return pathsum == target;
        bool lans = solve(root->left,target,pathsum);
        bool rans = solve(root->right,target,pathsum);

        return lans || rans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int s=0;
        return solve(root,targetSum,s);

    }
};