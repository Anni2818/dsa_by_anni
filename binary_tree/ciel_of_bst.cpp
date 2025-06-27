// ciel is the least valued noe which is >= given input
// there are several subtleties in the code which you need to understand 


/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int helper(Node* root, int &ans,int input)
{
    if(root == NULL) return ans; // here we have to return ans because if we hit null after finding the ans then -1 gets returned
    if(root->data == input) return input;
    if(root->data > input) 
    {
        ans = root->data;
        return helper(root->left,ans,input); // return statement is necessary
    }
    else{
        return helper(root->right,ans,input);// return statement is necessary
    }
    return ans;
}

int findCeil(Node* root, int input) {
    // Your code here
    int ans=-1;
    return helper(root,ans,input);
    
}