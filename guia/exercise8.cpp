#include <iostream>

struct Producto {
    std::string nombre;
    float precio;
};

Producto* productExpensive(Producto* Pproducto, int tamano);

int main(){
    int longi = 3;
    Producto productos2 [longi] = {
        {"Raid", 20},
        {"Huevos", 50},
        {"Agua", 0.25}
    };

    Producto* mayor = productExpensive(productos2, longi); // llamar la funcion de esa manera si piden que retorne algo

    if (mayor != nullptr) {
        std::cout << "\nEl producto mas caro es: " << mayor->nombre << std::endl;
        std::cout << "Precio: $" << mayor->precio << std::endl;
    }

    return 0;
}


Producto* productExpensive(Producto* Pproducto, int tamano){
    if (tamano <= 0) {
        std::cout << "El arreglo esta vacio." << std::endl;
        return nullptr;
    } 
    
    Producto* mayor = Pproducto; // Puntero al primer elemento - hace la funcion de buscar el mayo

    std::cout << "Lista de productos:" << std::endl;
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
