#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Definimos la estructura con las pilas y la página actual
struct Navegador {
    stack<string> historialAtras;
    stack<string> historialAdelante;
    string paginaActual;
};

// Función para visitar una nueva URL
void visitar(Navegador& nav, string nuevaUrl) {
    // 1. Guardar la paginaActual en nav.historialAtras
    // 2. Actualizar nav.paginaActual con nuevaUrl
    // 3. Vaciar nav.historialAdelante (usando un bucle while !empty() y pop())
}

// Función para ir atrás
void atras(Navegador& nav) {
    // 1. Verificar si nav.historialAtras está vacía.
    // 2. Si NO está vacía:
    //    - Guardar nav.paginaActual en nav.historialAdelante
    //    - Cambiar nav.paginaActual por nav.historialAtras.top()
    //    - Hacer nav.historialAtras.pop()
}

// Función para ir adelante
void adelante(Navegador& nav) {
    // 1. Verificar si nav.historialAdelante está vacía.
    // 2. Si NO está vacía:
    //    - Guardar nav.paginaActual en nav.historialAtras
    //    - Cambiar nav.paginaActual por nav.historialAdelante.top()
    //    - Hacer nav.historialAdelante.pop()
}

void mostrarEstado(Navegador nav) {
    cout << "📍 Página actual: " << nav.paginaActual << endl;
}

int main() {
    // Crear el navegador e iniciar en Google
    Navegador miNavegador;
    miNavegador.paginaActual = "google.com";

    mostrarEstado(miNavegador);

    // Pruebas
    visitar(miNavegador, "youtube.com");
    mostrarEstado(miNavegador);

    visitar(miNavegador, "github.com");
    mostrarEstado(miNavegador);

    cout << "\n--- Probando Atrás ---" << endl;
    atras(miNavegador);
    mostrarEstado(miNavegador); // Debería ser youtube.com

    atras(miNavegador);
    mostrarEstado(miNavegador); // Debería ser google.com

    cout << "\n--- Probando Adelante ---" << endl;
    adelante(miNavegador);
    mostrarEstado(miNavegador); // Debería ser youtube.com

    cout << "\n--- Probando Nueva Visita (Borra Adelante) ---" << endl;
    visitar(miNavegador, "wikipedia.org");
    mostrarEstado(miNavegador);

    adelante(miNavegador); // No debería hacer nada porque adelante se vació

    return 0;
}