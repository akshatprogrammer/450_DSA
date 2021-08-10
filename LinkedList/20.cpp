#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node* prev;
	node(int val){
		data=val;
		next=NULL;
		prev=NULL;
	}
};
void insertAtHead(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	if(head!=NULL){
		head->prev=n;
	}
	head=n;
}
void insertAtTail(node* &head,int val){
	if(head==NULL){
		insertAtHead(head,val);
		return;
	}
	node* n=new node(val);
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
	//cout << "Added " << val << endl;
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout << temp->data << "->";
		temp=temp->next;
	}cout << "NULL\n";
}
node* reverse(node** head){
	node* curr=*head;
	node* prev=NULL;
	node* next;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;

}
int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	display(head);
	//reverse(head);
	display(reverse(&head));
}
