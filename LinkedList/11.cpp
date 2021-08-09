#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }cout << endl;
}
void intersection(node** head1,node** head2){
    node* a= *head1;
    node* b=*head2;
    node* c=NULL;
    node* temp=NULL;
    while(a && b){
        if(a->data==b->data){
            insert(c,a->data);
            a=a->next;
            b->next;
        }
        else if(a->data<b->data) a=a->next;
        else b=b->next;
    }
    display(c);
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head1,6);
    insert(head2,2);
    insert(head2,4);
    insert(head2,6);
    intersection(&head1,&head2);
    return 0;
}