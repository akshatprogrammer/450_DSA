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
bool isPalindrome(node* head){
	node* tail=head;
	int n=1;
	while(tail->next!=NULL){
		tail=tail->next;
		n++;
	}
	int count=0;
	while(head!=tail&&tail->next!=head){
		if(head->data==tail->data){
			count++;
			head=head->next;
			tail=tail->prev;
		}
		else{
			return false;
		}
	}
	if(count==n/2)	return true;
	else return false;
}
int main(){
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,2);
	cout << isPalindrome(head) << endl;
}