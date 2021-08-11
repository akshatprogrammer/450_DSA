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
void deletion(node* &head,int pos){
	node* temp=head;
	if(pos==1){
		while(temp->next!=head){
			temp=temp->next;
		}
		node* todelete=head;
		temp->next=head->next;
		head=head->next;
		delete todelete;
		return;
	}
	int count=1;
	while(count!=pos-1){
		temp=temp->next;
		count++;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	delete todelete;
}
int main(){
	node* head=NULL;
	insertAtHead(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);
	deletion(head,3);
	display(head);
}