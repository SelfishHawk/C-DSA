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
bool isSame(node* &r1,node* &r2){
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL && r2!=NULL) return false;
    if(r1!=NULL && r2==NULL) return false;
    bool left=isSame(r1->left,r2->left);
    bool right=isSame(r1->right,r2->right);
    bool value=r1->data==r2->data;
    if(left && right && value){
        return true;
    }else{
        return false;
    }
}
int main()
{
    node *root1 = NULL;
    root1=buildtree();
    node *root2 = NULL;
    root2=buildtree();
    cout<<isSame(root1,root2);
    return 0;
}