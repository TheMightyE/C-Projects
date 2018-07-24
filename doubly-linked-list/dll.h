/* A generic doubly linked list */

#ifndef _DLL_H_
#define _DLL_H_
#include "stdio.h"
#include "stdlib.h"

typedef struct Node{
  int item;
  struct Node *next;
  struct Node *prev;
}Node;


extern Node *head;
extern Node *tail;

/* Create a new list. Deletes the previous one if exists. */
void create_list(Node **head);

/* Add node to the end */
void append(Node **head, Node **tail, int item);

/* Add node to beginning */
void prepend(Node **head, Node **tail, int item);

/* Find a node with the given item */
Node * find(Node *head, int item);

/* Print th list from head to tail */
void print_list(Node *head);

/* Print th list from tail to head */
void print_list_rev(Node *tail);

/* Remove a node from end */
void pop(Node **head, Node **tail);

/* Remove node with the given item */
char remove_item(Node **head, Node **tail, int item);

#endif
