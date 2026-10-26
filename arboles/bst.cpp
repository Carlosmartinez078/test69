#include <iostream>

using namespace std;

struct Nodo {
    int data;
    Nodo *i;
    Nodo *d;
};

Nodo* crearNodo(int valor){
    Nodo* nodo_nuevo = new Nodo();
    nodo_nuevo -> data = valor;
    nodo_nuevo -> i = nullptr;
    nodo_nuevo -> d = nullptr;
    return nodo_nuevo;
}

//insertar elementos
Nodo* insertar(Nodo* raiz, int valor){
    // base case
    if(raiz = nullptr){
        return crearNodo(valor);
    }

    //recursive case
    if (valor < raiz->data){
            raiz -> i = insertar(raiz -> i, valor);
        } else if (valor > raiz->data) {
            raiz ->d = insertar(raiz-> d, valor);
        }
    
    return raiz;
}

void preorder(Nodo* raiz){
    if (raiz != nullptr) {
        //R
        cout << raiz->data << "->";
        //I
        preorder(raiz->i);
        //D
        preorder(raiz->d);
    }
}

void inorder(Nodo* raiz){
    if (raiz != nullptr) {
        //I
        preorder(raiz->i);
        //R
        cout << raiz->data << "->";
        //D
        preorder(raiz->d);
    }
}

void postorder(Nodo* raiz){
        if (raiz != nullptr) {
        //I
        preorder(raiz->i);
        //D
        preorder(raiz->d);
        //R
        cout << raiz->data << "->";
    }
}

void liberar(Nodo* raiz){
    //usando post para borrar
    if(raiz !=nullptr){
        //I
        liberar(raiz->i);
        //D
        liberar(raiz->d);
        //R
        delete raiz;
    }
}




int main(){


    return 0;
}