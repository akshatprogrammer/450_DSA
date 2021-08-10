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
void FindPair(node* first,node* second,int x,int cd){
	while(first!=NULL && second!=NULL && first!=second && second->next!=first){
		if((first->data+second->data) == x){
			cout << "(" << first->data << "," << second->data << "," <<cd << ")" << endl;
			first=first->next;
			second=second->prev;
		}
		else if((first->data+second->data)>x){
			second=second->prev;
		}
		else{
			first=first->next;
		}
	}
	//if(!found) cout << "No pair Found" << endl;
}
void findTriplet(node* head,int x){
	cout << "here";
	if(head==NULL)return;
	node*current,*first,*last=head;
	while(last->next!=NULL){
		last=last->next;	
	}
	for (current = head; current != NULL; current = current->next){
		first=current->next;
		FindPair(first,last,x-current->data,current->data);
	}

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
	findTriplet(head,17);

	return 0;
}
