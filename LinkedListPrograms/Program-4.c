#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node {
  int data;
  struct node *pre, *next;
} *start = NULL;

int main(){
  struct node *t, *last, *temp;
  int numberOfNodes, pos;
  scanf("%d", &numberOfNodes);
  for (int i=0; i < numberOfNodes; i++){
    t = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &(t -> data));
    if (start == NULL){
      start = t;
      t -> next = start;
      t -> pre  = start;
    }
    else{
      last -> next = t;
      t -> pre = last;
      t -> next = start;
      start -> pre  = last;
    }
    last =t;
  }
  t =start;
  for (; t != NULL; t = t -> next)
    printf("%d\t", t -> data);
  scanf("%d", &pos);
  temp = (struct node *)malloc(sizeof(struct node));
  scanf("%d", &(temp -> data));
  if (pos == 1){
    temp -> pre = start;
    temp -> next = start -> next;
    start = temp;
  }
  else{
    t = start;
    for (int i= 1; i < pos-1;i++){
      t = t -> next;
    }
    temp -> pre = t;
    temp -> next  = t -> next;
    t -> next = temp;
    (temp -> next) -> pre = temp;
  }
  t =start;
  for (; t != NULL; t = t -> next)
    printf("%d\t", t -> data);
}
