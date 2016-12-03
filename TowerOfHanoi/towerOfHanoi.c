#include <stdio.h>
#include <malloc.h>

struct node { int data; struct node *ptr; } *s = NULL, *m = NULL, *d = NULL;

struct node * push(struct node *t, int ele){
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp -> data = ele;
  temp -> ptr = t;
  t = temp;
  return temp;
}

int pop(struct node *t){
  int element;
  struct node *temp;
  temp = t;
  element = t -> data;
  t = temp -> ptr;
  free(temp);
  return element;
}

void display(struct node *t){
  struct node *temp;
  temp = t;
  while (temp != NULL){
    printf("%d\n", temp -> data);
    temp = temp -> ptr;
  }
}

void toh(int n, struct node *a, struct node *b, struct node *c ){
  if (n == 1){ int e = a -> data; push(c,e); return; }
  toh(n-1,a,c,b);
  int e = pop(a);
  push(c,e);
  toh(n-1,b,a,c);
}

int main() {
  int n, i;
  
  printf("Enter max number of disks : "); scanf("%d", &n); printf("\n");

  for ( i = 1 ; i <= n ; i++ ) s = push(s,i);
  
  printf("Source = \n"); display(s);
  printf("Middle = \n"); display(m);
  printf("Destination = \n"); display(d);
  
  toh(n,s,m,d);
  
  printf("Source = \n"); display(s);
  printf("Middle = \n"); display(m);
  printf("Destination = \n"); display(d);

  return 0;
}
