#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node{
	int data;
	struct node *next;
} *start = NULL;

int main(){
	int choice, numberOfNodes, count = 0;
	struct node *t, *last, *p;
	char ch;
	clrscr();
	printf("Enter the Number of nodes you want to enter: ");
	scanf("%d", &numberOfNodes);
	do{
		if (numberOfNodes == 0)
		{
			break;
		}
		ch = 'y';
		t = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data for Node: ");
		scanf("%d", &(t -> data));
		t -> next = NULL;
		if (start == NULL){
			start = t;
		}
		else
			last -> next = t;
		last = t;
		count++;
		if (count  >= numberOfNodes){
			printf("Do you want to add More?");
			clean_stdin();
			scanf("%c", &ch);
		}
	}while(ch == 'Y' | ch == 'y');
	t = start;
	p = start;
	while (t != NULL && p != NULL){
		if (p -> next == NULL) break;
		if (p -> next != NULL)
			p = (p -> next) -> next;
		t = t -> next;
	}
	printf("Middle element is %d \t", t -> data );
}
