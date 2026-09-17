#include <iostream>

struct node {
    int data;
    node* next; // es el nodo
};

void insert(node*& head, int data){  
    node* new_node = new node {data, head}; // estructura con llaves
    head = new_node; // cambiar de head
}

void InsertAtEnd(node*& head, int data){    //final ->adelante  
    node* new_node = new node {data, nullptr};

    if (head = nullptr){  //como no hay nada se hace el primero head / lista vacia
        head = new_node;
        return;
    }

    //si no esta vaica la lista
    node* current = head;
    
    while (current->next != nullptr) {
    current = current ->next; // pasa al siguiente nodo
    }
    
    current = current ->next;
}

int main(){
    


    return 0;
}

