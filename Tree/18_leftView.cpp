#include <queue>
#include <iostream>
#include <vector>
#include <map>
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
    node *root = new node(data);
    cout << "Enter the data for the left of " << data << endl;
    root->left = buildtree();
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildtree();
    return root;
}
void solve(node* root,vector<int> &ans,int lvl){
    if(root==NULL){
        return;
    }
    if(ans.size()==lvl){
        ans.push_back(root->data);
    }
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
}
vector<int> left(node *root)
{
    vector<int> ans;
    solve(root,ans,0);
        return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree();
    vector<int> result = left(root);
    cout << "Traversal result from left view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}