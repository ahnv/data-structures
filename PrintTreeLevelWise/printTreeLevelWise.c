#include <stdio.h>
#include <malloc.h>

struct node { int data; struct node *l, *r; } *parentRoot = NULL;

struct node * insertion(struct node * root, int ele){
	if (root == NULL){
		struct node *t = (struct node *)malloc(sizeof(struct node));
		t -> data = ele;
		t -> l = t -> r = NULL;
		return t;
	}
	else if (ele > root -> data) root -> r = insertion(root->r,ele);
	else if (ele < root -> data) root -> l  = insertion(root->l,ele);
	return root;
}

int height (struct node * t){
	int lh, rh;
	struct node *tmp = t;
	if (t == NULL)  return 0;
	for (lh = 1 ; tmp != NULL; lh++, tmp = tmp->l);
	for (lh = 1 ; tmp != NULL; lh++, tmp = tmp->l);
	return (lh > rh) ? lh : rh;
}

int main(){
	int ch, element, n;
	menu:
	printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: 
				printf("Enter Element : ");
				scanf("%d",&n);
				parentRoot = insertion(parentRoot,n);
				printf("\n");
				goto menu;
		case 2:
				printf("Enter Element to delete : ");
				scanf("%d",&element);
				deletion(parentRoot,element);
				printf("\n");
				goto menu;
		case 3:
				printf("The Binary Tree is : ");
				display(parentRoot);
				printf("\n");
				goto menu;
		case 4: return 0;
		default: goto menu;   
	}
}