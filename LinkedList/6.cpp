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
        cout << temp->data << "-> ";
        temp=temp->next;
    }cout << "NULL" <<endl;
}
node* duplicateFinder(node* head){
    if(head==NULL) return head;
    node* temp=head;
    while(temp!=NULL&&temp->next!=NULL){
        if(temp->data==temp->next->data){
            node* temp1=temp->next;
            temp->data=temp1->data;
            temp->next=temp1->next;
        }
        else
        temp=temp->next;
    }
    return head;
}
int main(){
    node* head=NULL;
    int n,ele;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ele;
        insertAtTail(head,ele);
    }
    node* newhead=duplicateFinder(head);
    display(newhead);
}