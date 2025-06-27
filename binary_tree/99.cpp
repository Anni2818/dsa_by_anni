// a very beautifull usecase for the inorder traversal
// if we find any anamoly in inorder traversal then we note them and perform swap at the end
// the way we decide which nodes are anamolies is also very instructive

class Solution {
public:

    void inorder(TreeNode* root,vector<TreeNode*>&v)
    {
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root,v);
        TreeNode* temp1=NULL;
        TreeNode* temp2=NULL;
        for(int i=0;i<v.size()-1;i++)
        {
            if (v[i]->val > v[i + 1]->val) {
                if (temp1 == NULL) {
                    // First anomaly
                    temp1 = v[i];
                    temp2 = v[i + 1];
                } else {
                    // Second anomaly (non-adjacent swap)
                    temp2 = v[i + 1];
                }
            }
        }
        swap(temp1->val,temp2->val);
    }
};