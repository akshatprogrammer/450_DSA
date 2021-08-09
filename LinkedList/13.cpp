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
void FindMiddle(node* curr,node** first,node** second){
    node* slow=curr;
    node* fast=curr->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        }
    }
    *first=curr;
    *second=slow->next;
    slow->next=NULL;
}
node* MergeBoth(node* first,node* second){
    node* ans=NULL;
    if(first==NULL)return second;
    else if(second==NULL) return first;

    if(first->data<=second->data){
        ans=first;
        ans->next=MergeBoth(first->next,second);
    }
    else{
        ans=second;
        ans->next=MergeBoth(first,second->next);
    }
    return ans;
}
void mergeSort(node** head){
    node* curr = *head;
    node* first;
    node* second;
    if(curr==NULL || curr->next==NULL) return;

    FindMiddle(curr,&first,&second);
    mergeSort(&first);
    mergeSort(&second);
    *head=MergeBoth(first,second);
}
node* mergesorting(node* head){
    mergeSort(&head);
    return head;
}
int main(){
    node* head=NULL;
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    node* newhead=mergesorting(head);
    display(newhead);
}