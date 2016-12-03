#include <stdio.h>
#include <malloc.h>

int queue[100], size,f,e;

void insert(){
  int ele;
  printf("Enter Number to be inserted : ");
  scanf("%d", &ele);
  if (f == -1) f++;
  queue[++e] = ele;
}
void delete(){ if (f == e) f = e = -1; else f++; }
void display(){ for (int i = f; i <= e ;i++) printf("%d ", queue[i]); }

int main(){
  int ch;
  f = e = -1;
  printf("Enter Size of Array");
  scanf("%d", &size);
  for (int i = 0 ; i < size; i++){
    if (f == -1) f++; scanf("%d", &queue[i]); e = i;
  }
  menu:
  printf("\n1. Insertion\n2.Deletion\n3.Display\n4.Exit");
  printf("\n Enter Your Choice : ");
  scanf("%d", &ch);
  switch (ch) {
    case 1: insert(); goto menu;
    case 2: delete(); goto menu;
    case 3: display(); goto menu;
    case 4: return 0;
  }
}
