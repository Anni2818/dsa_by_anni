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

    void solve(TreeNode* root, int targetSum, int sum, vector<int> temp,vector<vector<int>>&fans)
    {
        //base case null alyavr kahich nahi karaych be
        if(root== NULL) return ;
        sum += root->val;
        temp.push_back(root->val);
        if(root->right == NULL && root->left == NULL){
            // verify kara
            if(sum == targetSum){
                fans.push_back(temp);
            }
            else{
                return;
            }
        }

        //ata left and right subtree che ans kadha
        solve(root->left,targetSum, sum,temp,fans);
        solve(root->right,targetSum, sum,temp,fans);
      
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> fans;
        vector<int> temp;
        int sum =0;
        solve(root,targetSum, sum,temp,fans);
        return fans;
    }
};