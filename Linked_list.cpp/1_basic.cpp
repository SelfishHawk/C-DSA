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
    void insertAthead(node* &head,int d){
        node* temp=new node(d);
        temp->next=head;
        head=temp;
    }
    void insertAttail(node* &tail,int d){
        node*temp=new node(d);
        tail->next=temp;
        tail=temp->next;
    }
    void print(node* &head){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
int main(){
    node* node1= new node(10);
    node* head=node1;
    node* tail=node1;
    cout<<node1->data<<endl;
    insertAthead(head,20);
    print(head);
    insertAttail(tail,30);
    print(head); 
}