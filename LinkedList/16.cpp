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
	}while(temp->next!=head);
}
bool isCircular(node* head){
	node* temp=head;
	int i=0;
	while(temp->next!=head&&i<count){
		temp=temp->next;
	}
	if(temp->next==head)
		return true;
	else
		return false;
}
int main(){
	node* head=NULL;
	insertAtHead(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);
	cout <<endl<< isCircular(head);
}