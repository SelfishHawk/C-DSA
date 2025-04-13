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
bool BSTsearch(node* root,int val){
    if(root==NULL){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(root->data>val){
        return BSTsearch(root->left,val);
    }else{
        return BSTsearch(root->right,val);

    }
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    cout<<"Enter the data to search "<<endl;
    int val;
    cin>>val;
    if(BSTsearch(root,val)==true){
        cout << val << " is found in the BST." << endl;
    }else{
        cout << val << " is not found in the BST." << endl;

    }
}