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
void inOrderTraversal(node* root,vector<int> &inorderVal){
if(root==NULL)
return;
inOrderTraversal(root->left,inorderVal);
inorderVal.push_back(root->data);
inOrderTraversal(root->right,inorderVal);
}
bool TwoSumBST(node*root,int target){
    vector <int> inorderVal;
    inOrderTraversal(root,inorderVal);
    int i=0,j=inorderVal.size()-1;
    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];
        if(sum==target) return true;
        else if(sum>target) j--;
        else i++;
    }
    return false;
}
int main(){
    node* root=NULL;
    cout<<"Insert the data"<<endl;
    insert(root);
    int k;
    cout<<"Enter the value of k "<<endl;
    cin>>k;
    cout<<TwoSumBST(root,k);
}