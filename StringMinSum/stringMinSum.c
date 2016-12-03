//You are given a string let say “saideep”, where s-1,a-1,i-1,e-2,d-1,p-1 is the frequency of each character. Now the value of the string is defined as sum of squares of count of each distinct character. For the above string the value is 1+1+1+1+1+4=9. Now given an integer k your task is to print the min value of the string after removal of ‘k’ characters.

#include <string.h>
#include <malloc.h>

struct freq{
  char a;
  int count;
  struct freq *next;
} *start = NULL;

int main(){
  int te, k, len, i, f = 0, val = 0, max;
  struct freq *t, *t2, *last;
  char str[50];
  scanf("%d", &te);
  for(;te > 0; te--){
    scanf("%s", str);
    scanf("%d", &k);
    for(len=0; str[len] != '\0'; len++);
    for(i=0; i<len; i++){
      if (start == NULL){
        t = (struct freq *)malloc(sizeof(struct freq));
        t -> a = str[i];
        t -> count = 1;
        t -> next = NULL;
        start = t;
      }
      else {
        f = 0;
        t = t2 = start;
        for ( ; t2 -> next != NULL; t2 = t2 -> next){ if (t2 -> a == str[i]){ f = 1; } }
        if(t2 ->  a == str[i]){ f = 1; t2 = t2 -> next; }
        if (f == 1){ (t -> count)++; }
        if (f == 0){
          t = (struct freq *)malloc(sizeof(struct freq));
          t -> a = str[i];
          t -> count = 1;
          t -> next = NULL;
          t2 -> next  = t ;
        }
      }
    }
    t = start;
    for ( ; t != NULL; t = t -> next){ val += (t -> count)*(t -> count); }
    for (int  i = 0; i < k ; i++){
       t = t2 = start;
       max = t -> count;
       t = t -> next;
       for (;t != NULL; t = t -> next){
         if (t -> count > max){ t2 = t;break;}
       }
       (t2 -> count)--;
    }
    val = 0;
    t = start;
    for ( ; t != NULL; t = t -> next){ val += (t -> count)*(t -> count); }
    printf("%d\n", val);
  }
}
