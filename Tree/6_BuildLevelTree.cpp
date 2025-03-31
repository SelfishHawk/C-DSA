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
void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        //for left
        cout<<"Enter the left data of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!= -1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        //for right
        cout<<"Enter the right data of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!= -1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrder(node* &root){
    if(root==NULL) return;


    queue<node*> q;
    q.push(root); 
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
        
}
int main(){
    node* root=NULL;
    buildFromLevelOrder(root);
    levelOrder(root);
    return 0;
}