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
void startingPoint(node* head){
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow->next!=fast->next);

	fast=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	cout << slow->next->data << endl;
} 
void checkLoop(node* head){
	node* slow=head;
	node* fast=head;
	while(fast->next!=NULL&&fast!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			startingPoint(head);
			return;
		}
	}
	cout << "NO LOOP FOUND\n";

}
int main(){
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	head->next->next->next->next->next=head->next;
	checkLoop(head);


}