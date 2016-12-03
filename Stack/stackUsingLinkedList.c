#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct stack{ int data; struct stack *ptr;} *top = NULL;

void push(){
  struct stack *t;
  t = (struct stack *)malloc(sizeof(struct stack));
  scanf("%d", &(t -> data));
  t -> ptr = top;
  top = t;
}

int pop(){
  if (top == NULL) printf("UnderFlow");
  struct stack *t;
  t = top;
  top  = top -> ptr;
  int ele = t -> data;
  free(t);
  return (ele);
}

void display(){
  if (top == NULL) printf("List is empty\n"); return;
  struct stack *t;
  for (t = top; ; ){
    printf("%d\n", t -> data);
    if ( t -> ptr == NULL) return;
    t = t -> ptr;
  }
}

int main(){
  int ch;
  menu:
  printf("Enter your choice: \n1. Push \n2. Pop\n3. Display\n4. Exit\n");
  scanf("%d", &ch);
  switch (ch) {
    case 1: push(); goto menu;
    case 2: printf("%d",pop()); goto menu;
    case 3: display(); goto menu;
    case 4: return 0;
    default: goto menu;
  }
}
