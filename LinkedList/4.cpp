void deleteloop(node* &head){
	node* slow=head;
	node* fast=head;
	do{
		slow=slow->next;
		fast=fast->next->next;
	}while(fast!=slow);

	fast=head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}