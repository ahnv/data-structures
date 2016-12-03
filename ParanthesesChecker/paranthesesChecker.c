#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct stack{ char data; struct stack *ptr; } *top = NULL;

void push(char c){
  struct stack *t;
  t = (struct stack *)malloc(sizeof(struct stack));
  t -> data = c; t -> ptr = top; top = t;
}

char pop(){
  if (top == NULL) printf("UnderFlow");
  struct stack *t;
  t = top;
  top  = top -> ptr;
  char ele = t -> data;
  free(t);
  return (ele);
}

void display(){
  if (top == NULL) printf("List is empty\n"); return;
  struct stack *t;
  for (t = top; ; ){
    printf("%c\n", t -> data);
    if ( t -> ptr == NULL) return;
    t = t -> ptr;
  }
}

int check(char arr[], int s){
  for (int i = 0 ; i <=s ;i++){
    char c = arr[i];
    if (c == '[' || c == '(' || c == '{') {push(c); display();}
    else if(c == ')'){ if (pop() != '(') return 0; }
    else if(c == '}') if (pop() != '{') {display();return 0;}
    else if(c == ']') if (pop() != '[') {display();return 0;}
  }
  if (top == NULL) return 1;
  else return 0;
}

int main(){
  int size;
  scanf("%d", &size);
  char arr[size];
  for (int i = 0; i < size; i++)
  scanf(" %c", &arr[i]);
  printf(" %s ", check(arr,size) ? "Parantheses are closed properly" : "Parantheses are not closed properly");
}
