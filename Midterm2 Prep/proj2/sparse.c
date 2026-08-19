/* This is the sample sparse.c file that implements functions defined in the 
	sparse.h file and those called from p2_1.c. 
ENTRY * make_node (int r, int c, int v)		// sparse.h
ROOT * make_root (void)				// sparse.h
void show_list (ROOT *M, FILE *F)		//p2_1.c
void  read_input(FILE *F, ROOT *M, FILE *G)	//p2_1.c

   You can also define new functions and structures here, but they will not be
	"seen" or used outside this file (e.g. you cannot use them in p2.c). 
	For example, the following function is introduced to help implementing
	function read_input().  
void insert_at_tail (ROOT *M, ENTRY *e)
								Gang Qu
								March 31, 2026
void show_list()	// position of the non-zero entries is added
								April 13, 2026
*/

#include<stdio.h>
#include<stdlib.h>
#include "sparse.h"

ENTRY * make_node (int r, int c, int v)
{ ENTRY *temp;
  if (r<0 || c<0 || v==0)		// verify input values 
    return NULL;
  temp = NEW(ENTRY);
  if (temp != NULL)
  { temp->val = v;
    temp->row = r;
    temp->col = c;

    temp->left = NULL;
    temp->right = NULL;
    temp->up = NULL;
    temp->down = NULL;
    temp->info = NULL;
    temp->next = NULL;
  }
  return temp;
}

ROOT * make_root (void)
{ ROOT  *temp;
  temp = NEW(ROOT);
  if (temp != NULL)
  { temp->head = NULL;
    temp->num = 0;
    temp->info = NULL;
  }
  return temp; 
}

void insert_at_tail (ROOT *M, ENTRY *e)
{ ENTRY *tmp;

  if (M == NULL) return;
  if (M->head == NULL) 
  { M->head = e;
    M->num = 1;
    return;
  } 
  
  tmp = M->head;
  while (tmp->next != NULL) 
    tmp = tmp->next;
  tmp->next = e;
  e->next = NULL;
  M->num++;
}


void show_list (ROOT *M, FILE *F)
{ ENTRY *temp;
  int i=0;				// 5 values per line

  if (M != NULL)
  { 
printf("matrix at %p ...\n", M);
    fprintf(F, "matrix at %p ...\n", M);
    temp = M->head;
    do
    { fprintf(F, "%5d (%d,%d)", temp->val, temp->row, temp->col);
       printf("%5d (%d,%d)", temp->val, temp->row, temp->col);
       temp = temp->next;
      i++;
      if (i == 5)
      {	fprintf(F, "\n");
	printf("\n");
        i = 0;
      }
    } while (temp != NULL);
  }
  if (i!=0) 
  { fprintf(F, "\n");
    printf("\n");
  }
}


void  read_input(FILE *F, ROOT *M, FILE *G)
{ ENTRY *tmp;
  int r, c, v;
  
  if (M == NULL)
  { M = make_root();
    if (M == NULL)
    { printf("No space left. Fail to store data.\n");
      exit(0);
    }
  }

printf("Reading entry from %p ... \n", F);
  fprintf(G, "Reading entry from %p ... \n", F);
  while(fscanf(F, "%d %d %d", &r, &c, &v) != EOF)
  { tmp = make_node(r, c, v);
    if (tmp != NULL)			// check whether node is made or not
      insert_at_tail (M, tmp);
  }
printf("%d entries stored in matrix at %p.\n", M->num, M);
  fprintf(G, "%d entries stored in matrix at %p.\n", M->num, M);
}
