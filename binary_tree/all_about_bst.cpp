#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* rc;
    Node* lc;

    Node(int d) {
        val = d;
        lc = NULL;
        rc = NULL;
    }
};

Node* insertBST(Node* root, int d) {
    if (!root) {
        return new Node(d);
    }
    if (d <= root->val) {
        root->lc = insertBST(root->lc, d);
    } else {
        root->rc = insertBST(root->rc, d);
    }
    return root;
}

void createBST(Node*& root) {
    // cout << "Enter data (-1 to stop): ";
    int d;
    cin >> d;
    while (d != -1) {
        root = insertBST(root, d);
        cin >> d;
    }
}

void lvlorder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->val << " ";
            if (front->lc) q.push(front->lc);
            if (front->rc) q.push(front->rc);
        }
    }
}

void minima(Node* root)
{
    while(root->lc){
        root = root->lc;
    }
    cout<<root->val<<" is the min value."<<endl;
}

void maxima(Node* root){
    while(root->rc){
        root = root->rc;
    }
    cout<<root->val<<" is the max value."<<endl;
}

bool isThere(int tar,Node* root)
{
    if(root == NULL) return false;
    if(root->val == tar){
        return true;
    }
    else if(tar > root->val){
        isThere(tar,root->rc);
    }
    else{
        isThere(tar,root->lc);
    }
}

Node* bstfromInoreder(int inorder[],int s,int e)
{
    //base case for stopping of recirsion
    if(s>e) return NULL;

    //ek case sodva..
    //root tayar kara using middle element
    int mid = (s+e)/2;
    Node* root = new Node(inorder[mid]);

    //bakich recirsion karun gheil..
    root->lc = bstfromInoreder(inorder,s,mid-1);
    root->rc = bstfromInoreder(inorder,mid+1,e);
    return root;
}

void printLL(Node* head)
{
    Node* temp = head;
    cout<<"The Doubley LL :"<<endl;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->rc;
    }
}

void convertToLL(Node* root, Node* &head)
{
    //base case :
    if(root == NULL) return;
    //RNL :
    //R :
    convertToLL(root->rc, head);

    //N
    //root chya right la ll attach kara
    root->rc = head;
    //head cha back pointer root la attach kara (ithe head null yeu shakto mhanun extra care)
    if(head) head->lc = root;
    //head change kara
    head = root;

    //L
    convertToLL(root->lc,head);
}

int main() {
    //50 30 60 25 40 70 80 55 -1
    Node* root = NULL;
    createBST(root);
    // cout << "\nLevel Order Traversal:\n";
    // lvlorder(root);
    // minima(root);
    // maxima(root);
    // cout<<isThere(40,root);

    // cout<<isThere(2,root);
    Node* head = NULL;
    convertToLL(root,head);
    printLL(head);
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* rc = NULL;
//     Node* lc = NULL;

//     Node(int d){
//         this->val = d;
//         this->lc = NULL;
//         this->rc = NULL;
//     }
// };

// Node* insertBST(Node* root,int d)
// {
//     if(root == NULL){
//         return new Node(d);
//     }
//     if(d <= root->val){
//         root->lc = insertBST(root->lc,d); 
//     }
//     else{
//         root->rc = insertBST(root->rc,d);
//     }
//     return root;
// }

// void createBST(Node* &root)
// {
//     cout<<"Enter data -> ";
//     int d ;
//     cin>>d;
//     while(d !=-1){
//         Node* root;
//         root = insertBST(root,d);
//         cin>>d;
//     }
// }


// void lvlorder(Node* root)
// {
//     queue<Node*>q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty())
//     {
//         Node* front = q.front();
//         if(front == NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<front->val;
//             if(front->lc) q.push(front->lc);
//             if(front->rc) q.push(front->rc);
//         }
//     }
// }

// int main()
// {
//     Node* root = NULL;
//     createBST(root);
//     lvlorder(root);
//     return 0;
// }