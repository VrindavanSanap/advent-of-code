#include<iostream>
using namespace std;

/*
  MAX HEAP
    We want to store top 3 values 
    
    heap class
      add node
      delete lowest node
      pop highest node
      get sum of all nodes
*/

class Node{
  public:
    int data;
    Node* next;
    Node(int val){
      data = val;
      next = nullptr;
    }
    void display(){
      cout << data;

    }
};


class Max_pq{
  public:
    Node *head;
    int max_size;
    Max_pq(int max_size = 3){
      head = nullptr;
      this->max_size = max_size;
    }

    void add_node(int data){
      Node* newNode = new Node(data);
      if (head == nullptr){
        head = newNode;
        return;
      }
      if (head -> data < data){
        newNode->next = head;
        head = newNode;
      }
      Node* temp = head;
      Node *temp_next;
      int count = 0;
      while (temp->next != nullptr){
        count++;
        if (count == max_size){
          temp->next = nullptr;
          return;
        }
        temp_next = temp->next;
        if (temp_next->data < data){
          temp->next = newNode;
          newNode->next = temp_next;
          return;
        }
        temp = temp -> next;
      }
      temp->next = newNode;
    }
    int sum(){
      int sum = 0;
      Node *temp = head;
      while (temp != nullptr){
        sum+= temp->data;
        temp = temp->next;
       }
       return sum;
    }
    void display() {
       Node* temp = head;
       while (temp != nullptr) {
          cout << temp->data << "->";
          temp = temp->next;
       }
      cout<< "nullptr"<< endl;
    }
};

int main(){
    Max_pq max_pq;
    max_pq.add_node(30);
    max_pq.add_node(7);
    max_pq.add_node(3);
    max_pq.add_node(1230);
    max_pq.add_node(3123);
    max_pq.add_node(33);
    max_pq.add_node(12);
    max_pq.add_node(123);
    max_pq.add_node(23);
    max_pq.add_node(12);
    max_pq.add_node(20);
    max_pq.display();
    int sum = max_pq.sum();
    cout << sum;
    return 0;
}

