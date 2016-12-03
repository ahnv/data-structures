#include <stdio.h>
#include <malloc.h>
#include <custom.h>

struct node{
	int data;
	struct node *next;
} *start = NULL, *start2 = NULL;

int isPalindrome(){
	struct node *t, *t2;
	t = start;
	t2 = start2;
	for (;t != NULL && t2 != NULL; t = t -> next, t2 = t2 -> next){
		if (t -> data != t2 -> data){
			return 0;
		}
	}
	return 1;
}
void reverse(){
	struct node *t, *t2, *prev;
	t =start;
	for (;t != NULL; t = t -> next){
		t2 = (struct node *)malloc(sizeof(struct node));
		t2 -> data = t -> data;
		t2 -> next = start2;
		start2 = t2;
	}
}

int main(){
	int numberOfNodes;
	struct node *t, *last;
	scanf("%d", &numberOfNodes);
	for (int i = 0; i < numberOfNodes; i++){
		t = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &(t -> data));
		t -> next = NULL;
		if (start  == NULL)
			start = t;
		else
			last -> next = t;
		last = t;
	}
	reverse();
	printf("%s",isPalindrome()? "Palindrome\n" : "Not Palindrome\n" );
}
