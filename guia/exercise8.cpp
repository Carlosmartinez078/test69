#include <iostream>

struct Producto {
    std::string nombre;
    float precio;
};

Producto* productExpensive(Producto* Pproducto, int tamano);

int main(){

    return 0;
}


Producto* productExpensive(Producto* Pproducto, int tamano){
    if (tamano <= 0) {
        std::cout << "El arreglo esta vacio." << std::endl;
        return nullptr;
    } 
    
    Producto* mayor = Pproducto; // Puntero al primer elemento

    std::cout << "Lista de numeros:" << std::endl;
    for (int i = 0; i < tamano; ++i) {
        // 1. Mostramos el valor actual del arreglo
        std::cout << "- " << (Pproducto + i)->precio << std::endl;

        // 2. Comprobamos si el elemento actual es mayor que el registrado
        if ((Pproducto + i)->precio > mayor->precio) {
            mayor = (Pproducto + i);
        }
    }
    return mayor;
}
