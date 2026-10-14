#include <iostream>
#include <string>

// Struct para almacenar los datos de una canción
struct Cancion {
    string titulo;
    string artista;
    float duracion; // en minutos
    string genero;
};

// Struct Nodo - Representa cada nodo de la lista

struct Nodo {
    Cancion cancion; // Dato almacenado en el nodo
    Nodo* siguiente; // Puntero al siguiente nodo
    Nodo* anterior;  // Puntero al nodo anterior
};

// Variables globales

Nodo *inicio = nullptr; // Puntero al primer nodo
Nodo *fin = nullptr;    // Puntero al último nodo

// Declaraciones de funciones
Cancion pedirDatosCancion();
void agregarCancion(Cancion cancion);
void mostrarPlaylist();
void mostrarPlaylistInversa();
void buscarCancion(Cancion cancion);
void eliminarCancion(Cancion cancion);
void contarCanciones();
void calcularDuracionTotal();
void liberarMemoria();
string clasificarDuracion(float duracion);

int main()
{
    int opcion;

    do
    {
        cout << "\n=== Biblioteca de Canciones ===\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar playlist (inicio -> fin)\n";
        cout << "3. Mostrar playlist (fin -> inicio)\n";
        cout << "4. Buscar cancion\n";
        cout << "5. Eliminar cancion\n";
        cout << "6. Duracion total de playlist\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion)
        {
        case 1:
        {
            Cancion nueva = pedirDatosCancion();
            agregarCancion(nueva);
        }
        break;
        case 2:
            mostrarPlaylist();
            break;
        case 3:
            mostrarPlaylistInversa();
            break;
        case 4:
        {
            Cancion buscada;

            cout << "\n--- Buscar cancion ---\n";
            cout << "Ingrese el titulo de la cancion: ";
            getline(cin, buscada.titulo);

            buscarCancion(buscada);
            break;
        }
        case 5:
        {
            Cancion eliminada;

            cout << "\n--- Eliminar cancion ---\n";
            cout << "Ingrese el titulo de la cancion a eliminar: ";
            getline(cin, eliminada.titulo);

            eliminarCancion(eliminada);
            break;
        }
        case 6:
            calcularDuracionTotal();
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            liberarMemoria();
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
        }
        } while (opcion != 0);

        return 0;
}

// Pedir los datos de una canción
Cancion pedirDatosCancion() {
    Cancion nueva;

    cout << "\n--- Agregar nueva cancion ---\n";
    cout << "Titulo: ";
    getline(cin, nueva.titulo);
    cout << "Artista: ";
    getline(cin, nueva.artista);
    cout << "Duracion (minutos): ";
    while (!(cin >> nueva.duracion) || nueva.duracion < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        if (nueva.duracion < 0)
        {
            cout << "No se aceptan numeros negativos. Intente nuevamente: ";
        }
        else
        {
            cout << "Solo se aceptan numeros. Intente nuevamente: ";
        }
    }
    cin.ignore();
    cout << "Genero: ";
    getline(cin, nueva.genero);
    return nueva;
}

// Agregar una canción al final de la lista

void agregarCancion(Cancion cancion)
{
    // Crear el nuevo nodo
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->cancion = cancion;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;

    // Insertar en la lista
    if (inicio == nullptr)
    {
        // Lista vacía - primer elemento
        inicio = nuevo_nodo;
        fin = nuevo_nodo;
    }
    else
    {
        // Insertar al final
        nuevo_nodo->anterior = fin;
        fin->siguiente = nuevo_nodo;
        fin = nuevo_nodo;
    }

    cout << "Cancion agregada exitosamente!\n";
}

// Mostrar playlist de inicio a fin

void mostrarPlaylist()
{
    cout << "\n--- Playlist (inicio -> fin) ---\n";

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

// Mostrar playlist de fin a inicio

void mostrarPlaylistInversa()
{
    cout << "\n--- Playlist (fin -> inicio) ---\n";

    if (fin == nullptr)
    {
        cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = fin;
    int posicion = 1;

    while (actual != nullptr)
    {
        cout << "\nCancion #" << posicion << "\n";
        cout << "  Titulo: " << actual->cancion.titulo << "\n";
        cout << "  Artista: " << actual->cancion.artista << "\n";
        cout << "  Duracion: " << actual->cancion.duracion << " min ("
                  << clasificarDuracion(actual->cancion.duracion) << ")\n";
        cout << "  Genero: " << actual->cancion.genero << "\n";
        actual = actual->anterior;
        posicion++;
    }
}

// Buscar una canción por título

void buscarCancion(Cancion cancion)
{
    if (inicio == nullptr)
    {
        cout << "La playlist esta vacia.\n";
        return;
    }

    Nodo *actual = inicio;
    bool encontrada = false;

    while (actual != nullptr)
    {
        if (actual->cancion.titulo == cancion.titulo)
        {
            cout << "\nCancion encontrada:\n";
            cout << "  Titulo: " << actual->cancion.titulo << "\n";
            cout << "  Artista: " << actual->cancion.artista << "\n";
            cout << "  Duracion: " << actual->cancion.duracion << " min\n";
            cout << "  Genero: " << actual->cancion.genero << "\n";
            encontrada = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrada)
    {
        cout << "Cancion no encontrada.\n";
    }
}

// Eliminar una canción por título

void eliminarCancion(Cancion cancion)
{
    if (inicio == nullptr)
    {
        cout << "La playlist esta vacia. No hay nada que eliminar.\n";
        return;
    }

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        if (actual->cancion.titulo == cancion.titulo)
        {
            // Caso 1: Un solo nodo
            if (actual == inicio && actual == fin)
            {
                inicio = nullptr;
                fin = nullptr;
            }
            // Caso 2: Nodo al inicio
            else if (actual == inicio)
            {
                inicio = inicio->siguiente;
                inicio->anterior = nullptr;
            }
            // Caso 3: Nodo al final
            else if (actual == fin)
            {
                fin = fin->anterior;
                fin->siguiente = nullptr;
            }
            // Caso 4: Nodo en medio
            else
            {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;

            cout << "Cancion eliminada exitosamente!\n";
            return;
        }
        actual = actual->siguiente;
    }

    cout << "Cancion no encontrada.\n";
}

// Calcular duración total de la playlist

void calcularDuracionTotal()
{
    cout << "\n--- Duracion total de playlist ---\n";

    if (inicio == nullptr)
    {
        cout << "La playlist esta vacia. Duracion total: 0 min\n";
        return;
    }

    float duracion_total = 0;
    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        duracion_total += actual->cancion.duracion;
        actual = actual->siguiente;
    }

    cout << "Duracion total: " << duracion_total << " minutos\n";
    cout << "Equivale a: " << (int)duracion_total << " min "
              << (int)((duracion_total - (int)duracion_total) * 60) << " segundos\n";
}

// Clasificar duración de una canción

string clasificarDuracion(float duracion)
{
    if (duracion < 3.0f)
    {
        return "Corta";
    }
    else if (duracion < 5.0f)
    {
        return "Media";
    }
    else
    {
        return "Larga";
    }
}

// Liberar memoria al salir del programa

void liberarMemoria()
{
    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        Nodo *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    inicio = nullptr;
    fin = nullptr;
    cout << "Memoria liberada. Hasta luego!\n";
}
