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
void inorder(node* &root,int &count){
    // left node right
    if(root == NULL) return;
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL) count++;
    inorder(root->right,count);
}
void noOfLeafNode(node* &root){
    int count=0;
   inorder(root,count);
    cout<<"Number of leaf node "<<count;
    return;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    noOfLeafNode(root);
    return 0;
}