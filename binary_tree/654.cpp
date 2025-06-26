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

    TreeNode* helper(vector<int>&nums, int start,int end)
    {

        //the base case is where we hit no element in a subarray. We return nullptr
        if(start > end) return NULL;
        int maxIndex = start;

        //find max element in the subarray
        for(int i=start;i<=end;i++)
        {
            if(nums[i]>nums[maxIndex]) maxIndex = i;
        }

        //create a node of current element
        TreeNode* node = new TreeNode(nums[maxIndex]);

        node->left = helper(nums,start,maxIndex-1);
        node->right = helper(nums,maxIndex+1,end);

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int end = nums.size()-1;
        int start = 0;
        return helper(nums,start,end);
    }
};