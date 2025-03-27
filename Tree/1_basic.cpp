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
node *buildtree(node *&root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the data for the left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildtree(root->right);
}
int main()
{
    node *root = NULL;
    buildtree(root);
    return 0;
}