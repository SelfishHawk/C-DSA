#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* insertIntoBST(node* &root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
node* insert(node* &root){
    int d;
    cin>>d;
    while(d!=-1){
    root=insertIntoBST(root,d);
    cin>>d;
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}
node* minVal(node* root){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}
node* maxVal(node* root){
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp;
}
node* predecessor(node* root,int val){
    node* predecessor = NULL;
    while (root != NULL) {
        if (val > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}
node* successor(node* root,int val){
    node* succ = NULL;
    while (root != NULL) {
        if (val < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    cout<<"Inorder traversal"; 
    inorder(root);
    cout<<endl;
    cout<<"Min val in the BST is "<<minVal(root)->data<<endl;
    cout<<"Max val in the BST is "<<maxVal(root)->data<<endl;
    cout<<"Enter the value ";
    int val;
    cin>>val;
    cout<<"Inorder predecessor of " << val <<" is "<<predecessor(root,val)->data<<endl;
    cout<<"Inorder successor of " << val <<" is "<<successor(root,val)->data<<endl;
}