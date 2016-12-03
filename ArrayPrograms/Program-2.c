/*	
Given a singly linked list, swap every 2 nodes, for odd number of input; retain the last node as it is.
Eg: Input: 5 13 15 18 20 11 6 7
Output: 13 5 18 15 11 20 7 6
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
	int c = numberOfNodes;
	if (c % 2 != 0)
		c--;
	for (int i = 0; i < c ; i = i + 2)
	{
		t1 = t -> ptr;
		int temp = t -> data;
		t -> data = t1->data;
		t1 -> data = temp;
		t = t1 ->ptr;
	}
	t = start;
	for (int i = 0; i < numberOfNodes; i++ , t = t->ptr)
		printf("%d ", t->data);
}