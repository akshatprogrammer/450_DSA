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
/*void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp=temp->next;
    }
}*/
bool detectloop(node* head){
    node* slow=head;
    node* fast=head;
    if(head==NULL)
        return false;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)
            return true;
    }
    return false;

}
int main(){
    node* head=NULL;
    int n,ele;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ele;
        insert(head,ele);
    }
    cin >> x;
    //display(head);
    cout << detectloop(head);

}
