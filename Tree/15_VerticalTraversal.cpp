#include<queue>
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
vector<int> traverse(node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node*,pair<int,int>>> q;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    q.push({root,{0,0}});
    while(!q.empty()){
        pair<node*,pair<int,int>> temp=q.front();
        q.pop();
        node* frontnode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push({frontnode->left,{hd-1,lvl+1}});
        }
        if(frontnode->right){
            q.push({frontnode->right,{hd+1,lvl+1}});
        }
    }
    
    for (auto& i : nodes) {
        for (auto& j : i.second) {
            for (int k : j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}
int main()
{
    node *root = NULL;
    root=buildtree();
    vector<int> result = traverse(root);
    cout << "Traversal result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}