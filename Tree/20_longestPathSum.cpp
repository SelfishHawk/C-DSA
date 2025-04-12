#include <iostream>
#include<vector>
#include<map>
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
void path(node* root,int len,int &MaxLen,int sum,int &MaxSum){
    if(root==NULL){
        if(len>MaxLen){
            MaxLen=len;
            MaxSum=sum;
        }else if(len==MaxLen){
          sum=MaxSum;
        }
        return;
    }
    sum+=root->data;
    path(root->left,len+1,MaxLen,sum,MaxSum);
    path(root->right,len+1,MaxLen,sum,MaxSum);
}
int sum(node* root){
    int len=0;
    int MaxLen=0;
    int sum=0;
    int MaxSum=0;
    path(root,len,MaxLen,sum,MaxSum);
    return MaxSum;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<"Maximum sum in a branch of tree is "<<sum(root)<<endl;
    return 0;
}