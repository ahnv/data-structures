// Binary Search Tree
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

struct node * minValue(struct node * t){
	while(t->l != NULL) t = t -> l;
	return t;
}

struct node * deletion(struct node * root, int ele){
	if (root == NULL) return root;
	else if(ele > root -> data) root -> r = deletion(root->r,ele);
	else if(ele < root -> data) root -> l = deletion(root->l, ele);
	else if(ele == root->data){
		if(root->l == NULL){
			struct node * temp;
			temp = root->r;
			free(root);
			return temp;
		}
		if(root->r == NULL){
			struct node * temp;
			temp = root->l;
			free(root);
			return temp;
		}
		struct node * temp = minValue(root->r);
		root->data = temp->data;
		root->r = deletion(root->r,temp->data); 
	}
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



void printGivenLevel(struct node* root, int level){
		if (root == NULL) return;
		if (level == 1) printf("%d ", root->data);
		else if (level > 1){
				printGivenLevel(root->l, level-1);
				printGivenLevel(root->r, level-1);
		}
}


void display(struct node * root){
			int h = height(root);
			for (int i = 1; i <=h; i++){
				printGivenLevel(root,i);
			}
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