#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

class LinkedList {
 public:
  Node* head;

  LinkedList() { head = nullptr; }

  void append(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void display() {
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "nullptr" << endl;
  }
};
int main() {
  LinkedList myList;

  myList.append(10);
  myList.append(10);
  myList.append(10);
  myList.append(10);
  myList.append(10);
  myList.display();
  return 0;
}
