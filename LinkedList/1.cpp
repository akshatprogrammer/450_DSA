#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}
void insertAtTail(node* &head,int data){
    node* n = new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
node* reverseItr(node* &head){
    node* prev=NULL;
    node* curr=head;
    node *nextptr;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}
node* reverseRec(node* &head){
    if(head==NULL || head->next==NULL)
        return head;
    node* newhead3=reverseRec(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead3;
}
int main(){
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    node *newhead = reverseItr(head);
    display(newhead);
    node *newhead1 = reverseRec(newhead);
    display(newhead1);
}