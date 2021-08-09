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
void FindMiddle(node* curr){
    node* slow=curr;
    node* fast=curr->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        }
    }
    cout << slow->data << endl;
    
}
int main(){
    node* head=NULL;
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    insert(head,6);
    insert(head,7);
    FindMiddle(head);
   // display(head);
}