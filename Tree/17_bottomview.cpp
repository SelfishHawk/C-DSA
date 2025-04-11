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
vector<int> bottom(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;
        topnode[hd] = frontnode->data;
        if (frontnode->left)
        {
            q.push({frontnode->left, hd - 1});
        }
        if (frontnode->right)
        {
            q.push({frontnode->right, hd + 1});
        }
    }
    for (auto i : topnode)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree();
    vector<int> result = bottom(root);
    cout << "Traversal result from bottom view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}