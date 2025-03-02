#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;


    node(int data){    
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
    }
};void insert(node *&head, int d, int pos)
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
void print(node* &head){
    node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node* reverse(node* &head){
    node* prev=NULL;
    node* forward=NULL;
    node* curr=head;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr->prev=forward;
        prev=curr;
        curr=forward;
        head=prev;
    }
    return prev;
}
int main(){
    node* head= new node(10);
    insert(head,20,2);
    insert(head,30,3);
    insert(head,40,4);
    insert(head,50,5);
    print(head);
    reverse(head);
    print(head);
}