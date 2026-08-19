/* one example on linked list 
   The program prompts user to enter a sid (3 digit or shorter for simplicity)
	and a name (up to 39 characters for simplicity); builds a NODE with 
	sid and name[] and insert it at the tail of a linked list; after the 
	insertion, prints out the current linked list and the longest name; 
	then prompts the user for another sid (and name[]) till a 0 is entered
	as the sid. 

What is new from the linkedlist.c and linkedlist2.c?
1. typedef struct student {} DATA: a new structure with sid and name[]

2. When sid and name[] in DATA are accessed through NODE, the void * pointer 
	needs to be explicitly casted to (DATA *). You can search for DATA in
	the code to see this. 
 
3. void longest_name(ROOT *r): the function that finds the longest name in 
	the linked list with root r. If there is a tie, the first longest 
	name in the linked list will be printed out 

4. int main(): see the beginning of this header file 
								Gang Qu
								April 4, 2024
*/


#include <stdio.h>
#include <stdlib.h>

#define NEW(x) (x*)malloc(sizeof(x))

typedef struct student
{ int sid;		// student ID, 3 digits for simplicity
  char name[40];	// student name, up to 39 characters
} DATA;

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
    { printf("%3d ", ((DATA *)(temp->data))->sid);
      printf("%s\n", ((DATA *)(temp->data))->name);
      temp = temp->next;
    } while (temp != NULL);
  }
//  printf("\n");
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

void longest_name(ROOT *r)
{ NODE *Long, *this;		// Long points to the DATA with longest name[]
  int i, max=0;			// max is the length of name[] in the above
				// longest name[]

  if (r == NULL) return;
  this = r->head;

  while(this != NULL)
  { i=0;
    while (((DATA *)(this->data))->name[i]!='\0') i++;
				// count the length of name[]
    if (i>max)			// update the longest name	 
    { max = i; 
      Long = this;
    } 

    this = this->next;
  }
  
  if (max > 0)			// when max=0, no name[], no print out
    printf("Longest name: %s\n", ((DATA *)(Long->data))->name);

  return;
}


int main(void)
{ ROOT *root;	// a pointer to ROOT type
  DATA *data;	// a pointer to type DATA (sid, name) 
  int x, i;
  char ch;
  NODE *temp;

  root = make_root(); // see what happend when this line is deleted.

  printf("Enter student ID, 0 to stop:");
  scanf("%d", &x);
  while(x!=0)				// continue if sid is not 0
  { data = NEW(DATA);			// allocate memory for the new DATA
    data->sid = x; 			// assign sid to the new DATA
    printf("Enter student name:");
					// read in name[] till \n
    scanf("%c%c", &ch, &ch);		// %c%c to skip the \n after sid
    i = 0;
    while (ch!='\n')
    { data->name[i] = ch;
      scanf("%c", &ch);
      i++;
    }
    data->name[i] = '\0';		// done reading in name[]

    insert_at_tail(root, data);		// insert new DATA to the linked list	
    display_list(root);			// display the updated linked list
    longest_name(root);			// print out the longest name

    printf("Enter student ID, 0 to stop:");
    scanf("%d", &x);			// get ready for the next sid
  }

  longest_name(root);

  return 0;
}
