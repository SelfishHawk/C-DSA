#include <iostream>
#include<queue>
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
vector<int> traverse(node* &root){
    vector<int> result;
    if(root==NULL) return result;
    queue<node*> q;
    q.push(root);
    bool LeftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0; i<size; i++){      
        node* front=q.front();
        q.pop();
        int index=LeftToRight ? i:size-i-1;
        ans[index]=front->data;
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
        }
        LeftToRight= !LeftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    cout<<"zig zag traversal "<<endl;
    vector<int> output = traverse(root);
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}