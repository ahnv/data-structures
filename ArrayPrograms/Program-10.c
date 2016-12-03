/*
Reverse last 5 nodes of linked list.
E.g.  Input: 1,2,3,4,5,6,7
Output: 1,2,7,6,5,4,3
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *ptr;
} *start = NULL;

int main(){
	int numberOfNodes;
	struct node *t, *t1, *last;
	scanf("%d", &numberOfNodes);
	for (int i = 0; i < numberOfNodes; i++){
		t = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(t -> data));
		t -> ptr = NULL;
		if (start  == NULL)
			start = t;
		else
			last -> ptr = t;
		last = t;
	}
	printf("\n");
	t = start;
	int i;
	for (i = 0; i < numberOfNodes -5 ; i++){
		t = t->ptr;
	}
	for (; i< numberOfNodes; i++)
	{
		
	}
	t = start;
	for (int i = 0; i < numberOfNodes; i++ , t = t->ptr)
		printf("%d ", t->data);
}