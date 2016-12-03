//Calculate the frequency of the numbers in a given Linked List.

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *ptr;
}*start = NULL;

int main(){
	int numberOfNodes ,count, counter = 0, f=0 ;
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
	t = start;
	int done[numberOfNodes];
	for (int i = 0; i < numberOfNodes ; i ++)
	{
		for (int k = 0 ; k < counter; k++)
		{
			if (done[k] == t -> data){
				t = t -> ptr;
				f =1;
			}
		}
		if (f == 1)
			continue;
		t1 = start;
		count = 0 ;
		for (int j = 0; j < numberOfNodes ; j++)
		{
			if (t->data == t1 -> data)
				count++;
			t1 = t1 -> ptr;
		}
		done[counter] = t->data;
		counter++;
		printf("%d occurs %d times\n", t->data, count);
		t = t -> ptr;
	}
	return 0;
}