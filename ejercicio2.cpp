#include <iostream>
#include <string>
#include <limits> // Necesario para numeric_limits

using namespace std;

struct Elemento {
    string codigo;
    string nombre;
    float longitud;
    float cargas[3];
    float capacidadMaxima;
    float factorUtilizacion;
    string estadoSeguridad;
};

void registrarElemento(Elemento &elemento);
float calcularFactor(Elemento *elemento);
void determinarSeguridad(Elemento &elemento);

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos a registrar (1 a 10): ";
    cin >> n;

    while (n < 1 || n > 10) {
        cout << "Cantidad invalida. Ingrese un valor entre 1 y 10: ";
        cin >> n;
    }

    Elemento elementos[10];

    // 1. Registro de datos
    for (int i = 0; i < n; i++) {
        cout << "\n=== REGISTRANDO ELEMENTO " << i + 1 << " ===\n";
        registrarElemento(elementos[i]);
    }

    // 2. Procesamiento de datos
    for (int i = 0; i < n; i++) {
        calcularFactor(&elementos[i]);
        determinarSeguridad(elementos[i]);
    }

    // 3. Mostrar resultados
    cout << "\n================ RESULTADOS ================\n";
    for (int i = 0; i < n; i++) {
        cout << "\nElemento " << i + 1 << " - " << elementos[i].nombre << " (" << elementos[i].codigo << ")\n";
        cout << "Factor de utilizacion: " << elementos[i].factorUtilizacion << endl;
        cout << "Estado de seguridad: " << elementos[i].estadoSeguridad << endl;
    }

    return 0;
}

void registrarElemento(Elemento &elemento) {
    cout << "Codigo: ";
    cin >> elemento.codigo;

    // Limpiamos el salto de linea pendiente antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre: ";
    getline(cin, elemento.nombre);

    cout << "Longitud: ";
    cin >> elemento.longitud;

    for (int i = 0; i < 3; i++) {
        cout << "Carga " << i + 1 << ": ";
        cin >> elemento.cargas[i];
    }

    cout << "Capacidad maxima: ";
    cin >> elemento.capacidadMaxima;
}

float calcularFactor(Elemento *elemento) {
    float sumaCargas = elemento->cargas[0] + elemento->cargas[1] + elemento->cargas[2];
    float cargaPromedio = sumaCargas / 3.0f;
    elemento->factorUtilizacion = cargaPromedio / elemento->capacidadMaxima;
    return elemento->factorUtilizacion;
}

void determinarSeguridad(Elemento &elemento) {
    float f = elemento.factorUtilizacion;

    if (f <= 0.50f) {
        elemento.estadoSeguridad = "SEGURO";
    } else if (f <= 0.80f) {
        elemento.estadoSeguridad = "PRECAUCION";
    } else if (f <= 1.00f) {
        elemento.estadoSeguridad = "RIESGO";
    } else {
        elemento.estadoSeguridad = "SOBRECARGA";
    }
}