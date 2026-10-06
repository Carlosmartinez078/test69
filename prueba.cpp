#include <iostream>

struct Productos {
    std::string id;
    std::string name;
    float price;
};

struct Nodo {
    Productos producto; 
    Nodo *siguiente; 
    Nodo *anterior;  
};

Nodo *inicio = nullptr; 
Nodo *fin = nullptr; 

Productos pedirDatos();
void agregarProducto(Productos producto);

int main(){
    int option;

    do{
        std::cout << "INVENTARIO DE PRODCUTOS \n";
        std::cout << "1. Agregar producto\n";
        std::cout << "2. Mostrar playlist (inicio -> fin)\n";;
        std::cout << "3. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> option;

        switch (option) {
        case 1: {
            Productos nueva = pedirDatos();

            std::cout << "///////////////////////////" << std::endl;
            agregarProducto(nueva);
        }
        break;
        case 2:
            // mostrarPlaylist();
            break;
        case 3:
            // mostrarPlaylistInversa();
            break;
    }
    } while (option != 0);
    
    return 0;
}        
 
 

Productos pedirDatos(){
    Productos nueva;

        std::cout << "Codigo: " << std::endl;
        std::cin >> nueva.id;
        std::cout << "Nombre: " << std::endl;
        std::cin >> nueva.name;
        std::cout << "Precio: " << std::endl;
        std::cin >> nueva.price;
        return nueva;
}



void InsertarInicio(Productos producto){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->producto = producto;
    nuevoNodo->siguiente = inicio;
    nuevoNodo->anterior = nullptr;

    if (inicio == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        inicio->anterior = nuevoNodo;
        inicio = nuevoNodo;
    }
    std::cout << "Prodcuto agregado \n";
}

void InsertarFinal(Productos producto){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->producto = producto;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = fin;

    if (fin == nullptr) {
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
}

    


void mostrarDatos() {
    std::cout << "Productos ---\n";

    if (inicio == nullptr)
    {
        std::cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = inicio;
    int posicion = 1;

    while (actual != nullptr)
    {
        std::cout << "\nCancion #" << posicion << "\n";
        std::cout << "  Titulo: " << actual->cancion.titulo << "\n";
        std::cout << "  Artista: " << actual->cancion.artista << "\n";
        std::cout << "  Duracion: " << actual->cancion.duracion << " min ("
                  << clasificarDuracion(actual->cancion.duracion) << ")\n";
        std::cout << "  Genero: " << actual->cancion.genero << "\n";
        actual = actual->siguiente;
        posicion++;
    }
}

