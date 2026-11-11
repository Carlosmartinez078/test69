#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>

struct Cancion
{
    std::string titulo;
    std::string artista;
    double duracion; // en minutos
    std::string genero;
    int reproducciones;
};

void SolicitarDatos(Cancion &cancion);
void MostrarPlaylist(std::list<Cancion> lista);
void BuscarPorArtista(std::list<Cancion> lista, std::string artista_buscar);

int main()
{
    int opcion;
    std::string artista_buscar;
    struct Cancion cancion;
    std::list<Cancion> lista_canciones;

    do
    {
        std::cout << "\n -Biblioteca de Musica Personal-\n";
        std::cout << "1. Agregar cancion\n";
        std::cout << "2. Ordenar y mostrar playlist (por reproducciones de mayor a menor)\n";
        std::cout << "3. Buscar canciones por artista (lower_bound)\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            SolicitarDatos(cancion);
            lista_canciones.push_front(cancion);
            std::cout << "Cancion registrada correctamente.\n";
            break;

        case 2:
            if (lista_canciones.empty())
            {
                std::cout << "La playlist esta vacia. No hay canciones registradas.\n";
            }
            else
            {
                // Ordena de mayor a menor número de reproducciones usando una función lambda
                lista_canciones.sort([](const Cancion &a, const Cancion &b) {
                    return a.reproducciones > b.reproducciones;
                });
                MostrarPlaylist(lista_canciones);
            }
            break;

        case 3:
            if (lista_canciones.empty())
            {
                std::cout << "La playlist esta vacia. No se puede realizar la busqueda.\n";
            }
            else
            {
                //lower_bound
                lista_canciones.sort([](const Cancion &a, const Cancion &b) {
                    return a.artista < b.artista;
                });
                std::cout << "Ingresa el nombre del artista a buscar: ";
                std::cin.ignore(); 
                std::getline(std::cin, artista_buscar);
                BuscarPorArtista(lista_canciones, artista_buscar);
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

void SolicitarDatos(Cancion &cancion)
{
    std::cin.ignore();

    std::cout << "Ingresar el titulo de la cancion: ";
    std::getline(std::cin, cancion.titulo);

    std::cout << "Ingresar el artista: ";
    std::getline(std::cin, cancion.artista);

    std::cout << "Ingresar la duracion (en minutos): ";
    std::string aux_duracion;
    std::getline(std::cin, aux_duracion);
    cancion.duracion = std::stod(aux_duracion);

    std::cout << "Ingresar el genero: ";
    std::getline(std::cin, cancion.genero);

    std::cout << "Ingresar el numero de reproducciones: ";
    std::string aux_repro;
    std::getline(std::cin, aux_repro);
    cancion.reproducciones = std::stoi(aux_repro);
}

void MostrarPlaylist(std::list<Cancion> lista)
{
    std::cout << "\n Mi playlist (Ordenada por Reproducciones) \n";

    int max_repro = -1;
    if (!lista.empty())
    {
        max_repro = lista.front().reproducciones;
    }

    int contador = 1;
    while (!lista.empty())
    {
        std::cout << contador << ". Titulo: " << lista.front().titulo
                  << " - Artista: " << lista.front().artista
                  << " - Duracion: " << lista.front().duracion << " min"
                  << " - Genero: " << lista.front().genero
                  << " - Reproducciones: " << lista.front().reproducciones;

        if (lista.front().reproducciones == max_repro && max_repro > 0)
        {
            std::cout << " La mas reproducida";
        }
        std::cout << "\n";

        lista.pop_front();
        contador++;
    }
}

void BuscarPorArtista(std::list<Cancion> lista, std::string artista_buscar)
{
    Cancion clave;
    clave.artista = artista_buscar;

    auto it = std::lower_bound(lista.begin(), lista.end(), clave,
                               [](const Cancion &a, const Cancion &b) {
                                   return a.artista < b.artista;
                               });

    bool encontrado = false;
    std::cout << "\nResultados de busqueda para el artista \"" << artista_buscar << "\":\n";

    while (it != lista.end() && it->artista == artista_buscar)
    {
        std::cout << "- " << it->titulo << " (" << it->duracion << " min, Genero: " << it->genero 
                  << ", Reproducciones: " << it->reproducciones << ")\n";
        encontrado = true;
        ++it;
    }

    if (!encontrado)
    {
        std::cout << "No se encontraron canciones del artista \"" << artista_buscar << "\".\n";
    }
}