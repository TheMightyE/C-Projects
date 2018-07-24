#include "dll.h"
#include "malloc.h"

void create_list(Node **head){
  //TODO
  
}

void append(Node **head, Node **tail, int item){
  /* Obtain memory for the new node and initialize it */
  Node *new = malloc(sizeof(Node));
  new->item = item;
  new->next = NULL;

  /* Check if the list is empty */
  if (*head){
    new->prev = *tail;
    new->prev->next = new;
    *tail = new;
  } else{
    /* Since the list is empty, head and tail point to new node */
    new->prev = NULL;
    *head = new;
    *tail = new;
  }

}

void prepend(Node **head, Node **tail, int item){
  /* Obtain memory for the new node and initialize it */
  Node *new = malloc(sizeof(Node));
  new->item = item;

  /* Check if list is empty */
  if (*head){
    new->next = *head;
    (*head)->prev = new;
    *head = new;
  } else{
    /* Since the list is empty, head and tail point to new node */
    new->next = NULL;
    *head = new;
    *tail = new;
  }
}

/* Remove the last node */
void pop(Node **head, Node **tail){
  if (*head){
    /* Check if there's only one item in the list */
      /* If there's more than one item */
      *tail = (*tail)->prev;
      if (*tail == NULL){
        *head = NULL;
      }else{
        free((*tail)->next);
        // (*tail)->next->prev = NULL;
        (*tail)->next = NULL;
      }
  } else{

  }
}

/* Remove node with the given item */
char remove_item(Node **head, Node **tail, int item){
  /* Check if you're removing the head */
  if (*head){
    if ((*head)->item == item){
      *head = (*head)->next;
      (*head)->prev = NULL;
      free((*head)->prev);
      return 1;

    } else if ((*tail)->item == item){
      pop(&(*head), &(*tail));
      return 1;

    } else {
      Node *cp = *head;
      while (cp && cp->item != item)
      cp = cp->next;
      if (cp){
        cp->prev->next = cp->next;
        cp->next->prev = cp->prev;
        free(cp);
        return 1;
      }else {
        return 0;
      }
    }
  } else {
    return 0;
  }


}

Node * find(Node *head, int item){
  Node *cp = head;
  while (cp){
    if (cp->item == item)
      return cp;
    cp = cp->next;
  }
  return 0;
}


void print_list(Node *head){
  if (head == NULL){
    printf("List is empty.\n");
    return;
  }
  Node *cp = head;
  while (cp) {
    printf("%d, ", cp->item);
    cp = cp->next;
  }
  printf("\n");
}

void print_list_rev(Node *tail){
  if (tail == NULL){
    printf("List is empty.\n");
    return;
  }
  Node *cp = tail;
  while (cp){
    printf("%d, ", cp->item);
    cp = cp->prev;
  }
  printf("\n");

}
