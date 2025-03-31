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
void postorder(node* &root){
    // left right node
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root=NULL;
    root=buildtree();
    cout<<"postorder treversal "<<endl;
    postorder(root);
    return 0;
}