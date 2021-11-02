#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
node* str2Tree(string s,int* start){
	if(s.size()==0 || *start>s.size()) return NULL;

	int num;
	while(*start<s.size()&&s[*start]!='(' && s[*start]!=')'){
		num=(int)(s[*start]-'0');
		*start+=1;
	}

	node* root=new node(num);
	if(*start>s.size()) return root;



	if(*start<s.size()&&s[*start]=='('){
		*start+=1;
		root->left=str2Tree(s,start);
	}
	if(*start<s.size()&&s[*start]==')')
		*start+=1;



	if(*start<s.size()&&s[*start]=='('){
		*start+=1;
		root->right=str2Tree(s,start);
	}
	if(*start<s.size()&&s[*start]==')')
		*start+=1;


	return root;
}
void displayPreOrder(node* head){
	if(head==NULL)return;
	cout << head->data << " ";
	displayPreOrder(head->left);
	displayPreOrder(head->right);
}
int main(){
	int start=0;
	string s;
	cin >> s;

	node* head=str2Tree(s,&start);
	displayPreOrder(head);
}