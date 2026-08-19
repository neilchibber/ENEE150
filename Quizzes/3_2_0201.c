/*
Problem 2: separate

complete the function separate() to  take in two ROOT pointers 
r1 and r2, and move all  nodes from r2 that are  duplicates of 
nodes in r1 into  the tail of r1. The function should NOT make 
any new nodes, but should instead manipulate existing pointers 
to move the nodes.

Examples:
before calling separate(r1, r2)
r1: 7 -> 3 -> 6 -> 2 -> 5 -> NULL
r2: 9 -> 6 -> 8 -> 5 -> 4 -> NULL

after calling separate(r1, r2)
r1: 7 -> 3 -> 6 -> 2 -> 5 -> 6 -> 5 -> NULL (6 and 5 were inserted)
r2: 9 -> 8 -> 4 -> NULL (6 and 5 were removed)
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


void separate(ROOT *r1, ROOT *r2){
  if (r1 == NULL || r2 == NULL || r1->head == NULL || r2->head == NULL) {
    return;
  }
  
  // Find the tail of r1
  NODE *tail_r1 = r1->head;
  while (tail_r1->next != NULL) {
    tail_r1 = tail_r1->next;
  }
  
  NODE *prev = NULL;
  NODE *curr = r2->head;
  
  while (curr != NULL) {
    NODE *next_curr = curr->next;
    
    // Check if curr's data is in r1
    int is_duplicate = 0; 
    NODE *temp = r1->head;
    while (temp != NULL) {
      if (*temp->data == *curr->data) {
        is_duplicate = 1;
        break;
      }
      temp = temp->next;
    }
    
    if (is_duplicate) {
      // Remove curr from r2
      if (prev == NULL) {
        r2->head = next_curr;
      } else {
        prev->next = next_curr;
      }
      
      // Append curr to r1's tail
      if (tail_r1 == NULL) {
        r1->head = curr;
        tail_r1 = curr;
      } else {
        tail_r1->next = curr;
        tail_r1 = curr;
      }
      curr->next = NULL;
      
      // Continue with next_curr
      curr = next_curr;
      // prev remains the same
    } else {
      prev = curr;
      curr = next_curr;
    }
  }
}

//you do not need to change the main function.
int main(void)
{ int value, i;
  int *p;
  ROOT *r1, *r2;

  r1 = make_root();
  r2 = make_root();
  if (r1 == NULL || r2 == NULL)
    return -1;

  for (i=0; i<10; i++)
  { value = rand()%11 + 10;
    p = NEW(int);
    if (p == NULL) return -1;
    *p = value;

    insert_at_tail(r1, p);		// insert at tail

    value = rand()%11 + 10;
    p = NEW(int);
    if (p == NULL) return -1;
    *p = value;

    insert_at_tail(r2, p);		// insert at tail
  }

  printf("Before separating:\nr1: ");
  display_list(r1);
  printf("r2: ");
  display_list(r2);

  separate(r1, r2);

  printf("After separating:\nr1: ");
  display_list(r1);
  printf("r2: ");
  display_list(r2);

  return 0;
}

     
