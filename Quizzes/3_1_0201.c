/*
Problem 1: excluding sum

complete the function excluding_sum() to take in a ROOT pointer
and an integer k,  where it returns the sum of all nodes in the
list pointed to by r EXCLUDING the node at position k, assuming
positions  are 0 indexed.  k is not  guaranteed  to be  a valid 
position in the list: in case of an invalid k, sum all nodes in
the list.

Examples:
r: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

excluding_sum(r, 1) = 1 + 3 + 4 + 5 = 13
excluding_sum(r, 3) = 1 + 2 + 3 + 5 = 11
excluding_sum(r, -1) = 1 + 2 + 3 + 4 + 5 = 15
*/

#include <stdio.h>
#include <stdlib.h>

#define NEW(x) (x*)malloc(sizeof(x))

typedef struct node
{ int * data;
  struct node * next;
} NODE;

typedef struct
{ NODE *head;
} ROOT;

NODE * make_node (int *data)
{ NODE * temp;
  temp = NEW(NODE);
  if (temp != NULL)
  { temp->data = data;
    temp->next = NULL;
  }
  return temp;
}

ROOT * make_root (void)
{ ROOT * temp;
  temp = NEW(ROOT);
  if (temp != NULL)
    temp->head = NULL;
  return temp;
}

int insert_at_tail(ROOT *r, int *d)	// problem 1. 
{ NODE *temp, *curr ;
  temp = make_node(d);

  if (temp == NULL) return -1;  // fail, cannot create new NODE

  if (r == NULL)
  { r = make_root();
    if (r == NULL) return -1;   // fail, cannot create ROOT
  }

  curr = r->head;		// when the linked list is empty
  if (curr == NULL)
  { r->head = temp;
    return 0;
  }

  for (; curr->next != NULL; curr = curr->next);
				// find the tail, empty loop body
  curr->next = temp; 		// link node temp to the linked list 
				// at the tail.

  return 0;
}

void display_list(ROOT *r)	// problem 2.
{ NODE *temp;
  if (r == NULL) return;		// undefinted linked list
  if (r->head == NULL) return;		// empty linked list
  
  for (temp = r->head; temp != NULL; temp = temp->next)
    printf("%d->", *temp->data);
  printf("/\n");
}


void display_largest(ROOT *r)	// problem 3.
{ NODE *temp;
  int largest = 10;			// safe, because values are 
					// between 10 and 20
  if (r == NULL) return;                
  if (r->head == NULL) return;          

  for (temp = r->head; temp != NULL; temp = temp->next)
    if (*(temp->data) > largest)	// find a larger data
      largest = *(temp->data);
  
  printf("  Largest: %d\n", largest);

}

// DO NOT MAKE CHANGES ABOVE THIS LINE.

int excluding_sum(ROOT *r, int k){
  if (r == NULL || r->head == NULL) {
    return 0;
  }
  int sum = 0;
  int pos = 0;
  int exclude = 0;
  int found = 0;
  NODE *curr = r->head;
  while (curr != NULL) {
    sum += *(curr->data);
    if (pos == k) {
      exclude = *(curr->data);
      found = 1;
    }
    curr = curr->next;
    pos++;
  }
  if (found && k >= 0) {
    return sum - exclude;
  } else {
    return sum;
  }
}

//you do not need to change the main function.
int main(void)
{ int value, i;
  int *p;
  ROOT *r;

  r = make_root();
  if (r == NULL)
    return -1;

  for (i=0; i<10; i++)
  { value = rand()%11 + 10;
    p = NEW(int);
    if (p == NULL) 
      return -1;

    *p = value;

    insert_at_tail(r, p);		// insert at tail
  }

  display_list(r);
  printf("Sum excluding k = 0: %d\n", excluding_sum(r,0));
  printf("Sum excluding k = 3: %d\n", excluding_sum(r,3));
  printf("Sum excluding k = 11: %d\n", excluding_sum(r,11));

  return 0;
}

     
