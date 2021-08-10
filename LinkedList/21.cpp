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
void FindPair(node* head,int x){
	node* start=head;
	node* end=head;
	while(end->next->data<x){
		end=end->next;
	}
	bool found=false;

	while(start!=end && end->next!=start){
		if(start->data+end->data == x){
			found = true;
			cout << "(" << end->data << "," << start->data << ")" << endl;
			start=start->next;
			end=end->prev;
		}
		else{
			start=start->next;
			end=end->prev;
		}
	}
	if(!found) cout << "No pair Found" << endl;
}
int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtTail(head,6);
	insertAtTail(head,8);
	insertAtTail(head,9);
	display(head);
	//cin >> x;
	FindPair(head,7);

	return 0;
}
