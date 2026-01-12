#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

class Node {
 public:
  int data;
  Node *next;
  Node(int data) : data(data), next(nullptr) {}
};

class Priority_queue {
 public:
  Node *head;
  int max_size;

  Priority_queue(int max_size = 3) {
    head = nullptr;
    this->max_size = max_size;
  }

  void add_node(int data);

  int sum();

  void display();
};

#endif  // PRIORITY_QUEUE_H
