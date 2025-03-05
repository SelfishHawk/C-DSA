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
//It can be done this way but if clearly mentioned that you can't use data replacement method then we have to go other way
/*
node* sort(node* &head){
    node* temp=head;
    int count0=0,count1=0,count2=0;
    while(temp){
        if(temp->data==0) count0++;
        if(temp->data==1) count1++;
        if(temp->data==2) count2++;
        temp=temp->next;
    }
    node* curr=head;
    while(curr!=NULL){
        if(count0!=0){
            curr->data=0;
            count0--;
        }
        else if(count1!=0){
            curr->data=1;
            count1--;
        }
        else{
            curr->data=2;
            count2--;
        }
        curr=curr->next;
    }
    return head;
}
    */
node* sort(node* &head){
    node* headcount0=new node(-1);
    node* tailcount0=headcount0;
    node* headcount1=new node(-1);
    node* tailcount1=headcount1;
    node* headcount2=new node(-1);
    node* tailcount2=headcount2;
    node* temp=head;
    while(temp){
        if(temp->data==0){
            node* move=temp;
            temp=temp->next;
            tailcount0->next=move;
            move->next=NULL;
            tailcount0=move;
        }
        else if(temp->data==1){
            node* move=temp;
            temp=temp->next;
            tailcount1->next=move;
            move->next=NULL;
            tailcount1=move;
        }
        else if(temp->data==2){
            node* move=temp;
            temp=temp->next;
            tailcount2->next=move;
            move->next=NULL;
            tailcount2=move;
        }
    }
    if(headcount1->next!=NULL) tailcount0->next=headcount1->next;
    else tailcount0->next=headcount2->next;
    tailcount1->next=headcount2->next;
    tailcount2->next=NULL;
    head=headcount0->next;
    delete headcount0;
    delete headcount1;
    delete headcount2;
    return head;
}
int main()
{
    node *head = new node(1);
    insert(head, 2, 2);
    insert(head, 2, 3);
    insert(head, 0, 4);
    insert(head, 1, 5);
    print(head);
    sort(head);
    print(head);
}