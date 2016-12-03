//Remove the duplicate elements exits in linked list.

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *ptr;
}*start = NULL;

int main(){
	int numberOfNodes ,count, counter = 0, f=0 ;
	struct node *t, *t1,*temp, *last;
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
	while ( t != NULL){
		t1 = t;
		while (t1->ptr != NULL){
			if (t->data == t1->ptr->data){
				temp = t1->ptr;
				t1->ptr = temp->ptr;
				free(temp);
			}
			else{
				t1 = t1 -> ptr;
			}
		}
		t = t->ptr;
	}
	t = start;
	for (int i = 0; i < numberOfNodes ; i++, t = t->ptr){
		printf("%d\n", t-> data);
	}
	return 0;
}