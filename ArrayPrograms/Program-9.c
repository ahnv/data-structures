// There are two linked lists. Perform the addition and store in the third linked list.

#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *ptr;
}*start1 = NULL, *start2 = NULL, *startr = NULL;

int main(){
	int n1,n2 ,count, counter = 0, f=0, i ,j;
	struct node *t1, *t2, *tr, *last;
	printf("Enter First Node");
	scanf("%d", &n1);
	printf("Enter First Node");
	for (i = 0; i < n1; i++){
		t1 = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(t1 -> data));
		t1 -> ptr = NULL;
		if (start1  == NULL)
			start1 = t1;
		else
			last -> ptr = t1;
		last = t1;
	}
	printf("Enter Second Node");
	scanf("%d", &n2);
	printf("Enter Second Node");
	for (int i = 0; i < n2; i++){
		t2 = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(t2 -> data));
		t2 -> ptr = NULL;
		if (start2  == NULL)
			start2 = t2;
		else
			last -> ptr = t2;
		last = t2;
	}
	i = 0;
	j = 0;
	t1 = start1;
	t2 = start2;
	while (i < n1 && j < n2){
		tr = (struct node *)malloc(sizeof(struct node));
		tr -> data = t1 ->data + t2 -> data;
		tr -> ptr = NULL;
		if (startr == NULL)
			startr = tr;
		else
			last -> ptr = tr;
		last = tr;
		t1 = t1 -> ptr;
		t2 = t2 -> ptr;
		i++;j++;	
	}
	while (i < n1){
		tr = (struct node *)malloc(sizeof(struct node));
		tr -> data = t1 -> data;
		tr -> ptr = NULL;
		if (startr == NULL)
			startr = tr;
		else
			last -> ptr = tr;
		last = tr;
		t1 = t1-> ptr;
		i++;
	}
	while (j < n2){
		tr = (struct node *)malloc(sizeof(struct node));
		tr -> data = t2 -> data;
		tr -> ptr = NULL;
		if (startr == NULL)
			startr = tr;
		else
			last -> ptr = tr;
		last = tr;
		t2 = t2-> ptr;
		j++;
	}
	tr = startr;
	i = 0;
	(n1 > n2) ? (j = n1) : (j = n2) ; 
	while (i < j){
		printf("%d ", tr->data);
		tr = tr -> ptr; i++;
	}

}	