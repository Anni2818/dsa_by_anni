#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* lc;
    Node* rc;
    Node(int val){
        data = val;
        lc = rc = NULL;
    }

// friend function createtree();
};

// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
//returns root node of created tree
Node* createtree()
{
    int val;
    cout<<endl;
    // cout<<"Enter data : ";
    cin>>val; 
    if(val == -1){
        return NULL;
    }
    //maz kam node tayar karane
    Node* newnode = new Node(val);
    //left subtree
    // cout<<"data for lc of "<<newnode->data<<" : ";
    newnode->lc = createtree();
    //right subtree
    // cout<<"data for rc of "<<newnode->data<<" : ";
    newnode->rc = createtree();

    return newnode;
}

//you can perform all traversals in similar fashion as below : 
void preorder(Node* root)
{
    if(root == NULL) return;
    
    preorder(root->lc);
    cout<<root->data<<" ";
    preorder(root->rc);
}

void postorder(Node* root)
{
    if(root == NULL) return;
    postorder(root->lc);
    postorder(root->rc);
    cout<<root->data<<" ";
}

//its nothing but BFS
void lvlorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front != NULL){
            cout<<front->data<<" ";
            if(front->lc != NULL){
                q.push(front->lc);
            }
            if(front->rc != NULL){
                q.push(front->rc);
            }
        }

        else{
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
    }
}

//--------------height-------------
int height(Node* root)
{
    //base case : null ale tar +1 height madhe
    if(root == NULL) return 0;
    int l = height(root->lc);
    int r = height(root->rc);

    return max(l,r) + 1; 
}

//--------------diameter---------------
int diameter(Node*root)
{
    if(root == NULL) return 0;
    int l = height(root->lc);
    int r = height(root->rc);

    return l+r;
}

bool hbalanced(Node* root,int &height)
{
        
    if(root == NULL) height =0; return true;

    int lheight =0;
    int rheight =0;

    bool ls = hbalanced(root->lc,lheight);
    bool rs = hbalanced(root->rc,rheight);

    height = 1+max(lheight, rheight);

    bool node = abs(ls-rs) <= 1;
    return ls && rs && node;
}
//============= finding the kth ancestor of a node=========

void helper(Node* root,int val,int k,stack<int>&s,int &ans)
{
    if(root == NULL) return;
    s.push(root->data);
    if(root->data == val){
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        if(!s.empty()) ans = s.top();
        return;
    }
    helper(root->lc,val,k,s,ans);
    helper(root->rc,val,k,s,ans);
    s.pop();
}

void kthAncestor(Node*root,int val, int k)
{
    int ans=0;
    stack<int>s;
    helper(root,val,k,s,ans);
    cout<<ans;
}


//=============== leftview of tree===========
void printLeft(Node* root, int lvl, vector<int>& lview)
{
    if(root == NULL) return;

    if(lvl == lview.size()){
        lview.push_back(root->data);
    }
    printLeft(root->lc, lvl+1, lview);
    printLeft(root->rc, lvl+1, lview);
}

void printRight(Node* root, int lvl, vector<int>& rview)
{
    if(root == NULL) return;

    if(lvl == rview.size()){
        rview.push_back(root->data);
    }
    printRight(root->rc, lvl+1, rview);
    printRight(root->lc, lvl+1, rview);
}


//================ top view ====================
void printTop(Node* root,vector<int> &tview)
{
    map<int,int>hdmap;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> temp= q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(hdmap.find(hd) == hdmap.end()){
            hdmap[hd] = frontNode->data;
        }
        if(frontNode->lc != NULL){
            q.push(make_pair(frontNode->lc, hd-1));
        }
        if(frontNode->rc != NULL){
            q.push(make_pair(frontNode->rc, hd+1));
        }
    }

    for(auto i : hdmap){
        tview.push_back(i.second);
    }
}
//==========bottom view sathi fakt if condition kadhun taka value overwrite houdet=========
// if(hdmap.find(hd) == hdmap.end()){
//             hdmap[hd] = frontNode->data;
//         }

//==================== transform to sum tree ================
int lrsum(Node *root)
{
    if (root == NULL)
        return 0;

    int lsum = lrsum(root->lc);
    int rsum = lrsum(root->rc);

    return root->data + lsum + rsum;
}
   
int main()
{
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    Node* root = createtree();
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // lvlorder(root);
    // cout<<endl;
    // cout<<height(root)<<endl;
    // cout<<diameter(root)<<endl;
    // cout<<"balacnced ?";
    // cout<<hbalanced(root)<<endl;
    // kthAncestor(root,7,1);
    // int lvl =0;
    // vector<int> tview;
    // printTop(root,tview);
    // for(int i=0; i<tview.size(); i++){
    //     cout<<tview[i] <<" ";
    // }

    cout<<lrsum(root);
    return 0;
}