#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertIntoBST(node* &root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

node* insert(node* &root){
    int d;
    cin>>d;
    while(d!=-1){
    root=insertIntoBST(root,d);
    cin>>d;
    }
    return root;
}

void BSTtoDLL(node* root, node* &head){
    if(root==NULL)
    return;
    BSTtoDLL(root->left,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    BSTtoDLL(root->right,head);
}

node* mergeDLL(node* &head1, node* &head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    
    node* head = NULL;
    node* tail = NULL;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!head) {
                head = tail = head1;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        } else {
            if (!head) {
                head = tail = head2;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }
    if (head1) {
        if (!head) return head1;
        tail->right = head1;
        head1->left = tail;
    }
    if (head2) {
        if (!head) return head2;
        tail->right = head2;
        head2->left = tail;
    }
    
    return head;
}

int count(node* head){
    int cnt=0;
    node* temp=head;
    while(temp){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

node* DLLtoBST(node* &head,int n){
    if(n<=0 || head==NULL)
    return NULL;
    node* left=DLLtoBST(head,n/2);
    node* root=head;
    root->left=left;
    head=head->right;
    root->right =DLLtoBST(head,n-n/2-1);
    return root;
}

node* BST(node* &root1,node* &root2){
   node* head1 = NULL;
   BSTtoDLL(root1, head1);
   while (head1 && head1->left)
       head1 = head1->left;

   node* head2 = NULL;
   BSTtoDLL(root2, head2);
   while (head2 && head2->left)
       head2 = head2->left;
   
   node* head=mergeDLL(head1,head2);
   int n=count(head);
   return DLLtoBST(head,n);
}

void levelOrderTraversal(node* root){
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

int main(){
    node* root1=NULL;
    cout<<"Insert the data for root1 "<<endl;
    insert(root1);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root1);
    node* root2=NULL;
    cout<<"Insert the data for root2 "<<endl;
    insert(root2);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root2);
    node* root=BST(root1,root2);
    cout<<"level order traversal "<<endl;
    levelOrderTraversal(root);
}