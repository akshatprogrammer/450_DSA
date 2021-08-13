#include<iostream>
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
void zigzag(node* root){
	if(root==NULL) return;
	stack<node*> currLvl;
	stack<node*> nextLvl;
	currLvl.push(root);
	bool left2right=true;

	while(!currLvl.empty()){
		node* temp=currLvl.top();
		currLvl.pop();
		if(temp!=NULL){
			cout << temp->data << " ";	
		if(left2right){
			if(temp->left!=NULL) nextLvl.push(temp->left);
			if(temp->right!=NULL) nextLvl.push(temp->right);
		}
		else{
			if(temp->right!=NULL) nextLvl.push(temp->right);
			if(temp->left!=NULL) nextLvl.push(temp->left);
		}
	}
		if(currLvl.empty()){
			left2right=!left2right;
			swap(currLvl,nextLvl);
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
	zigzag(root);

}