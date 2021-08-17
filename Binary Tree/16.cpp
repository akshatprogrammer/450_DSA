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
void printLeft(node* root){
	if(root==NULL) return;
	if(root->left){
		cout << root->data << " ";
		printLeft(root->left);
	}
	else if(root->right){
		cout << root->data << " ";
		printLeft(root->right);
	}
}
void printRight(node* root){
	if(root==NULL) return;
	if(root->right){
		cout << root->data << " ";
		printLeft(root->right);
	}
	else if(root->left){
		cout << root->data << " ";
		printLeft(root->left);
	}
}
void printL2R(node* root){
	if(root==NULL) return;
	printL2R(root->left);
	if(!(root->left)&&!(root->right))
		cout << root->data << " ";
	printL2R(root->right);
}
void printBoundary(node* root){
	if(root==NULL) return;

	cout << root->data << " ";

	printLeft(root->left);

	printL2R(root->left);
	printL2R(root->right);

	printRight(root->right);
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
	printBoundary(root);
}