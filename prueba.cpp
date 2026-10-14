#include <iostream>

struct Productos {
    string id;
    string name;
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
        cout << "INVENTARIO DE PRODCUTOS \n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar playlist (inicio -> fin)\n";;
        cout << "3. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option) {
        case 1: {
            Productos nueva = pedirDatos();

            cout << "///////////////////////////" << std::endl;
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

        cout << "Codigo: " << std::endl;
        cin >> nueva.id;
        cout << "Nombre: " << std::endl;
        cin >> nueva.name;
        cout << "Precio: " << std::endl;
        cin >> nueva.price;
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
    cout << "Prodcuto agregado \n";
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
    cout << "Productos ---\n";

    if (inicio == nullptr)
    {
        cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = inicio;
    int posicion = 1;

    while (actual != nullptr)
    {
        cout << "\nCancion #" << posicion << "\n";
        cout << "  Titulo: " << actual->cancion.titulo << "\n";
        cout << "  Artista: " << actual->cancion.artista << "\n";
        cout << "  Duracion: " << actual->cancion.duracion << " min ("
                  << clasificarDuracion(actual->cancion.duracion) << ")\n";
        cout << "  Genero: " << actual->cancion.genero << "\n";
        actual = actual->siguiente;
        posicion++;
    }
}

