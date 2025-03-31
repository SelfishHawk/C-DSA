#include<iostream>
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
node* buildtree(){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    if(data==-1) return NULL;
    node* root=new node(data);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void preorder(node* &root){
    // node left right
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=NULL;
    root=buildtree();
    cout<<"Preorder treversal "<<endl;
    preorder(root);
    return 0;
}