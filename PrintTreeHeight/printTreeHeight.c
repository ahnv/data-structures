#include <stdio.h>
#include <malloc.h>

struct node { int data; struct node *l, *r; } *parentRoot = NULL;

struct node * insertion(struct node * root, int ele){
  if (root == NULL){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t -> data = ele;
    t -> l = t -> r = NULL;
    return t;
  }
  else if (ele > root -> data) root -> r = insertion(root->r,ele);
  else if (ele < root -> data) root -> l  = insertion(root->l,ele);
  return root;
}

int height (struct node * t){
  int lh, rh;
  struct node *tmp = t;
  if (t == NULL)  return 0;
  for (lh = 0 ; tmp != NULL; lh++, tmp = tmp->l);
  for (rh = 0 ; tmp != NULL; rh++, tmp = tmp->r);
  return (lh > rh) ? lh : rh;
}

int main(){
  int arr[8]  = {30,34,15,16,35,47,2,31};
  for (int i = 0 ; i < 8 ; i++) parentRoot = insertion(parentRoot,arr[i]);
  printf("%d\n", height(parentRoot));
}