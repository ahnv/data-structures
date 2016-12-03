#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node{ int data; struct node *ptr; } *start = NULL, *last, *p;

void push(int e){
  struct node *t;
  t = (struct node *)malloc(sizeof(struct node));
  t -> data = e;
  if (start == NULL) start = t;
  else last -> ptr = t;
  t -> ptr = start;
  last = t;
}

int survivor(int k){
  int i;
  struct node *temp;
  p = temp = start;
  while (p -> ptr != p){
    for (int i = 0; i < k-1;i++){
      p = temp;
      temp = temp -> ptr;
    }
    p -> ptr = temp -> ptr;
    printf("%d\tis Dead\n", temp -> data);
    free(temp);
    temp = p -> ptr;
  }
  start = p;
  return (p->data);
}

int main(){
  int n, s, c = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) push(i);
  printf("c = %d ", c);
  printf("Enter Skip : ");
  scanf("%d", &s);
  printf(" Survivor is : %d \n",survivor(s) );
}
