#include<iostream>
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
void display(node* root){
	if(root==NULL) return;
	display(root->left);
	cout << root->data << " ";
	display(root->right);
}
node* mirrorOfTree(node* &root){
	if(root==NULL) return root;
	//root=root->left;
		node* temp=root->left;
		root->left=root->right;
		root->right=temp;
	if (root->left)
        mirrorOfTree(root->left);
    if (root->right)
        mirrorOfTree(root->right);

   return root;
	
}
int main(){
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	mirrorOfTree(root);
	display(root);
	cout << endl;
}