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
node* LCA(node* root,int p,int q){
    if(root==NULL)
    return NULL;
    if(root->data>p && root->data>q){
        return LCA(root->left,p,q);
    }else if(root->data<p && root->data<q){
        return LCA(root->right,p,q);
    }else {
        return root;
    }
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    levelOrderTraversal(root);
    int p,q;
    cout<<"Enter the value of p and q"<<endl;
    cin>>p>>q;
    cout<<"Least common ancestor is "<<LCA(root,p,q)->data;
}