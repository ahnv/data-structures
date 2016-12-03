#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str) return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;*p2 ^= *p1;*p1 ^= *p2;
      }
      return str;
}

struct stack{ char data; struct stack *ptr; } *top = NULL;

void push(char c){
  struct stack *t;
  t = (struct stack *)malloc(sizeof(struct stack));
  t -> data = c; t -> ptr = top; top = t;
  printf("Element Pushed : %c \n", c);
}

char pop(){
  char ele;
  if (top == NULL){ printf("UnderFlow"); return -1; }
  struct stack *t;
  t = top; top  = top -> ptr; ele = t -> data;
  printf("Element Popped : %c \n", ele);
  free(t);
  return (ele);
}


int prioritize(char c1, char c2){
  char symbols[12] = {'#','+','-','*','/','[',']','{','}','(',')','^'};
  int  num[12]     = { 5 , 1 , 1 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 4 };
  int a1,a2;
  for (int i = 0; i < 12; i++) if (symbols[i] == c1) a1 = num[i];
  for (int i = 0; i < 12; i++) if (symbols[i] == c2) a2 = num[i];
  if (a1 > a2) return 1;
  return 0;
}

void convert(char s[], int size){
  int j = 0;
  char sol[100];
  char *r;
  r = strrev(s);
  for (int i = 0; i < size; i++){
    char ch = r[i];
    if (isalnum(ch)) sol[j++] = ch;
    else{
      while(prioritize(top -> data,ch) == 0) sol[j++] = pop();
      push(ch);
    }
  }
  do{ sol[j++] = pop(); }while(top -> data != '#');
  printf("%s\n", strrev(sol));
}

int main(){
  char string[100];
  char *s;
  int len;
  scanf("%s", string);
  for ( len = 0; string[len] != '\0' ; len++);
  push('#');
  convert(string,len);
}
