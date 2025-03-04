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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node* deleteDuplicate(node* &head){
    node* curr=head;
    while(curr!=NULL){
        if(curr->next!=NULL && curr->data==curr->next->data){
            node* nodeTodelete=curr->next;
            curr->next=nodeTodelete->next;
            nodeTodelete->next=NULL;
            delete nodeTodelete;
        }
        else{
        curr=curr->next;
        }
    }
    return head;
}
int main()
{
    node *head = new node(10);
    insert(head, 20, 2);
    insert(head, 20, 3);
    insert(head, 40, 4);
    insert(head, 40, 5);
    insert(head, 40, 6);
    insert(head, 50, 7);
    print(head);
    deleteDuplicate(head);
    print(head);
}