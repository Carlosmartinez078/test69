// buscar mayor puntero

#include <iostream>

struct Numero {
    int valor;
};

void mostrarYBuscarMayor(Numero* arreglo, int tamano);

int main() {
    int n = 5;
    Numero numeros[5] = {{12}, {45}, {7}, {89}, {23}};

    mostrarYBuscarMayor(numeros, n);

    return 0;
}

void mostrarYBuscarMayor(Numero* arreglo, int tamano) {
    if (tamano <= 0) {
        std::cout << "El arreglo esta vacio." << std::endl;
        return;
    }

    Numero* mayor = arreglo; // Inicializamos el puntero al primer elemento

    std::cout << "Lista de numeros:" << std::endl;
    for (int i = 0; i < tamano; ++i) {
        // 1. Mostramos el valor actual del arreglo
        std::cout << "- " << (arreglo + i)->valor << std::endl;

        // 2. Comprobamos si el elemento actual es mayor que el registrado
        if ((arreglo + i)->valor > mayor->valor) {
            mayor = (arreglo + i);
        }
    }

    // Impresión del resultado final
    std::cout << "\nEl numero mayor es: " << mayor->valor << std::endl;
}
