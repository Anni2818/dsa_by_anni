// this is very much similar to ciel of the bst just couple of changes in the operators

// Function to search a node in BST.
class Solution {

  public:
  
    int helper(Node* root,int &ans, int x)
    {
        if(root == NULL) return ans;
        if(root->data == x) return x;
        if(root->data > x)
        {
            return helper(root->left,ans,x);
        }
        else{
            ans = root->data;
            return helper(root->right,ans,x);
        }
        return ans;
    }
  
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        return helper(root,ans,x);
    }
};