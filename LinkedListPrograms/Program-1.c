#include <stdio.h>
#include <malloc.h>

struct polynomial{
	int coefficient, exponent;
	struct polynomial *next;
} *s1 = NULL, *s2 = NULL, *ss = NULL, *sd = NULL;

void display(struct polynomial *p){
	do{
		printf("%d*x^%d + ", p -> coefficient, p -> exponent);
		p = p -> next;
	}while ( p -> next != NULL);
	printf("%d*x^%d ", p -> coefficient, p -> exponent);
}

void add(){
	struct polynomial *t, *last, *t1, *t2;
	t1 = s1; t2 = s2;
	for (int i = 3; i > -1 ; i--){
		t = (struct polynomial *)malloc(sizeof(struct polynomial));
		t -> coefficient = t1 -> coefficient + t2 -> coefficient;
		t -> exponent = t1 -> exponent;
		if (ss == NULL)
			ss = t;
		else
			last -> next = t;
		last = t;
	}
}

void diff(){
	struct polynomial *t, *last, *t1, *t2;
	t1 = s1; t2 = s2;
	for (int i = 3; i > -1 ; i--){
		t = (struct polynomial *)malloc(sizeof(struct polynomial));
		t -> coefficient = t1 -> coefficient - t2 -> coefficient;
		t -> exponent = t1 -> exponent;
		if (sd == NULL)
			sd = t;
		else
			last -> next = t;
		last = t;
		t1 = t1 -> next;
		t2 = t2 -> next;
	}
}

int main(){
	struct polynomial *t, *last;
	printf("Enter Polynomial 1 : \n");
	for (int i = 3; i > -1 ; i--){
		t = (struct polynomial *)malloc(sizeof(struct polynomial));
		printf("Enter coefficient of term with power %d :", i );
		scanf("%d", &(t->coefficient));
		t -> exponent = i;
		t -> next = NULL;
		if (s1 == NULL)
			s1 = t;
		else
			last -> next = t;
		last = t;
	}
	display(s1);
	last = NULL;
	printf("\nEnter Polynomial 2 : \n");
	for (int i = 3; i > -1 ; i--){
		t = (struct polynomial *)malloc(sizeof(struct polynomial));
		printf("Enter coefficient of term with power %d :", i );
		scanf("%d", &(t->coefficient));
		t -> exponent = i;
		t -> next = NULL;
		if (s2 == NULL)
			s2 = t;
		else
			last -> next = t;
		last = t;
	}
	display(s2);
	printf("\nSum is : ");
	add();
	display(ss);
	printf("\nDifference is : ");
	diff();
	display(sd);
	printf("\n");

	return 0;
}
