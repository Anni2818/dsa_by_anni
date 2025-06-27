// there will be no change in left sub tree
// we go in right subtree untill the value of node is less than the given val
// then we assign root to new node->left
// if we find null then just return new node


//a very good problm for understanding concept of traveral and keeping track pf the pointers

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* temp = root;
        if(val > root->val)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        else{
            while(temp->right && temp->right->val >= val)
            {
                temp = temp->right;
            }
            TreeNode* node = new TreeNode(val);
            node->left = temp->right;
            temp->right = node;
        }
        return root;
    }
};