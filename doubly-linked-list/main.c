#include "dll.h"

int main(int argc, char **argv){
  Node *head = NULL;
  Node *tail = NULL;
  // create_list(&head);
  for (size_t i = 0; i < 10; i++) {
    append(&head, &tail, i);
  }
  print_list(head);

  int n = 7;
  if (remove_item(&head, &tail, n)){
    printf("Deleted: %d\n", n);
  }

  if (find(head, 3)){
    printf("Found: %d\n", 3);
  }

  if (!find(head, n)){
    printf("Not Found: %d\n", n);
  }

  print_list(head);

  printf("Popping\n");
  for (size_t i = 0; i < 10; i++) {
    pop(&head, &tail);
  }
  print_list(head);
}
