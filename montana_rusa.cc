#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Almacena los datos de cada pasajero.
struct Persona {
    string nombre;
    int numero_asiento;
    string categoria;
};
//Declarando las funciones
Persona LlenarDatosPersona(int siguiente_asiento);
void AgregarPersona(queue<Persona>& cola, const Persona& persona);
void MostrarCola(queue<Persona> cola);
void IniciarViaje(queue<Persona>& cola);

int main() {
    queue<Persona> cola;
    int siguiente_asiento = 1;
    int opcion;

    do {
        cout << "\n=== Sistema de montana rusa ===\n";
        cout << "1. Agregar persona\n";
        cout << "2. Mostrar cola\n";
        cout << "3. Iniciar viaje\n";
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
                Persona nueva = LlenarDatosPersona(siguiente_asiento);
                AgregarPersona(cola, nueva);
                siguiente_asiento++;
                break;
            }

            case 2:
                MostrarCola(cola);
                break;

            case 3:
                IniciarViaje(cola);
                break;

            case 0:
                cout << "Cerrando el sistema.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}

Persona LlenarDatosPersona(int siguiente_asiento) {
    Persona nueva_persona;
    cout << "Ingrese el nombre del pasajero: ";
    getline(cin, nueva_persona.nombre);

    cout << "Ingrese la categoria (adulto, nino, etc.): ";
    getline(cin, nueva_persona.categoria);

    nueva_persona.numero_asiento = siguiente_asiento;
    return nueva_persona;
}
// Registra una persona y le asigna un asiento consecutivo.
void AgregarPersona(queue<Persona>& cola, const Persona& persona) {
    cola.push(persona);
    cout << "Pasajero registrado. Asiento asignado: "
              << persona.numero_asiento << "\n";
}

// Muestra los pasajeros sin modificar la cola original.
void MostrarCola(queue<Persona> cola) {
    if (cola.empty()) {
        cout << "No hay personas esperando para subir.\n";
        return;
    }

    cout << "\n--- Pasajeros en espera ---\n";

    while (!cola.empty()) {
        Persona actual = cola.front();

        cout << "Nombre: " << actual.nombre << "\n";
        cout << "Asiento: "
                  << actual.numero_asiento << "\n";
        cout << "Categoria: " << actual.categoria << "\n";
        cout << "--------------------------\n";

        cola.pop();
    }
}

// Atiende hasta cinco pasajeros para iniciar un viaje.
void IniciarViaje(queue<Persona>& cola) {
    if (cola.empty()) {
        cout << "No hay pasajeros para iniciar el viaje.\n";
        return;
    }

    const int capacidad_viaje = 5;
    int pasajeros_abordados = 0;

    cout << "\n--- Pasajeros que suben al viaje ---\n";

    while (!cola.empty() && pasajeros_abordados < capacidad_viaje) {
        Persona pasajero = cola.front();

        cout << "Nombre: " << pasajero.nombre << "\n";
        cout << "Asiento: "
                  << pasajero.numero_asiento << "\n";
        cout << "Categoria: " << pasajero.categoria << "\n";
        cout << "--------------------------\n";

        cola.pop();
        pasajeros_abordados++;
    }

    cout << "Total de pasajeros que subieron: "
              << pasajeros_abordados << "\n";

    if (cola.empty()) {
        cout << "No quedan pasajeros en espera.\n";
    } else {
        cout << "Quedan " << cola.size()
                  << " pasajeros esperando.\n";
    }
}
