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
node* middle(node *&head)
{
    node *midlleNode = head;
    node *temp = head;
    if(head==NULL){
        return head;
        cout<<"Middle node is :- NULL"<<endl;
    }else{
        while (temp != NULL)
        {
            if(temp->next==NULL){
                cout<<"Middle node is :-"<<midlleNode->data<<endl;
                return midlleNode;
            }
            else if(temp->next->next==NULL){
                midlleNode = midlleNode->next;
                cout<<"Middle node is :-"<<midlleNode->data<<endl;
                return midlleNode;
            }
            else{
            temp = temp->next->next;
            midlleNode = midlleNode->next;
            }
        }
        
        cout<<"Middle node is :-"<<midlleNode->data<<endl;
    }
    return midlleNode;
}
/*
node* middle(node* &head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(head==NULL){
        cout<<"Middle node is :- null"<<endl;
        return head;
    }
    else if(len==1){
        cout<<"Middle node is :-"<<head->data<<endl;
        return head;
    }
    else if(len==2){
        cout<<"Middle node is :-"<<head->next->data<<endl;
        return head->next;
    }
    else{
    int middleNode=(len/2);
    node* midNode=head;
    for(int i=1;i<=middleNode;i++){
        midNode=midNode->next;
    }
    cout<<"Middle node is :-"<<midNode->data<<endl;
    return midNode;}
}
*/
int main()
{
    node *head = new node(10);
    insert(head, 20, 2);
    insert(head, 30, 3);
    insert(head, 40, 4);
    insert(head, 50, 5);
    print(head);
    middle(head);
}