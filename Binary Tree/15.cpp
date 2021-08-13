#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node* right;
	node* left;

	node(int val){
		data=val;
		right=NULL;
		left=NULL;
	}
};
void diagonal(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		while(temp){
			if(temp->left) q.push(temp->left);
			cout << temp->data << " ";
			temp=temp->right;
		}
	}
}
int main(){
	node* root=new node(8);
	root->left=new node(3);
	root->right=new node(10);
	root->left->right=new node(6);
	root->left->left=new node(1);
	root->left->right->right=new node(7);
	root->left->right->left=new node(4);
	root->right->right=new node(5);
	root->right->right->left=new node(2);
	diagonal(root);
}