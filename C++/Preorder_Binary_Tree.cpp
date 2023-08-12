//Write ‘C’ program to implement any one recursive Tree Traversal on Binary Tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* l;
	struct node* r;
};
struct node* newNode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->l=NULL;
	node->r=NULL;
	return(node);
}
void Display(struct node* node)
{ 
	if(node==NULL)
		return;
	printf("%d ", node->data);
	Display(node->l);
	Display(node->r);
}
int main()
{
	struct node *root=newNode(1);
	root->l=newNode(2);
	root->r=newNode(3);
	root->l->l=newNode(4);
	root->l->r=newNode(5);
	printf("Preorder traversal of binary tree is \n");
	Display(root);
	return 0;
}
