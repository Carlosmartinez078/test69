#include <iostream>

void changeArreglo(int* arreglo, int tamano);

int main(){
    int longitud = 6; 
    int number [] = {2, -3, 4, -6, 8, -5};

    changeArreglo(number, longitud); // mandar variables sin nada porque ya esta como puntero

    return 0;
}

void changeArreglo(int* arreglo, int tamano){
    for (int i = 0; i < tamano; i++) {
        std::cout << "Elementos. " << arreglo[i] << std::endl;
        std::cout << std::endl;
        if (arreglo[i] < 0) {
        arreglo[i] = 0; // si cumple que son menor a 0 hacer que se hagan cero si o si
        }
    std::cout << "Elementos despues del cambio. " << arreglo[i] << std::endl;
    std::cout << std::endl;
    }    
}