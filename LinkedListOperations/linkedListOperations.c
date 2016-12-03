#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node{ int data; struct node *ptr; } *start = NULL;

void insert(struct node *s){
	int pos;
	struct node *temp, *t;
	temp = (struct node *)malloc(sizeof(struct node));
	t = (struct node *)malloc(sizeof(struct node));
	printf("Enter Data "); scanf("%d", &(temp -> data));
	printf("Enter Position of the node to be inserted "); scanf("%d", &pos);
	if ( pos == 1){ temp -> ptr = start; start = temp; }
	else{
		t = start;
		for (int i = 1; i < pos-1; i ++){
			if (t -> ptr == NULL) break; t = t -> ptr;
		}
		temp -> ptr = t -> ptr;
		t -> ptr = temp;
	}
}

void display(struct node *s){
	struct node *t; t = s;
	do {
		printf("%d\t", t -> data);t = t ->ptr;
	}while(t -> ptr != NULL);
	printf("%d\n", t ->data);
}

void search(struct node *s){
	struct node *t;t = s;
	int search, counter = 0;
	printf("Enter Value you want to find "); scanf("%d", &search);
	do{
		if (t -> data == search) printf("%d at Position %d\n",  t -> data, counter + 1);
		t = t ->ptr;
		counter++;
	}while(t -> ptr != NULL);
	if (t -> data == search) printf("%d\t at Position %d", t ->data, counter + 1);
}

void delete(struct node *s){
	int pos;
	struct node *temp, *t, * t2;
	temp = (struct node *)malloc(sizeof(struct node));
	t = (struct node *)malloc(sizeof(struct node));
	t2 = (struct node *)malloc(sizeof(struct node));
	printf("Data entered is "); display(s); printf("\n");
	printf("Enter Position from which you want to delete data "); scanf("%d", &pos);
	t = start;
	if ( pos == 1) start = t -> ptr;
	else{
		for (int i = 1; i < pos - 1; i ++)
			if (t -> ptr != NULL) t = t -> ptr;
			else return;
		t2 = t -> ptr;
		t -> ptr = t2 -> ptr;
	}
	printf("Final Data is ");
	display(start);
	printf("\n");
	free(t2);
}

int  main()
{
	int choice, numberOfNodes, count = 0 ;
	struct node *t, *t1, *last;
	char ch; clrscr(); printf("Enter the Number of nodes you want to enter: ");
	scanf("%d", &numberOfNodes);
	do{
		if (numberOfNodes == 0) break;
		ch = 'y';
		t = (struct node *)malloc(sizeof(struct node));
		printf("Enter Data for Node: ");
		scanf("%d", &(t -> data));
		t -> ptr = NULL;
		if (start == NULL) start = t;
		else last -> ptr = t;
		last = t;
		count++;
		if (count  >= numberOfNodes){
			printf("Do you want to add More?");
			clean_stdin();
			scanf("%c", &ch);
		}
	}while(ch == 'Y' | ch == 'y');
	if (start == NULL){ printf("LIST NOT FOUND\n"); return 404; }
	clrscr();
	menu:
		printf("Select One of the Following:\n1. Insert to List\n2. Delete from List\n3. Search\n4. Display\n5. Exit");
		scanf("%d", &choice);
		switch(choice){
			case 1:	clrscr(); insert(start); goto menu;
			case 2:	clrscr(); delete(start); goto menu;
			case 3:	clrscr(); search(start); goto menu;
			case 4:	clrscr(); display(start);goto menu;
			case 5: 	return 0;
			default:	goto menu;
		}
	return 0;
}
