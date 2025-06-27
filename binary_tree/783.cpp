//just finding inorder and ir=terating over the array

class Solution {
public:

    int mini(vector<int>nums)
    {
        int diff =INT_MAX;
        for(int i=0;i<nums.size()-1;i++)
        {
            diff = min(diff,abs(nums[i]-nums[i+1]));
        }
        return diff;
    }

    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>res;
        inorder(root,res);
        return mini(res);
    }
};