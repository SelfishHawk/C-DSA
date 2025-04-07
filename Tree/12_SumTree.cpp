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
pair<int,bool> isSum(node* &root){
    if(root==NULL){
        pair<int,bool> p=make_pair(0,true);
        return p;
    }
    if(root->left ==NULL && root->right==NULL){
        pair<int,bool> p=make_pair(root->data,true);
        return p;
    }
    pair<int,bool> leftAns=isSum(root->left);
    pair<int,bool> rightAns=isSum(root->right);
    bool left=leftAns.second;
    bool right=rightAns.second;
    bool cond= root->data==(leftAns.first+rightAns.first);
    pair<int,bool> ans;
    if(left && right && cond){
        ans.second=true;
        ans.first=root->data + leftAns.first + rightAns.first;;
    }
    else{
        ans.second=false;
    }
    return ans;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<"Is sum tree possible "<<isSum(root).second<<endl;
    return 0;
}