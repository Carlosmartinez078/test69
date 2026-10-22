#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>

struct Cancion
{
    std::string titulo;
    std::string artista;
    float duracion; // en minutos
    std::string genero;
    int reproducciones;
};

void SolicitarDatos(Cancion &cancion);
void MostrarPlaylist(std::list<Cancion> lista);
bool CompararReproducciones(const Cancion &a, const Cancion &b);
bool CompararArtistas(const Cancion &a, const Cancion &b);
void BuscarCancionPorArtista(std::list<Cancion> lista, std::string artista_buscar);

int main()
{
    int opcion;
    std::string artista_buscar;
    struct Cancion cancion;
    std::list<Cancion> playlist;

    do
    {
        std::cout << "\n=== Biblioteca de Musica Personal ===\n";
        std::cout << "1. Agregar cancion\n";
        std::cout << "2. Ordenar y mostrar playlist (por reproducciones)\n";
        std::cout << "3. Buscar canciones por artista (lower_bound)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            SolicitarDatos(cancion);
            playlist.push_front(cancion);
            std::cout << "Cancion registrada correctamente en la playlist.\n";
            break;

        case 2:
            if (playlist.empty())
            {
                std::cout << "La playlist esta vacia. Agregue canciones primero.\n";
            }
            else
            {
                // Ordenar de mayor a menor por número de reproducciones
                playlist.sort(CompararReproducciones);
                MostrarPlaylist(playlist);
            }
            break;

        case 3:
            if (playlist.empty())
            {
                std::cout << "La playlist esta vacia. No se puede realizar la busqueda.\n";
            }
            else
            {
                // Se asegura que la lista este ordenada alfabeticamente por artista antes de usar lower_bound
                playlist.sort(CompararArtistas);
                std::cout << "Ingrese el nombre del artista a buscar: ";
                std::cin >> artista_buscar;
                BuscarCancionPorArtista(playlist, artista_buscar);
            }
            break;

        case 0:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}

void SolicitarDatos(Cancion &cancion) {
    std::cout << "Ingresar el titulo de la cancion: ";
    std::cin >> cancion.titulo;

    std::cout << "Ingresar el artista: ";
    std::cin >> cancion.artista;

    std::cout << "Ingresar la duracion (en minutos): ";
    std::cin >> cancion.duracion;

    std::cout << "Ingresar el genero: ";
    std::cin >> cancion.genero;

    std::cout << "Ingresar el numero de reproducciones: ";
    std::cin >> cancion.reproducciones;
}

void MostrarPlaylist(std::list<Cancion> lista) {
    std::cout << "Mi playlist de musica \n";
    int contador = 1;

    while (!lista.empty()) {
        std::cout << contador << ". Título: " << lista.front().titulo;
        std::cout << " | Artista: " << lista.front().artista;
        std::cout << " | Duración: " << lista.front().duracion << " min";
        std::cout << " | Género: " << lista.front().genero;
        std::cout << " | Reproducciones: " << lista.front().reproducciones;

        if (contador == 1) {
            std::cout << "La mas reproducida";
        }
        std::cout<<std::endl;

        lista.pop_front();
        contador++;
    }
}

bool CompararReproducciones(const Cancion &a, const Cancion &b) {
    // De mayor a menor reproducciones
    return a.reproducciones > b.reproducciones;
}

bool CompararArtistas(const Cancion &a, const Cancion &b){
    // Orden alfabético para que lower_bound funcione correctamente
    return a.artista < b.artista;
}

void BuscarCancionPorArtista(std::list<Cancion> lista, std::string artista_buscar) {
    Cancion clave;
    clave.artista = artista_buscar;

    // Utilizando lower_bound para encontrar la posición inicial del artista
    auto it = std::lower_bound(lista.begin(), lista.end(), clave, CompararArtistas);

    bool encontrado = false;
    std::cout << " Resultados de busqueda para el artista " << artista_buscar << std::endl;

    // Recorremos mientras el iterador sea válido y coincida el artista buscado
    while (it != lista.end() && it->artista == artista_buscar)
    {
        std::cout << "- Título: " << it->titulo;
        std::cout << " | Género: " << it->genero;
        std::cout << " | Duración: " << it->duracion << " min";
        std::cout << " | Reproducciones: " << it->reproducciones << std::endl;
        encontrado = true;
        ++it;
    }

    if (!encontrado)
    {
        std::cout << "No se encontro ninguna cancion del artista \"" << artista_buscar << "\".\n";
    }
}