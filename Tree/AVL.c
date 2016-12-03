#include <stdio.h>
#include <malloc.h>

struct node { int data, ht; struct node *lc, *rc; } *pNode = NULL;

int height (struct node * t){
  int lh, rh;
  if (t == NULL)  return 0;
  lh = (t -> lc == NULL) ? lh = 1 : (1 + t->lc->ht);
  rh = (t -> rc == NULL) ? rh = 1 : (1 + t->rc->ht);
  return (lh > rh) ? lh : rh;
}

int balFact(struct node * t){
  if (t == NULL)  return 0;
  if (t->lc == NULL) return (0- t->rc->ht);
  if (t->rc == NULL) return (t->lc->ht);
  return (t->lc->ht - t->rc->ht);
}

struct node * minVal(struct node * t){
  while(t->lc != NULL) t = t -> lc;
  return t;
}

struct node * LeftRotate(struct node * a){
  struct node *b = a->rc; a -> rc = b -> lc; b -> lc = a;
  a -> ht = height(a);
  b -> ht = height(b);
  return b;
}

struct node * RightRotate(struct node * a){
  struct node *b = a->lc;
  a -> lc = b -> rc;
  b -> rc = a;
  a -> ht = height(a);
  b -> ht = height(b);
  return b;
}

struct node * RRrotation(struct node *t) { return LeftRotate(t); }
struct node * LLrotation(struct node *t) { return RightRotate(t); }
struct node * RLrotation(struct node *t) { t-> rc = RightRotate(t->rc); return LeftRotate(t);}
struct node * LRrotation(struct node *t) { t-> lc = LeftRotate(t->lc); return RightRotate(t);}

struct node * insert(struct node * t, int ele){
  if (t == NULL){
      t = (struct node *)malloc(sizeof(struct node));
      t -> data = ele;
      t -> lc = t->rc = NULL;
  }
  else if (ele > t->data){
    t -> rc = insert(t->rc,ele);
    if (balFact(t) == -2) { t = (ele > t->rc->data)  ? RRrotation(t) : LRrotation(t); }
  }
  else if (ele < t->data){
    t -> lc = insert(t->lc,ele);
    if (balFact(t) == 2) { t = (ele < t->lc->data)  ? LLrotation(t) : RLrotation(t); }
  }
  t -> ht = height(t);
  return t;
}

struct node * deletion(struct node * t, int ele){
  if (t == NULL) return t;
  if (ele > t-> data){
    t -> rc = deletion(t->rc,ele);
    if (balFact(t) == 2) { t = (balFact(t->lc) >= 0) ?  LLrotation(t) : RLrotation(t); }
  }
  else if (ele < t-> data){
    t -> lc = deletion(t->lc,ele);
    if (balFact(t) == -2) { t = (balFact(t->lc) <= 0) ? RRrotation(t) : LRrotation(t); }
  }
  else if (ele == t->data){
    if (t->lc == NULL){
      struct node *temp = t -> rc;
      free(t);
      return temp;
    }
    else if (t->rc == NULL){
      struct node *temp = t -> lc;
      free(t);
      return temp;
    }
    struct node * temp ;
    temp = minVal(t->rc);
    t->data = temp->data;
    t->rc = deletion(t->rc,temp->data);
  }
  t->ht = height(t);
  return t;
}

void print(struct node * t){
  if (t != NULL){
    printf("%d\t", t->data);
    print(t->lc);
    print(t->rc);
  }
}

int main(){
  int ch,element;
  menu:
  printf("1. Insert\n2. Deletion\n3. Display\n4. Exit");
  scanf("%d",&ch);
  switch(ch){
    case 1:
        printf("Enter Element : ");
        scanf("%d",&element);
        pNode = insert(pNode,element);
        goto menu;
    case 2: 
        printf("Enter Element to delete : ");
        scanf("%d",&element);
        pNode  = deletion(pNode,element);
        goto menu;
    case 3: 
        printf("The Binary Tree is : ");
        print(pNode);
        printf("\n");
        goto menu;
    case 4: return 0;
    default: goto menu;   
  }
}