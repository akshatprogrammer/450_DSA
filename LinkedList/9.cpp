#include<iostream>
#include<cmath>
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
void addOneToLL(node* &head){
    int count=-1;
    node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout << count << endl;
    int sum=1;
    temp=head;
    while(count>=0){
        sum += temp->data*(pow(10,count));
        count--;
        temp=temp->next;
    }
    cout << sum << endl;
}
int main(){
    int n,ele;
    cin >> n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        cin >> ele;
        insertAtTail(head,ele);
    }
    addOneToLL(head);
}