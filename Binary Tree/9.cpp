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
void LeftViewOfTree(node* root){
	if(root==NULL) return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=1;i<n+1;i++){
			node* curr=q.front();
			q.pop();
			if(i==1)
				cout << curr->data << " ";
			if(curr->left!=NULL)
				 q.push(curr->left);
			if(curr->right!=NULL) 
				q.push(curr->right);
		}
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
	LeftViewOfTree(root);

}