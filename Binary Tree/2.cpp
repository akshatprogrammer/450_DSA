#include<iostream>
#include<queue>
#include<stack>
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
void reverseOrderTraversal(node* root){
	if(root==NULL) return;
	queue<node*> q;
	stack<int>s;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if(temp!=NULL){
			s.push(temp->data);
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		else if(!q.empty()){
			q.push(NULL);
		}
	}
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}
int main(){
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	reverseOrderTraversal(root);

}