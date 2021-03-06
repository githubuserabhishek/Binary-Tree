// Program to Check If a Binary Tree is Binary Search Tree or Not
// Another Approach is to Find Inorder Traversal and Check whether It is Sorted or Not

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
bool isBinarySearchTree(node *);
bool BSTUtil(node *, int, int);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	if(isBinarySearchTree(root))
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}
node *createNode(node *root, int n){

	if(root==NULL){
		node *root=new node;
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(n<root->data)
		root->left=createNode(root->left,n);
	else if(n>root->data)
		root->right=createNode(root->right,n);
}
void inOrder(node *root){

	if(root==NULL) return;
	else{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
bool BSTUtil(node *root, long min, long max){

	if(root==NULL) return true;
	long x=root->data;
	if(x<=min or x>=max) return false;
	return (BSTUtil(root->left,min,x) and BSTUtil(root->right,x,max));
}
bool isBinarySearchTree(node *root){

	return BSTUtil(root, LONG_MIN, LONG_MAX);
}
