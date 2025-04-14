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
node* minVal(node* root){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}
node* BSTdelete(node* &root,int val){
    if(root==NULL) return root;
    if(root->data==val){
        //0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child either left or right 
        else if(!root->left || !root->right){
            if(root->left){
                node* temp=root->left;
                delete root;
                return temp;
            }else if(root->right){
                node* temp=root->right;
                delete root;
                return temp;
            }
        }
        // 2 child 
        else if(root->left !=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=BSTdelete(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left=BSTdelete(root->left,val);
        return root;
    }else{
        root->right=BSTdelete(root->right,val);
        return root;
    }
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
    levelOrderTraversal(root);
    int val;
    cout<<"Enter the value to delete "<<endl;
    cin>>val;
    BSTdelete(root,val);
    levelOrderTraversal(root);
}