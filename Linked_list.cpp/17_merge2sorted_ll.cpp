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
node *sort(node *&head1, node *&head2)
{
    if (head1->data > head2->data)
    {
        node *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    node *temp = head2;
    node *prev = head1;
    node *curr = head1->next;
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    while (temp != NULL && curr != NULL)
    {
        if (temp->data >= prev->data && temp->data <= curr->data)
        {
            node *move = temp;
            temp = temp->next;
            prev->next = move;
            move->next = curr;
            prev = prev->next;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
           
        }
        if(curr==NULL){
            prev->next=temp;
            break;
        }
    }
    return head1;
}
int main()
{
    node *head2 = new node(15);
    insert(head2, 20, 2);
    insert(head2, 30, 3);
    insert(head2, 40, 4);
    insert(head2, 65, 5);
    print(head2);
    node *head1 = new node(10);
    insert(head1, 25, 2);
    insert(head1, 35, 3);
    insert(head1, 60, 4);
    insert(head1, 70, 5);
    print(head1);
    sort(head1, head2);
    print(head1);
}