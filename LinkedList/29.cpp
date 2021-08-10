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
node* sortZOT(node* head){
    int c0=0,c1=0,c2=0;
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0) c0++;
        else if(temp->data==1) c1++;
        else c2++;
        temp=temp->next;
    }
    //cout << c0 << c1 << c2;
    temp=head;
        while(c0--){
            temp->data=0;
            temp=temp->next;
        }
        while(c1--){
            temp->data=1;
            temp=temp->next;
        }
        while(c2--){
            temp->data=2;
            temp=temp->next;
        }
    return head;
}
int main(){
    node* head=NULL;
    insert(head,0);
    insert(head,1);
    insert(head,0);
    insert(head,1);
    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,0);
    display(head);
    display(sortZOT(head));
   // display(DNF(&head));
    return 0;
}