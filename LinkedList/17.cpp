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
int count=0;
void insertAtHead(node* &head,int val){
	node* n = new node(val);
	if(head==NULL){
		n->next=n;
		head=n;
		count++;
		return;
	}
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	count++;
}
void insertAtTail(node* &head,int val){
	if(head==NULL){
		insertAtHead(head,val);
		return;
	}
	node* n = new node(val);
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	count++;
}
void display(node* head){
	node* temp=head;
	do{
		cout << temp->data << " ";
		temp=temp->next;
	}while(temp!=head);
	cout <<endl;
}
void splitCLL(node* head,node** h1,node** h2){
	node* fast=head;
	node* slow=head;
	while(fast->next!=head&&fast->next->next!=head){
		slow=slow->next;
		fast=fast->next->next;
	}
	*h1=head;
	*h2=slow->next;
	slow->next=head;
	node* curr=*h2;
	while(curr->next!=head){
		curr=curr->next;
	}
	curr->next=*h2;
}	
int main(){
	node* head=NULL;
	node* head1=NULL;
	node* head2=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);
	splitCLL(head,&head1,&head2);
	display(head1);
	display(head2);
//	cout <<endl<< isCircular(head);
}