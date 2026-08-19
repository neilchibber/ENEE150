/* more examples for linked list 
NODE * second_last(ROOT *r): return a pointer to the second node from the
	last. NULL if the list has one or zero node.
NODE * middle(ROOT *r): return a pointer to the middle node from the list. 
	If the list has even number of nodes, for example 6, return a pointer
	to either node 3 or 4 should be ok.
	(In the sample implementation, node 4 is considered as the middle)
void remove_duplicate(ROOT *r): remove all the nodes that have duplicate DATA
	from the list. 
*/


#include <stdio.h>
#include <stdlib.h>

#define NEW(x) (x*)malloc(sizeof(x))

typedef int DATA;

typedef struct node
{ void * data;
  struct node * next;
} NODE;

typedef struct
{ long num;
  NODE * head;
  NODE * tail;
}ROOT;

NODE * make_node (void *data)
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
  { temp->num = 0;
    temp->head = NULL;
    temp->tail = NULL;
  }
  return temp;
}

void display_list(ROOT *r)
{ NODE * temp;

  if (r != NULL)
  { temp = r->head;
    do 
    { printf("%3d ", *(DATA *)(temp->data));
      temp = temp->next;
    } while (temp != NULL);
  }
  printf("\n");
}

int insert_at_tail(ROOT *r, DATA *d)
{ NODE * temp;
  temp = make_node(d);

  if (temp == NULL) return -1;  // fail, cannot create new NODE

  if (r == NULL)
  { r = make_root();
    if (r == NULL) return -1;   // fail, cannot create ROOT
  }

  (r->num)++;

  if (r->num == 1)              // if previously the list is empty
    r->head = r->tail = temp;

  else
  { r->tail->next = temp;
    r->tail = temp;
  }

  return 0;
}

NODE * second_last(ROOT *r)
{ NODE *found = NULL;
  NODE *this;
  
  if (r == NULL) return found;
  this = r->head;
  if (this->next == NULL) return found;

  this = this->next;
  found = r->head;
  while(this!=r->tail)
  { this = this->next;
    found = found->next;
  }

  return found;
}

NODE * middle(ROOT *r)
{ NODE *found = NULL;
  NODE *this;

  if (r == NULL) return found;
  this = r->head;
  if (this->next == NULL) return this;

  this = this->next;
  found = r->head;
  while(this!=NULL)
  { this = this->next;
    if (this != NULL)
      this = this->next;
    found = found->next;
  }

  return found;
}
 
void remove_duplicate(ROOT *r)
{ NODE *i, *j;		// I use i and j so you will feel that pointer
			// is the same as loop variables, although in real
			// life, i and j are normally of int type
  NODE *prev;		// pointer to the node before a duplicate

  if (r == NULL) return;
  if (r->head == r->tail) return;

  i = r->head;
  prev = i;
  i = i->next;
  while(i != NULL)
  { j = r->head;
    while (j != i)
    { if (*(DATA *)(j->data) == (*(DATA *)(i->data)))
      { prev->next = i->next;
	break;
      }
      j = j->next;
    }
    if (j==i) 		// not a duplicate 
    { prev = i;
      i = i->next;
    }
    else
     i = prev->next;
  }
}


int main(void)
{ ROOT *root;	// a pointer to ROOT type
  DATA *data, *data2;	// a pointer points to type DATA (int)
  DATA d, d2;
  int i;
  NODE *temp;

  root = make_root(); // see what happend when this line is deleted.

  for (i=0; i<9; i++)
  { data = NEW(DATA);
    d = 19 - 2*i;
    *data = d;
    insert_at_tail(root, data);
    printf("inserting %3d at the tail: ", d);
    display_list(root);

// test the second_last() function
    temp = second_last(root);
    if (temp == NULL) 
      printf("  Second from last node does not exist!\n");
    else
      printf("  Second from last node is %d\n", *(DATA *)(temp->data)); 

// test the middle() function
    temp = middle(root);
    if (temp == NULL)
      printf("  Empty list!\n");
    else
      printf("  The middle node is %d\n", *(DATA *)(temp->data));
  } 

// test the remove_duplicate() function
  data = NEW(DATA);
  *data = 15;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 8;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 15;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 11;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 8;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 28;
  insert_at_tail(root, data);
  data = NEW(DATA);
  *data = 8;
  insert_at_tail(root, data);
  printf("The new list: ");
  display_list(root);

  remove_duplicate(root);
  printf("No duplicate: ");
  display_list(root);

  return 0;
}
