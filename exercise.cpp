#include <iostream>

struct Elemento {
    int codigo, longitud,capacidad,utlizacion;
    std::string nombre;
    std::string seguridad;
    float cargas [3];
};

void registrarElementos (Elemento* Pelemento);
void promedio (Elemento* Pelemento);

int main(){
    Elemento elemento1;

    registrarElementos(&elemento1);

    return 0;
}



void registrarElementos (Elemento& Pelemento){
    Pelemento.cargas[3];
    
    std::cout << "Ingrese el codigo del elemento" << std::endl;
    std::cin >> Pelemento->codigo;
    std::cout << "Ingrese el nombre del elemento" << std::endl;
    std::cin >> Pelemento->nombre;
    std::cout << "Ingrese la longitud del elemento" << std::endl;
    std::cin >> Pelemento->longitud;
    std::cout << "Ingrese la capacidad maxima" << std::endl;
    std::cin >> Pelemento->capacidad;
    std::cout << "Ingrese las cargas" << std::endl;
    for (int i = 0; i < n; i++){
        std::cin >> Pelemento->cargas[n];
        std::cout << "Elemento: " << i+1 << std::endl;
        for (int i = 0; i < n; i++){
        }
        std::cout << Pelemento->cargas[n] << std::endl;
    }
}

void promedio (Elemento* Pelemento){
    float promedio = Pelemento->cargas/3;

    }
     
    