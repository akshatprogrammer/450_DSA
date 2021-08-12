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
int calDia(node* root,int* height){
	if(root==NULL){
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int ld=calDia(root->left,&lh);
	int rd=calDia(root->right,&rh);
	int cd=ld+rd+1;
	*height=max(lh,rh)+1;

	return max(cd,max(ld,rd));
}
int main(){
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
//	root->left->left=new node(4);
	//root->left->right=new node(5);
	//root->right->left=new node(6);
	//root->right->right=new node(7);
	int height=0;
	cout << calDia(root,&height);
}