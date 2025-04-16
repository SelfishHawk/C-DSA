#include <iostream>
#include <climits>
#include <vector>
#include <queue>
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
node* BST(vector<int> &preorder,int &i,int min,int max){
   if(i>=preorder.size()) return NULL;
   int val=preorder[i];
   if(val>max || val<min) return NULL;
   i++;
   node* root=new node(val);
   root->left=BST(preorder,i,min,val);
   root->right=BST(preorder,i,val,max);
   return root;
}
node* preorderToBST(vector<int> &preorder){
    int i=0;
    return BST(preorder,i,INT_MIN,INT_MAX);
}

void levelOrderTraversal(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}
int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    node* root = preorderToBST(preorder);

    cout << "Level Order Traversal of BST:\n";
    levelOrderTraversal(root);

    return 0;
}