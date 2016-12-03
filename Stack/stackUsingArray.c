#include <stdio.h>
#include <custom.h>

int stack[100], top  = -1;

void push(){
  if (top == 99) printf("Overflow"); return;
  int element;
  printf("Enter Element: ");
  scanf("%d", &element);
  stack[++top] = element;
}

void pop(){
  if (top == -1){ printf("UnderFlow\n"); return; }
  printf("%d is poped from the list", stack[top--]);
}

void display(){
  printf("List is \n");
  for (int i = top ; i > - 1; i--) printf("%d\n", stack[i]);
  printf("\n");
}

int main(){
  int ch;
  menu:
  printf("Enter your choice: \n1. Push \n2. Pop\n3. Display\n4. Exit\n");
  scanf("%d", &ch);
  switch (ch) {
    case 1: push(); goto menu;
    case 2: pop(); goto menu;
    case 3: display(); goto menu;
    case 4: return 0;
    default: goto menu;
  }
}
