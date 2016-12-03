#include <stdio.h>

int size = 100, front = -1, rear = -1;
int queue[100];

void insert(int ele){
	if (front == (rear + 1) % size) printf("Overflow");
	else{ 
		if (rear == -1) rear = front = 0;
		else  rear = (rear + 1) % size;
		queue[rear] = ele;
	}
}

void deleteFront(){
	if (rear == -1) printf("Underflow\n");
	else if (front == rear) front = rear = -1;
	else front = (front + 1) % size;
}

void deleteRear(){
	if (rear == -1) printf("Underflow\n");
	else if (front == rear) front = rear = -1;
	else rear = (rear + size - 1) % size;
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
		insert(a); 
	}
	menu:
	printf("1. Insert \n2. Delete Front \n3. Delete Rear \n4. Print \n5. Exit\n");
	scanf("%d", &ch);
	switch(ch){
		case 1: 
			printf("Enter element :");
			int a;
			scanf("%d", &a);
			insert(a); 
			goto menu;
		case 2:
			deleteFront();
			goto menu;
		case 3:
			deleteRear();
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
