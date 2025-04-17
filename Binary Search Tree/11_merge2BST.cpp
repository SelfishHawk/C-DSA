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
void inorder(node* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }else{
            ans[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }
    return ans;
}
node* BST(int s,int e, vector<int> &in){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    node* root=new node(in[mid]);
    root->left=BST(s,mid-1,in);
    root->right=BST(mid+1,e,in);
    return root;
}
node* mergeBST(node* &root1,node* &root2){
    //Step 1 :save inorder
    vector<int> in1,in2;
    inorder(root1,in1);
    inorder(root2,in2);
    //step 2: Merge 2 sorted arrays
    vector<int> mergedArr=merge(in1,in2);
    //step 3: Inorder to BST
    int s=0,e=mergedArr.size()-1;
    return BST(s,e,mergedArr);
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
    node* root1=NULL;
    cout<<"Insert the data for root1 "<<endl;
    insert(root1);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root1);
    node* root2=NULL;
    cout<<"Insert the data for root2 "<<endl;
    insert(root2);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root2);
    node* root=mergeBST(root1,root2);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root);
}