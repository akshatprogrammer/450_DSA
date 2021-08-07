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
void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }cout << "NULL";
}
void lastToFirst(node* &head){
    if(head==NULL){
        return;
    }
    node* prev=NULL;
    node* temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        //prev=prev->next;
    }
    temp->next=head;
    head=prev->next;
    prev->next=NULL;
    

}
int main(){
    int n,ele;
    cin >> n;
    node* head=NULL;
    for(int i=0;i<n;i++){
        cin >> ele;
        insertAtTail(head,ele);
    }
    lastToFirst(head);
    display(head);
}