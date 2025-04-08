#include <iostream>
#include<vector>
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
void traverseLeft(node* root,vector<int> &result){
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return;
    result.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,result);
    }
    else{
        traverseLeft(root->right,result);
    }
}
void traverseLeaf(node* root,vector<int> &result){
    if(root==NULL)
    return;
    if(root->left==NULL && root->right ==NULL){
        result.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,result);
    traverseLeaf(root->right,result);
}
void traverseRight(node* root,vector<int> &result){
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return;
    if(root->right){
        traverseRight(root->right,result);
    }
    else{
        traverseRight(root->left,result);
    }
    result.push_back(root->data);
}
vector<int> traverseBoundary(node* &root){
    vector<int> result;
    if(root==NULL)
      return result;
    result.push_back(root->data);
    // left subtree
    traverseLeft(root->left,result);
    //leaf nodes
    traverseLeaf(root->left,result);
    traverseLeaf(root->right,result);
    //right subtree
    traverseRight(root->right,result);
    return result;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<"Boundary traversal "<<endl;
    vector<int> output = traverseBoundary(root);
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}