#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert(node *&head, int d, int pos)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    if (pos == 1)
    {
        node *temp = new node(d);
        temp->next = head;
        head = temp;
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        node *t = new node(d);
        temp->next = t;
        t->next = NULL;
        return;
    }
    node *p = new node(d);
    p->next = temp->next;
    temp->next = p;
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
//Recursive solution
node* reverse_recursion(node* &head,node* curr,node* prev){
    if(curr==NULL){
        head=prev;
        return head;
    }
    node* forward=curr->next;
    reverse_recursion(head,forward,curr);
    curr->next=prev;
}
// Iterative solution
node* reverse(node* &head)
{
        node* curr=head;
        node*prev=NULL;
        reverse_recursion(head,curr,prev);
        return head;
//     if(head==NULL||head->next==NULL){
//         return head;
//     }
//     node* curr=head;
//     node*prev=NULL;
//     node* forward=NULL;
//     while(curr!=NULL){
//        forward=curr->next;
//        curr->next=prev;
//        prev=curr;
//        curr=forward;
//        head=prev;
//     }
//     return;
 }
int main()
{
    node *head = new node(10);
    insert(head, 20, 2);
    insert(head, 30, 3);
    insert(head, 40, 4);
    insert(head, 50, 5);
    print(head);
    reverse(head);
    print(head);
}