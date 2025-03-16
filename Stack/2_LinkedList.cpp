#include <iostream>
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
void push(node *&head, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *newnode = new node(data);
        temp->next = newnode;
    }
}
int peek(node *&head)
{
    if (head == NULL)
        return 0;
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}
void pop(node *&head)
{
    if (head == NULL)
        return;
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *prev = head;
        while (prev->next != temp)
            prev = prev->next;
        prev->next=NULL;
        delete temp;
        return;
    }
}
bool isEmpty(node *&head)
{
    if (head == NULL)
        return true;
    else
        return false;
}
int size(node* &head){
    int size=0;
    node*temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
using namespace std;
int main()
{
    node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    cout << "Data at top is " << peek(head) << endl;
    pop(head);
    cout << "Data at top is " << peek(head) << endl;
    cout << "Size of stack is " << size(head) << endl;
}