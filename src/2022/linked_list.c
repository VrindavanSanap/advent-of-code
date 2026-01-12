#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void print_linked_list(struct node *head) {
  for (struct node *cur = head; cur != NULL; cur = cur->next) {
    printf("%d -> ", cur->data);
  }
  printf("NULL");
}

int main() {
  struct node *head;

  head = malloc(sizeof(struct node));
  head->data = 100;
  head->next = malloc(sizeof(struct node));
  head->next->data = 100;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 220;
  head->next->next->next = malloc(sizeof(struct node));
  head->next->next->next = NULL;

  print_linked_list(head);
}
