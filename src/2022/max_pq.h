#ifndef MAX_PQ_H 
#define MAX_PQ_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class Max_pq {
public:
    Node *head;
    int max_size;

    Max_pq (int max_size = 3) {
        head = nullptr;
        this->max_size = max_size;
    }

    void add_node(int data);

    int sum();

    void display();
};

#endif // PRIORITY_QUEUE_H

