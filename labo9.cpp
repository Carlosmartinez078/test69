#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// Estructura para almacenar los datos de cada canción
struct Cancion {
    string titulo;
    string artista;
    double duracion; // Duración en minutos
    string genero;
    int reproducciones;
};

void agregarCancion(list<Cancion>& biblioteca) {
    Cancion c;
    cout << "\n--- Registrar Nueva Cancion ---\n";
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, c.titulo);
    cout << "Artista: ";
    getline(cin, c.artista);
    cout << "Duracion (minutos): ";
    cin >> c.duracion;
    cout << "Genero: ";
    cin.ignore();
    getline(cin, c.genero);
    cout << "Numero de reproducciones: ";
    cin >> c.reproducciones;

    biblioteca.push_back(c);
    cout << "¡Cancion agregada con exito!\n";
}

void ordenarCanciones(list<Cancion>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "\nLa biblioteca está vacía. No hay canciones que ordenar.\n";
        return;
    }
    
    biblioteca.sort([](const Cancion& a, const Cancion& b) {
        return a.reproducciones > b.reproducciones; // Mayor a menor
    });
    
    cout << "\n¡Canciones ordenadas por número de reproducciones (de mayor a menor)!\n";
}

void buscarPorArtista(list<Cancion>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "La biblioteca está vacía.";
        return;
    }

    string artistaBuscado;
    cout << "Ingrese el nombre del artista a buscar: ";
    cin.ignore(1000, '\n');
    getline(cin, artistaBuscado);

    //lower_bound
    biblioteca.sort([](const Cancion& a, const Cancion& b) {
        return a.artista < b.artista;
    });

    auto it = lower_bound(biblioteca.begin(), biblioteca.end(), artistaBuscado,
        [](const Cancion& c, const string& nombre) {
            return c.artista < nombre;
        });

    bool encontrado = false;
    cout << "\nResultados de búsqueda para '" << artistaBuscado << "':\n";
    cout << "--------------------------------------------------\n";
    
    while (it != biblioteca.end() && it->artista == artistaBuscado) {
        cout << "Título: " << it->titulo
             << " | Género: " << it->genero 
             << " | Duración: " << it->duracion << " min"
             << " | Reproducciones: " << it->reproducciones << "\n";
        encontrado = true;
        ++it;
    }

    if (!encontrado) {
        cout << "No se encontraron canciones registradas de dicho artista.\n";
    }
}

void mostrarPlaylist(const list<Cancion>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "No hay canciones registradas en la biblioteca.";
        return;
    }

    int maxRep = -1;
    for (const auto& c : biblioteca) {
        if (c.reproducciones > maxRep) {
            maxRep = c.reproducciones;
        }
    }

    std::cout << "Biblioteca de musica" << std::endl;

    int contador = 1;
    for (const auto& c : biblioteca) {
        bool esMasReproducida = (c.reproducciones == maxRep && maxRep > 0);
        
        cout << contador++ << ". " << c.titulo << " - " << c.artista << "\n";
        cout << "   Género: " << c.genero << " | Duración: " << c.duracion << " min\n";
        cout << "   Reproducciones: " << c.reproducciones;
        
        if (esMasReproducida) {
            cout << "  <--- Mas reproducida";
        }
        cout << "\n--------------------------------------------------\n";
    }
}

// --- Función Principal / Menú ---

int main() {
    list<Cancion> biblioteca;
    int opcion;

    do {
        std::cout << "Biblioteca de Musica \n";
        std::cout << "1. Agregar cancion\n";
        std::cout << "2. Ordenar y mostrar playlist (por reproducciones)\n";
        std::cout << "3. Buscar canciones por artista (lower_bound)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (!(cin >> opcion)) {
            cout << "Opción inválida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                agregarCancion(biblioteca);
                break;
            case 2:
                ordenarCanciones(biblioteca);
                break;
            case 3:
                buscarPorArtista(biblioteca);
                break;
            case 4:
                mostrarPlaylist(biblioteca);
                break;
            case 5:
                cout << "Saliendo \n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}