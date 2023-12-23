#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node *next;
} node;

void print_linked_list(node *head){
  for (node *cur = head; cur != NULL; cur = cur-> next){
    printf("%d -> ", cur->data);
  }
  printf("NULL \n");
}

void add_node(node *head, int data){
  print_linked_list(head);
  node *cur =  head;
  while(cur != NULL){
    if (cur->next == NULL){
      printf("adding node \n");
      cur->next = malloc(sizeof(node));
      cur->next->data = data;
      cur->next->next = NULL;
      break;
    }
  }
  print_linked_list(head);
}

int main(){
  node *head;
  head = malloc(sizeof(node));
  int data = 100;
  add_node(head, 10);
  add_node(head, 10213);
  add_node(head, 123);
  add_node(head, 123);
  add_node(head, 123);
}
