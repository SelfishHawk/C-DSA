#include<iostream>
#include<queue>
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
void inorder(node* root,vector<int>& inorderVal){
    if(root==NULL){
        return;
    }
    inorder(root->left,inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right,inorderVal);
}
node* inorderToBST(int s,int e, vector<int> &inorderVal){
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    node* root=new node(inorderVal[mid]);
    root->left=inorderToBST(s,mid-1,inorderVal);
    root->right=inorderToBST(mid+1,e,inorderVal);
    return root;
}
node* BalancedBST(node* &root){
    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}
void levelOrderTraversal(node* root){
    queue<node*> s;
    s.push(root); 
    while(!s.empty()){
        int levelSize=s.size();
        while(levelSize--){
        node* temp=s.front();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
        }
        cout<<endl;
        }
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    cout << "Original BST (Level Order): "<<endl;
    levelOrderTraversal(root);
    root=BalancedBST(root);
    cout << "Balanced BST (Level Order): "<<endl;
    levelOrderTraversal(root);
}