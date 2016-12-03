// Reverse the linked list by changing the link of the nodes only.

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
} *start;


int main(){
	int numberOfNodes;
	struct node *t, *prev, *temp, *last;
	scanf("%d", &numberOfNodes);
	for (int i = 0; i < numberOfNodes; i++){
		t = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(t -> data));
		t -> next = NULL;
		if (start  == NULL)
			start = t;
		else
			last -> next = t;
		last = t;
	}
	t = start;
	prev = NULL;
	while (t!= NULL)
	{
		temp = t -> next;
		t -> next = prev;
		prev = t;
		t = temp;
	}
	start = prev;
	t = start;
	for (int i = 0; i < numberOfNodes; i++ , t = t->next)
		printf("%d ", t->data);
}
