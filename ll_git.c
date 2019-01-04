#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int ll_add_to_head( llnode **head, int val)
{
   llnode *old_head;
   if (head == NULL)
   {
      return -1;
   }
        old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
   (*head) -> next = old_head;
   return 0;
}

int ll_add_to_tail( llnode **head, int val)
{
   if (head == NULL)
   {
      return -1;
   }

   if (*head == NULL)
   {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   }
   else
   {
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p)
{
   if (p==NULL)
   {
      return 0;
   }
   else
   {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p)
{
   if (p==NULL)
   {
      return -1;
   }
   else
   {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value(llnode *pList, int val)
{
        if (pList == NULL )
        {
                return -1;
        }
        if (pList -> val == val )
        {
                return 0;
        }
        else
        {
                return ll_find_by_value((pList) -> next, val);
        }
        return -1;
}

int ll_del_from_tail(llnode **ppList)
{
        if (ppList == NULL)
        {
                return -1;
        }
        if (((*ppList)->next) == NULL)
        {
                return -1;
        }
        if ((((*ppList)->next)->next) == NULL)
        {
                free(((*ppList)->next));
                ((*ppList)->next) = NULL;
                return 0;
        }
        else
        {
                return ll_del_from_tail(&((*ppList)->next));
        }
}

int ll_del_from_head(llnode **ppList)
{
   llnode *temp;

   if (*ppList == NULL) {return -1;}
   else
   {

   temp = *ppList;
   *ppList = (*ppList)->next;
   (temp)->next = NULL;
   free (temp);
   return 0;

   }
}

int ll_concat(llnode **pSrcA, llnode **pSrcB)
{
   llnode *mover = NULL;
   mover = *pSrcB;

   if (pSrcA == NULL || pSrcB == NULL)
   {
      return -1;
   }

   while (mover != NULL)
   {
      ll_add_to_tail(pSrcA, mover->val);
      mover = mover->next;
   }

   return 0;
}

int ll_del_by_value(llnode **ppList, int val) {
        llnode *delVal = NULL;

        if (ppList == NULL) {
                return -1;
        }
        if (*ppList == NULL) {
                return -1;
        }
        if ((*ppList)->next == NULL) {
                return -1;
        }
        if (((*ppList)->next)->val == val) {
                delVal = (*ppList)->next;
                (*ppList)->next = ((*ppList)->next)->next;
                free(delVal);
                return 0;
        }
        else{
                return ll_del_by_value(&(*ppList)->next,val);
        }
}

int ll_sort(llnode **ppList)
{
   llnode *cur = NULL;
   int sorttmp;
   int sort = 0;
   if (ppList == NULL) {return -1;}
   cur = *ppList;
   while (!sort)
   {
      cur = *ppList;
      sort = 1;
      while ((cur -> next) != NULL)
      {
         if (cur -> val > (cur -> next) -> val)
         {
            sorttmp = cur -> val;
            cur -> val = (cur -> next) -> val;
            (cur -> next) -> val = sorttmp;
            sort = 0;
         }
         cur = cur -> next;
      }
   }
   return 0;
}

int ll_insert_in_order(llnode **ppList,int val)
{
   llnode *prev = NULL;
   llnode *curr = NULL;

   if (ppList == NULL) { return -1; }

   if (*ppList == NULL)
   {
      return ll_add_to_head(ppList,val);
   }

   if ((*ppList) -> val > val)
   {
      return ll_add_to_head(ppList,val);
   }
   else
   {
      prev = *ppList;
      curr = (*ppList)->next;
      while(curr != NULL)
      {
         if (curr->val > val) {break;} 
         else
         {
            prev = curr;
            curr = prev->next;
         }
      }
      prev->next = (llnode *) malloc(sizeof(llnode));
      prev->next->val  = val;
      prev->next->next = curr;
      return 0;
   }
}