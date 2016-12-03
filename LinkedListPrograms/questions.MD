# Questions


### Program 1
```Write down a code to perform addition and subtration of two polynomial equations.```
> A polynomial is an expression that contains more than two terms.  A term is made up of coefficient and exponent.  An example of polynomial is P(x) = 4x3+6x2+7x+9
A polynomial can be represented using a linked list.  A structure may be defined such that it contains two parts- one is the coefficient and second is the 
corresponding exponent.  The structure definition may be given as shown below:

```
struct polynomial {
    int coefficient;
    int exponent;
    struct polynomial *next;
};
```
### Program 2
```Given a singly linked list, delete middle of the linked list. ```
> For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL, then it should remain NULL.
If the input linked list has 1 node, then this node should be deleted and new head should be returned.
Note: - There is no variable that will give you total nodes and don’t count number of nodes also.

### Program 3
```Given a singly linked list, determine if it’s a palindrome. Return 1 or 0 denoting if it’s a palindrome or not, respectively.```
> Notes: – Expected solution is linear in time and constant in space. For example, List 1–>2–>1 is a palindrome. List 1–>2–>3 is not a palindrome. Solution: This method takes O(n) time

### Program 4
```Write down a pseudo code to insertion an element at any position in circular doubly linked list.```

### Program 5
```Suppose there are two singly linked lists both of which intersect at some point and become a single linked list. The head or start pointers of both the lists are known, but the intersecting node is not known. Also, the number of nodes in each of the list before they intersect are unknown and both list may have it different i.e. Head1 may have n nodes before it reaches intersection point and Head2 might have m nodes before it reaches intersection point where m and n may be m = n, m < n or m > n```
