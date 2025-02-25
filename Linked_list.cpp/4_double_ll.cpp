#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Deleted data :" << value << endl;
    }
};
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
int length(node *head)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insert(node *&head, int d, int pos)
{
    if(head==NULL){
        if(pos!=1){
            cout<<"Invalid input position"<<endl;
            return;
        }
        node*temp=new node(d);
        head=temp;
    }
    else{
    if (pos == 1)
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
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
        node *p = new node(d);
        temp->next = p;
        p->prev = temp;
        return;
    }
    node *s = new node(d);
    s->next = temp->next;
    temp->next->prev = s;
    temp->next = s;
    s->prev = temp;
}
}
void del(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    if (pos == 1)
    {
        node *temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        cout << "out of bounds" << endl;
        return;
    }
    node *p = temp->next;
    if (p->next == NULL)
    {
        temp->next = NULL;
        p->next = NULL;
        p->prev = NULL;
        delete p;
        return;
    }
    else{
    temp->next = p->next;
    p->next->prev = temp;
    p->next = NULL;
    p->prev = NULL;
    delete p;
    return;
    }
}
int main()
{
    node *head = NULL;
    print(head);
    insert(head, 20, 1);
    insert(head, 30, 2);
    insert(head, 40, 3);
    print(head);
    cout << "Length of the linked list:-" << length(head) << endl;
    del(head, 1);
    print(head);
}
