// a really good exaple to use structs, rather an implementation of postorder traversal

class Solution {
  public:
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    
        Info(bool isBST, int size, int minVal, int maxVal)
            : isBST(isBST), size(size), minVal(minVal), maxVal(maxVal) {}
    };

    
    Info helper(Node*root, int &maxSize)
    {
        if(root == NULL){
            return Info(true,0,INT_MAX,INT_MIN);
        }
        //here we implement post order hence recursion for L and R first
        Info lans = helper(root->left,maxSize);
        Info rans = helper(root->right,maxSize);
        
        //now comes the part of node processing
        // 1. check whether left and right subtrees are bst or not
        //      this is done by checking isBst function and leftMax < node < rightMin..
        if(lans.isBST && rans.isBST && root->data > lans.maxVal && root->data < rans.minVal)
        {
            int curr_size = lans.size + rans.size + 1;
            maxSize = max(maxSize,curr_size);
            
            return Info(
                true,
                curr_size,
                min(root->data,lans.minVal),
                max(root->data,rans.maxVal));
        }
        
        //if not bst return info accordingly
        return Info(false,max(lans.size,rans.size),0,0);
    }
    
    int largestBst(Node *root) {
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
    }
};