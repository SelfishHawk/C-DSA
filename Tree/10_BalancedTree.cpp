#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree()
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    node* root = new node(data);
    cout << "Enter the data for the left of " << data << endl;
    root->left = buildtree();
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildtree();
    return root;
}
/*
int height(node* &root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    int  ans=max(left,right)+1;
    return ans;
}
bool isBalanced(node* &root){
    if(root==NULL) return true;
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}
    */
   pair<bool,int> isBalanced(node* &root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    pair<int,int> left=isBalanced(root->left);
    pair<int,int> right=isBalanced(root->right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    if(leftAns && rightAns && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
   }
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<isBalanced(root).first;
    return 0;
}