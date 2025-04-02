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
int height(node* &root){
    if (root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans = max(left,right)+1;
    return ans;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<"Height of tree is "<<height(root)<<endl;
    return 0;
}