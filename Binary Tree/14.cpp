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
int isBalancedCheck(node* root){
	if(root==NULL) return 0;
	int lh=isBalancedCheck(root->left);
	if(lh==-1) return -1;
	int rh=isBalancedCheck(root->right);
	if(rh==-1) return -1;
	if(abs(rh-lh)>1) return -1;
	
	return max(rh,lh)+1;
}
bool isBalanced(node* root){
	if(isBalancedCheck(root)==-1)
		return false;
		
	return true;
}
int main(){
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->right=new node(5);
	root->left->left=new node(4);
	cout << isBalanced(root) << endl;
}