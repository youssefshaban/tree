#include<stdio.h>
#include<alloc.h>
#include<conio.h>

struct node {
	int data ;
	struct node* left;
	struct node* right;
};
void print_in_order(struct node* pNode) ;
void print_post_order(struct node* pNode);
struct node* CreateNode(int data);
struct node* insertNode(struct node* pNode,int data);
void print_Pre_order(struct node* pNode) ;
int main ()  {


	struct node* pRoot=NULL;
	pRoot = insertNode(pRoot,1);
	insertNode(pRoot,2);
	insertNode(pRoot,3);
	insertNode(pRoot,4);
	insertNode(pRoot,5);
	printf(" Pre_Order : ");
	print_Pre_order(pRoot);
	printf("\n In_Order : ");
	print_in_order(pRoot);
	printf("\n Post_Order : ");
	print_post_order(pRoot);
	gotoxy(5,5);
	printf("--- Thank You ---");
	getch();
	clrscr();
	return 0;
}
struct node* CreateNode(int data){
	struct node* pointer;
	pointer= (struct node*)malloc(sizeof(struct node));
	if(pointer){

		pointer->data=data;
		pointer->left=pointer->right=NULL;
	}
	return pointer;
}
struct node* insertNode(struct node* pNode,int data){
	if(pNode==NULL){
		return(CreateNode(data));
	}
	else{

		if(data<=pNode->data){
			pNode->left=insertNode(pNode->left,data);
		}
		else {
			pNode->right = insertNode(pNode->right,data);
		}
	}
	return pNode;
}
void print_Pre_order(struct node* pNode){
	if(pNode->left==NULL){
		if(pNode->right==NULL){
	      //	printf("%d ",pNode->data);
		}
		else{
		print_Pre_order(pNode->right);
		}
	printf("%d ",pNode->data);

	}else{
		print_Pre_order(pNode->left);

	}


}
void print_in_order(struct node* pNode){
	if(pNode->left==NULL){
		printf("%d ",pNode->data);
		if(pNode->right==NULL){
	      //	printf("%d ",pNode->data);
		}
		else{
		print_Pre_order(pNode->right);
		}


	}else{
		print_Pre_order(pNode->left);

	}
}
void print_post_order(struct node* pNode){
	if(pNode->left==NULL){
	     //	printf("%d ",pNode->data);
		if(pNode->right==NULL){
		printf("%d ",pNode->data);
		}
		else{
		print_Pre_order(pNode->right);
		printf ("%d ",pNode->data);
		}


	}else{
		print_Pre_order(pNode->left);

	}
}
