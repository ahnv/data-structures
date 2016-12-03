#include <stdio.h>

int size = 100, front = -1, rear = -1;
int queue[100];

void insertFront(int ele){
	if (front == (rear + 1) % size) printf("Overflow");
	else{ 
		if (rear == -1) rear = front = 0;
		else  front = (rear + 1) % size;
		queue[front] = ele;
	}
}


void insertRear(int ele){
	if (front == (rear + 1) % size) printf("Overflow");
	else{ 
		if (rear == -1) rear = front = 0;
		else  rear = (rear + 1) % size;
		queue[rear] = ele;
	}
}

void delete(){
	if (rear == -1) printf("Underflow\n");
	else if (front == rear) front = rear = -1;
	else front = (front + 1) % size;
}

void display(){
	for (int i = front; front != -1; i = (i + 1) % size){ 
		printf("%d \t", queue[i]);
		if (i == rear) break;
	}
	printf("\n");
}

int main(){
	int n, ch;
	printf("Enter number of elements to add : ");
	scanf("%d", &n);
	for (int i = 0; i < n ; i ++){
		printf("Enter element %d : ", i + 1);
		int a;
		scanf("%d", &a);
		insertRear(a); 
	}
	menu:
	printf("1. Insert Front \n2. Insert Rear \n3. Delete \n4. Print \n5. Exit\n");
	scanf("%d", &ch);
	switch(ch){
		case 1: 
			printf("Enter element :");
			int a;
			scanf("%d", &a);
			insertFront(a); 
			goto menu;
		case 2:
		 	printf("Enter element :");
			int b;
			scanf("%d", &b);
			insertRear(b); 
			goto menu;
		case 3:
			delete();
			goto menu;
		case 4:
			display();
			goto menu;
		case 5:
			return 0;
		default: 
			goto menu;
	}
}
