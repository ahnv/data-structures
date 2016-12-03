#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node
{
	int data;
	struct node *ptr;
} *start = NULL , *start2 = NULL;

int main(){
    struct node *t, *t2 , *last;
    int a1[5] = {3,6,9,15,30}, a2[3] = {10,15,30}, i, j, intersect ,f=0;
    for (i = 0 ; i < 5; i++){
      for (j = 0; j < 3 ; j++){
        if (a1[i] == a2[j]){
          intersect = a1[i];
          f = 1;
          break;
        }
      }
      if (f ==1) break;
    }
    for (i = 0; i < 5; i++){
      t = (struct node *)malloc(sizeof(struct node));
      t -> data = a1[i];
      t -> ptr = NULL;
      if (start == NULL)
        start = t;
      else
        last -> ptr = t;
      last = t;
    }
    for (j = 0; a2[j] != intersect; j++){
      t = (struct node *)malloc(sizeof(struct node));
      t -> data = a2[j];
      t -> ptr = NULL;
      if (start2 == NULL)
        start2 = t;
      else
        last -> ptr = t;
      last = t;
    }
    t = start;
    for ( ; t -> data != intersect; t = t -> ptr);
    last -> ptr = t;
    t = start;
    for (;t != NULL; t = t -> ptr){
      t2 =start2;
      for (; t2 != NULL; t2 = t2 -> ptr){
        if (t -> ptr == t2 -> ptr){
            printf("Intersection is %d\n", (t -> ptr) -> data );
            return 0;
        }
      }
    }

}
