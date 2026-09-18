#include <iostream>

struct Rectangulo {
    float ancho, alto;
};

void numberCero(Rectangulo& Prectangulo);
float operacion(const Rectangulo& Prectangulo); // Devuelve el área como float

int main() {
    Rectangulo recta1 = {-2, 5}; // Probamos con un valor negativo
    
    std::cout << "Ancho: " << recta1.ancho << " | Alto: " << recta1.alto << std::endl;
    std::cout << "///////////////////////" << std::endl;

    numberCero(recta1);

    
    float area = operacion(recta1);
    std::cout << "El area es: " << area << std::endl;

    return 0;
}

// Se asegura de que si el alto O el ancho son menores a 0, se hagan 0
void numberCero(Rectangulo& Prectangulo) {
    if (Prectangulo.alto < 0) {
        Prectangulo.alto = 0;
    }
    if (Prectangulo.ancho < 0) {
        Prectangulo.ancho = 0;
    }
}

// Calcula y retorna el área sin modificar la estructura original devuelve algo
float operacion(const Rectangulo& Prectangulo) {
    return Prectangulo.alto * Prectangulo.ancho;
}