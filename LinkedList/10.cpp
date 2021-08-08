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
void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}
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
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data;
        temp=temp->next;
    }cout <<  endl;
}
node* reverse(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node* recursiveAdd(node* head1,node* head2){
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;

    int sum = head1->data+head2->data;
    node* finalLL=new node(sum%10);
    finalLL->next=recursiveAdd(head1->next,head2->next);
    if(sum>=10)
        finalLL->next=recursiveAdd(finalLL->next,new node(1));
    return finalLL;
}
node* addTwoLL(node* head1,node* head2){
   /* if(m>n){
        for(int i=0;i<abs(m-n);i++){
            insertAtHead(head1,0);
        }
    }
    else{
        for(int i=0;i<abs(m-n);i++){
            insertAtHead(head2,0);
        }
    }
    node* a = reverse(head1);
    display(a);
    node* b = reverse(head2);
    display(b);
    node* sum;
    int res=0;
    do{
        res = a->data + b->data;
        if(res >= 10){
            res=res%10;
            a->next->data+=1;
           /* if(a->data!=9 && b->data==9){
                a->data+=1;
            }
            else if(a->data!=9 && b->data==9){
                b->data+=1;
            } */
      /*  }
        sum=sum->next;
        insertAtTail(sum,res);

        a=a->next;
        b=b->next;
    }while(a!=NULL && b!=NULL);
    sum=reverse(sum);
    display(sum);
    */
    head1=reverse(head1);
    head2=reverse(head2);

    return reverse(recursiveAdd(head1,head2));
}
int main(){
    int n,m,ele;
    cin >> n >> m;
    node* head1=NULL;
    node* head2=NULL;

    for(int i=0;i<n;i++)
    {
        cin >> ele;
        insertAtTail(head1,ele);
    }
    for(int i=0;i<m;i++)
    {
        cin >> ele;
        insertAtTail(head2,ele);
    }
    node* newhead=addTwoLL(head1,head2);
    display(newhead);
}
