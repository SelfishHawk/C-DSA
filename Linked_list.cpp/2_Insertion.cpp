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
bool isCircular(node *&head)
{
    bool a=false;
    if (head == NULL)
    {
        cout << "true";
        a=true;
        return true;
    }
    else
    {
        node *temp = head->next;
        if (head->next == NULL)
        {
            cout << "false";
            return false;
        }
        else
        {
            while (temp != NULL)
            {
                temp = temp->next;
                if (temp == head)
                {
                    cout << "True" << endl;
                    a=true;
                    break;
                }
            }
        }
    }
    cout<<a;
    return a;
}
int main()
{
    node *head = new node(10);
    insert(head, 20, 2);
    insert(head, 30, 3);
    insert(head, 40, 4);
    // cout<<head->data<<endl;
    print(head);
    insert(head, 50, 3);
    print(head);
    isCircular(head);
}