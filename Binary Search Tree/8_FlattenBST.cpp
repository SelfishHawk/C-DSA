#include<iostream>
#include<vector>
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
void inorder(node* root,vector<int> &inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}
node* flattenBST(node* &root){
    vector<int> inorderVal;
    inorder(root,inorderVal);
    int n=inorderVal.size();
   node* newNode=new node(inorderVal[0]);
   node* curr=newNode;
   for(int i=1;i<n;i++){
    node* temp=new node(inorderVal[i]);
    curr->left=NULL;
    curr->right=temp;
    curr=temp;
   }
   curr->left=NULL;
   curr->right=NULL;
   return newNode;
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    node* flat = flattenBST(root);
    cout << "Flattened BST (Right-skewed): ";
    while(flat != NULL){
        cout << flat->data << " ";
        flat = flat->right;
    }
    cout << endl;
}