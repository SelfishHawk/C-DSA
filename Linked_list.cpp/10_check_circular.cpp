#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void print(node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        cout << tail->next->data << "->";
        node *temp = tail->next->next;
        while (temp != tail->next)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
void insert(node *&tail, int d, int pos)
{
    if (tail == NULL)
    {
        if (pos != 1)
        {
            cout << "Invalid position" << endl;
        }
        node *temp = new node(d);
        tail = temp;
        tail->next = temp;
        return;
    }
    else if (pos == 1)
    {
        node *temp = new node(d);
        temp->next = tail->next;
        tail->next = temp;
    }
    else
    {
        node *temp = tail->next;
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *p = new node(d);
        p->next = temp->next;
        temp->next = p;
        if (tail == temp)
        {
            tail = p;
        }
        return;
    }
}
void del(node *&tail, int pos)
{
    if (tail == NULL)
    {
        cout << "Empty linked list" << endl;
        return;
    }
    else if (tail == tail->next)
    {
        delete tail;
    }
    else
    {
        int count = 1;
        node *temp = tail->next;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *nodeTOdelete = temp->next;
        temp->next = nodeTOdelete->next;
        nodeTOdelete->next = NULL;
        if (nodeTOdelete == tail)
            tail = temp;
        delete nodeTOdelete;
    }
}
bool isCircular(node *&tail)
{
    bool condition=false;
    if (tail == NULL)
    {
        cout<<"true";
        return true;
    }
    else
    {
        node *temp = tail->next;
        if (tail->next == NULL)
        {
            cout<<"false";
            return false;
        }
        else
        {
            while(temp!=NULL){
                temp=temp->next;
                if(temp==tail){
                cout<<"True"<<endl;
                return true;}
            }
        }
    }
    return false;
}
int main()
{
    node *tail = NULL;
    insert(tail, 10, 1);
    insert(tail, 20, 2);
    insert(tail, 30, 3);
    print(tail);
    isCircular(tail);
}