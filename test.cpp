#include <iostream>

struct Node {
  int data;
  Node* next;
  Node* prev;
};

void Append(Node*& head, int value) {
  Node* new_node = new Node{value, nullptr, nullptr};

  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* current = head;

  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = new_node;
  new_node->prev = current;
}



void PrintForward(Node* head) {
  Node* current = head;

  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << '\n';
}

void PrintBackward(Node* head) {
  if (head == nullptr) {
    return;
  }

  Node* current = head;

  while (current->next != nullptr) {
    current = current->next;
  }

  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->prev;
  }

  std::cout << '\n';
}

bool InsertAfter(Node* head, int target, int value){
    if (head !=nullptr){
    head == new Node;
    return true;       
    } else {
    return false;    
    }
}

void SplitByPosition(
    Node*& head,
    Node*& even_head,
    Node*& odd_head);