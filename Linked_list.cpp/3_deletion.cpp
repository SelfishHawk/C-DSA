#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;


    node(int data){    
    this->data=data;
    this->next=NULL;
    }
};
void insert(node* &head,int d,int pos){
    if(head==NULL){
        node*temp=new node(d);
        head=temp;
    }
    if(pos==1){
        node* temp=new node(d);
        temp->next=head;
        head=temp;
        return;
    }
   node* temp=head;
   int count=1;
   while(count<pos-1){
    temp=temp->next;
    count++;
    }
    if(temp->next==NULL){
        node* t=new node(d);
        temp->next=t;
        t->next=NULL;
        return;
    }
    node* p=new node(d);
    p->next=temp->next;
    temp->next=p;
}
void print(node* &head){
    node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deletehead(node* &head,int pos){
    if(head==NULL){
        cout<<"Empty";
        return;
    }
    if(pos==1){
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    node* temp=head;
    int count=1;
    while(count<pos-1&& temp->next != NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        cout<<"out of bounds"<<endl;
        return;
    }
    node* p=temp->next;
    temp->next=p->next;
    p->next=NULL;
    delete p;
}
int main(){
    node* head= new node(10);
    insert(head,20,2);
    insert(head,30,3);
    insert(head,40,4);
    cout<<head->data<<endl;
    print(head);
    deletehead(head,2);
    print(head);
    deletehead(head,6);
    print(head);
}