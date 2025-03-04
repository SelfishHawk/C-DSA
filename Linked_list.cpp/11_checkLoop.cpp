#include <iostream>
#include <map>
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
bool checkLoop(node* &head){
    if(head==NULL){
        return false;
    }
    node* slowPointer=head;
    node* fastPointer=head;
    while(fastPointer!=NULL){
        fastPointer=fastPointer->next->next;
        slowPointer=slowPointer->next;
        if (fastPointer==slowPointer){
            cout<<"Loop is present"<<endl;
            return true;
        }
    }
    return false;
}
bool detectLoop(node* &head){
    if(head==NULL){
        return false;
    }
    map<node*,bool>visited;
    node* temp=head;
    while(temp){
        if(visited[temp]==true){
            cout<<"Element at start of loop is"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    cout<<"No cycle"<<endl;
    return false;
}
int main(){
    node *head = new node(10);
    insert(head, 20, 2);
    insert(head, 30, 3);
    insert(head, 40, 4);
    insert(head, 50, 5);
    head->next->next->next->next=head->next;
    cout<<head->next->next->next->next->data<<endl;
    checkLoop(head);   
}