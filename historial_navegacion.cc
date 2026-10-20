
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Almacena la informacion de una pagina visitada.
struct Pagina {
    string url;
    int numero_visitas;
    string fecha_visita;
};
//Declarando las funciones 
bool LlenarDatosPagina(Pagina& pagina);
void AgregarPagina(stack<Pagina>& historial, const Pagina& pagina);
void MostrarHistorial(stack<Pagina> historial);
void RetrocederPagina(stack<Pagina>& historial);

int main() {
    stack<Pagina> historial;
    int opcion;

    do {
        cout << "\n=== Historial de navegacion ===\n";
        cout << "1. Agregar pagina\n";
        cout << "2. Mostrar historial\n";
        cout << "3. Retroceder pagina\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ingrese una opcion valida.\n";
            continue;
               }

        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1:{
                Pagina nueva;
                if (LlenarDatosPagina(nueva)) {
                    AgregarPagina(historial, nueva);
                }
                break;
            }
            case 2:
                MostrarHistorial(historial);
                break;

            case 3:
                RetrocederPagina(historial);
                break;

            case 0:
                cout << "Cerrando el navegador.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}

bool LlenarDatosPagina(Pagina& pagina) {
    cout << "Ingrese la URL o nombre de la pagina: ";
    getline(cin, pagina.url);

    cout << "Ingrese el numero de visitas: ";
    if (!(cin >> pagina.numero_visitas) || pagina.numero_visitas < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "El numero de visitas debe ser positivo.\n";
        return false;
    }
    cin.ignore(1000, '\n');

    cout << "Ingrese la fecha de visita: ";
    getline(cin, pagina.fecha_visita);

    return true;
}
// Registra una nueva pagina en la cima de la pila.
void AgregarPagina(stack<Pagina>& historial, const Pagina& pagina) {
    historial.push(pagina);

    cout << "Pagina registrada correctamente.\n";
}

// Muestra el historial sin modificar la pila original.
void MostrarHistorial(stack<Pagina> historial) {
    if (historial.empty()) {
        cout << "El historial esta vacio.\n";
        return;
    }

    cout << "\n--- Historial de navegacion ---\n";

    int posicion = 1;

    while (!historial.empty()) {
        Pagina actual = historial.top();

        cout << "\nPagina #" << posicion << "\n";
        cout << "URL: " << actual.url << "\n";
        cout << "Numero de visitas: "
                  << actual.numero_visitas << "\n";
        cout << "Fecha de visita: "
                  << actual.fecha_visita << "\n";

        historial.pop();
        posicion++;
    }
}

// Elimina la pagina mas reciente del historial.
void RetrocederPagina(stack<Pagina>& historial) {
    if (historial.empty()) {
        cout << "No hay paginas para retroceder.\n";
        return;
    }

    cout << "Retrocediste desde "
              << historial.top().url << "\n";

    historial.pop();
}
