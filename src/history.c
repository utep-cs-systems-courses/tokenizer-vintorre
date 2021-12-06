#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int Id = 0;

List* init_history()
{
  List * list = malloc(sizeof (List));

  list -> root = NULL;
  return list;

  
}

void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof (Item));
  item -> str = malloc(sizeof(char) * (sizeof(str) +1));


  item -> id = Id++;
  item -> next = NULL;

  Item *ptr = list -> root;

  if(ptr == NULL){
      list -> root = item;
      item -> str = str;
      return;

  }

  while(ptr -> next != NULL)
    {
      ptr = ptr -> next;
    }
  
  ptr -> next = item;
  item -> str = str;
  

  
}



char *get_history(List *list, int id)
{
  Item *ptr = list -> root;

  while(ptr != NULL)
    {
      if(ptr -> id == id)
	{
	  return(ptr -> str);
	}
      ptr = ptr -> next;
    }

  return "";

}

void print_history(List *list)
{
  Item *ptr = list -> root;

  while(ptr != NULL)
    {
      printf("%d - %s\n", ptr -> id, ptr -> str);
      ptr = ptr -> next;
    }
}

void free_history(List *list)
{
  Item *temp = list -> root;
  Item *delete = NULL;

  while(temp != NULL)
    {
      delete = temp;
      temp = temp -> next;

      free(delete -> str);
      free(delete);
    }
}
