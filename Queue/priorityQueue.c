#include <stdio.h>
#include <malloc.h>

struct queue { int data, prio; struct queue *ptr; } *front = NULL, *rear = NULL;

void insert(){
	printf("Enter Element \n");
	struct queue *t, *t2;
	int e, p;
	printf("Enter Data ");
	scanf("%d", &e);
	printf("Enter Priority ");
	scanf("%d", &p);
	t = (struct queue *)malloc(sizeof(struct queue));
	t->data = e;
	t->prio = p;
	if (front == NULL) { front = t;  rear = t; rear -> ptr = NULL; }
	else {
		for (t2 = front; t2 -> prio >= t->prio; t2 = t2->ptr);
		t -> ptr = t2 -> ptr; t2 -> ptr = t;
	}
}

int delete(){
	struct queue *t;
	int e;
	t = front;
	front = front -> ptr;
	e = t-> data;
	return e;
}

void display(){
	struct queue *t;
	for (t = front ;t != NULL; t = t-> ptr) printf("%d | %d \t", t -> data, t-> prio); 
}

int main(){
	int ch, n;
	scanf("%d", &n);
	for (int i = 0 ; i < n; i++) insert();
  	menu:
  	scanf("%d", &ch);
  	switch(ch){
	case 1: insert(); goto menu;
    	case 2: printf("Element removed %d",delete()); goto menu;
    	case 3: display(); goto menu;
    	case 4: break;
  	}
  	return 0;
}