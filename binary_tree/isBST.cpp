// just intution is nes=cessary
// focous and think

class Solution {
public:

    bool solve(TreeNode* root,long mini, long maxi)
    {
        if(root == NULL) return true;
        if(root->val >=maxi || root->val <= mini) return false;
        return solve(root->left, mini,root->val) && solve(root->right,root->val,maxi);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};