/* This is the sample sparse.c file that implements functions defined in the
        sparse.h file and those called from p2_1.c.
ENTRY * make_node (int r, int c, int v)         // sparse.h
ROOT * make_root (void)                         // sparse.h
void show_list (ROOT *M, FILE *F)               //p2_1.c
void  read_input(FILE *F, ROOT *M, FILE *G)     //p2_1.c

   You can also define new functions and structures here, but they will not be
        "seen" or used outside this file (e.g. you cannot use them in p2.c).
        For example, the following function is introduced to help implementing
        function read_input().
void insert_at_tail (ROOT *M, ENTRY *e)
                                                                Gang Qu
                                                                March 31, 2026

void show_list()        // position of the non-zero entries is added
                                                                April 13, 2026


void show_list()	// the do-while loop is replaced by a while loop

   The following three functions are added at the end. You need to implement them
	for Phase 1. The specification of these functions can be found in sparse.h. 
void search (ROOT *M, int k, FILE *F)
void find_max(ROOT *M, FILE *F)
ROOT * addition (ROOT *M1, ROOT *M2, FILE *F)

								Gang Qu
								April 14, 2026
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
// printf("matrix at %p ...\n", M);	// for debug
    fprintf(F, "matrix at %p ...\n", M);
    temp = M->head;
    while (temp != NULL) 
    { fprintf(F, "%5d (%d,%d)", temp->val, temp->row, temp->col);
//        printf("%5d (%d,%d)", temp->val, temp->row, temp->col);
       temp = temp->next;
      i++;
      if (i == 5)
      {	fprintf(F, "\n");
//         printf("\n");
        i = 0;
      }
    } // while (temp != NULL);
// the previous do-while loop seg fault when the list is empty
  }

  if (i!=0)
  { fprintf(F, "\n");
//     printf("\n");
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

  fprintf(G, "Reading entry from %p ... \n", F);
  while(fscanf(F, "%d %d %d", &r, &c, &v) != EOF)
  { tmp = make_node(r, c, v);
    if (tmp != NULL)			// check whether node is made or not
      insert_at_tail (M, tmp);
  }
  fprintf(G, "%d entries stored in matrix at %p.\n", M->num, M);
}

void search (ROOT *M, int k, FILE *F)
{
}

void find_max(ROOT *M, FILE *F)
{
}

ROOT * addition (ROOT *M1, ROOT *M2, FILE *F)
{
}

void search(ROOT *M, int k, FILE *F)
{
    ENTRY *temp;

    fprintf(F, "search %d in matrix at %p ...\n", k, M);
    printf("search %d in matrix at %p ...\n", k, M);

    if (M == NULL) return;

    temp = M->head;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            fprintf(F, "%d %d\n", temp->row, temp->col);
            printf("%d %d\n", temp->row, temp->col);
        }
        temp = temp->next;
    }
}

void find_max(ROOT *M, FILE *F)
{
    ENTRY *temp, *maxEntry;

    fprintf(F, "find max in matrix at %p ...\n", M);
    printf("find max in matrix at %p ...\n", M);

    if (M == NULL || M->head == NULL) return;

    maxEntry = M->head;
    temp = M->head->next;
    while (temp != NULL)
    {
        if (temp->val > maxEntry->val)
            maxEntry = temp;
        temp = temp->next;
    }

    fprintf(F, "maximum %d at position (%d,%d)\n", maxEntry->val, maxEntry->row, maxEntry->col);
    printf("maximum %d at position (%d,%d)\n", maxEntry->val, maxEntry->row, maxEntry->col);
}

ROOT * addition(ROOT *M1, ROOT *M2, FILE *F)
{
    ROOT *result;
    ENTRY *temp, *other, *node;
    int matched, sum;

    result = make_root();
    if (result == NULL) return NULL;

    /* For each entry in M1, add M2's value if same position exists */
    if (M1 != NULL)
    {
        temp = M1->head;
        while (temp != NULL)
        {
            sum = temp->val;
            if (M2 != NULL)
            {
                other = M2->head;
                while (other != NULL)
                {
                    if (other->row == temp->row && other->col == temp->col)
                    {
                        sum += other->val;
                        break;
                    }
                    other = other->next;
                }
            }
            if (sum != 0)
            {
                node = make_node(temp->row, temp->col, sum);
                if (node != NULL)
                    insert_at_tail(result, node);
            }
            temp = temp->next;
        }
    }

    /* Add entries from M2 with no matching position in M1 */
    if (M2 != NULL)
    {
        temp = M2->head;
        while (temp != NULL)
        {
            matched = 0;
            if (M1 != NULL)
            {
                other = M1->head;
                while (other != NULL)
                {
                    if (other->row == temp->row && other->col == temp->col)
                    {
                        matched = 1;
                        break;
                    }
                    other = other->next;
                }
            }
            if (!matched && temp->val != 0)
            {
                node = make_node(temp->row, temp->col, temp->val);
                if (node != NULL)
                    insert_at_tail(result, node);
            }
            temp = temp->next;
        }
    }

    fprintf(F, "matrix at %p has %ld non-zero entries\n", result->head, result->num);
    printf("matrix at %p has %ld non-zero entries\n", result->head, result->num);

    return result;
}