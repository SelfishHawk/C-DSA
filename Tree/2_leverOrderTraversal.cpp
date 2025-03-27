#include <iostream>
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
    return root;
}
void levelOrderTraversal(node* &root){
    queue<node*> s;
    s.push(root); 
    while(!s.empty()){
        int levelSize=s.size();
        while(levelSize--){
        node* temp=s.front();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
        }
        cout<<endl;
        }
}
int main()
{
    node *root = NULL;
    buildtree(root);
    //1 3 7 -1 -1 5 -1 -1 2 8 -1 -1 -1
    levelOrderTraversal(root);
    return 0;
}