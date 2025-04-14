#include <iostream>
#include <climits>
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
bool isBST(node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
    bool left=isBST(root->left,min,root->data);
    bool right=isBST(root->right,root->data,max);
    return left&&right;
    }else{
        return false;
    }
}
bool check(node* root){
    return isBST(root,INT_MIN,INT_MAX);
}
int main()
{
    node *root = NULL;
    root=buildtree();
    if (check(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is NOT a BST." << endl;
    }
    return 0;
}