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

void read_input(FILE *F, ROOT *M, FILE *G)
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
printf("%ld entries stored in matrix at %p.\n", M->num, M);
  fprintf(G, "%ld entries stored in matrix at %p.\n", M->num, M);
}

void search (ROOT *M, int k, FILE *F)
{ ENTRY *curr;

printf("search %d in matrix at %p\n", k, M);
  fprintf(F, "search %d in matrix at %p\n", k, M);

  if (M == NULL || M->head == NULL) return;

  curr = M->head;
  while (curr != NULL)
  { if (curr->val == k)
    { fprintf(F, "%d %d\n", curr->row, curr->col);
       printf("%d %d\n", curr->row, curr->col);
    }
    curr = curr->next;
  }
}

void find_max (ROOT *M, FILE *F)
{ ENTRY *curr, *max_e;

printf("find max in matrix at %p\n", M);
  fprintf(F, "find max in matrix at %p\n", M);

  if (M == NULL || M->head == NULL) return;

  max_e = M->head;
  curr = M->head->next;
  while (curr != NULL)
  { if (curr->val > max_e->val)
      max_e = curr;
    curr = curr->next;
  }
printf("maximum %d at position (%d,%d)\n", max_e->val, max_e->row, max_e->col);
  fprintf(F, "maximum %d at position (%d,%d)\n", max_e->val, max_e->row, max_e->col);
}

ROOT * addition (ROOT *M1, ROOT *M2, FILE *F)
{ ROOT *sum_root;
  ENTRY *curr, *srch, *prev, *new_e;
  int found;

  sum_root = make_root();
  if (sum_root == NULL) return NULL;

  if (M1 != NULL)				// copy M1 into sum
  { curr = M1->head;
    while (curr != NULL)
    { insert_at_tail(sum_root, make_node(curr->row, curr->col, curr->val));
      curr = curr->next;
    }
  }

  if (M2 != NULL)				// add M2 into sum
  { curr = M2->head;
    while (curr != NULL)
    { found = 0;
      srch = sum_root->head;
      prev = NULL;
      while (srch != NULL)
      { if (srch->row == curr->row && srch->col == curr->col)
        { srch->val += curr->val;
          found = 1;
          if (srch->val == 0)			// remove if sum is zero
          { if (prev == NULL) sum_root->head = srch->next;
            else prev->next = srch->next;
            free(srch);
            sum_root->num--;
          }
          break;
        }
        prev = srch;
        srch = srch->next;
      }
      if (!found)
      { new_e = make_node(curr->row, curr->col, curr->val);
        if (new_e != NULL) insert_at_tail(sum_root, new_e);
      }
      curr = curr->next;
    }
  }

printf("matrix at %p has %ld non-zero entries\n", sum_root, sum_root->num);
  fprintf(F, "matrix at %p has %ld non-zero entries\n", sum_root, sum_root->num);

  return sum_root;
}