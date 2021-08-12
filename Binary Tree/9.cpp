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
void LeftViewOfTree(node* root){
	if(root==NULL) return;
	cout << root->data << " ";
	LeftViewOfTree(root->left);
//	cout << root->data << " ";
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