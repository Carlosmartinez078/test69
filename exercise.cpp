#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Parte 1 — Modelado del elemento
struct Elemento {
    string codigo;
    string nombre;
    float longitud;
    float cargas[3];
    float capacidadMaxima;
    float factorUtilizacion;
    string estadoSeguridad;
};

// Parte 2 — Registro de elementos
void registrarElemento(Elemento &elemento) {
    cout << "\n--- Registro de Elemento ---\n";
    cout << "Código: ";
    cin >> elemento.codigo;
    cin.ignore(); // Limpia el buffer antes de leer cadenas con espacios
    cout << "Nombre: ";
    getline(cin, elemento.nombre);
    cout << "Longitud (m): ";
    cin >> elemento.longitud;
    cout << "Carga 1 (N): ";
    cin >> elemento.cargas[0];
    cout << "Carga 2 (N): ";
    cin >> elemento.cargas[1];
    cout << "Carga 3 (N): ";
    cin >> elemento.cargas[2];
    cout << "Capacidad máxima (N): ";
    cin >> elemento.capacidadMaxima;
}

// Parte 3 — Cálculo del factor de utilización (mediante puntero)
float calcularFactor(Elemento *elemento) {
    float sumaCargas = elemento->cargas[0] + elemento->cargas[1] + elemento->cargas[2];
    float cargaPromedio = sumaCargas / 3.0f;
    
    elemento->factorUtilizacion = cargaPromedio / elemento->capacidadMaxima;
    return elemento->factorUtilizacion;
}

// Parte 4 — Determinación del estado de seguridad
void determinarSeguridad(Elemento &elemento) {
    float factor = elemento.factorUtilizacion;

    if (factor >= 0.0f && factor <= 0.50f) {
        elemento.estadoSeguridad = "SEGURO";
    } else if (factor > 0.50f && factor <= 0.80f) {
        elemento.estadoSeguridad = "PRECAUCION";
    } else if (factor > 0.80f && factor <= 1.00f) {
        elemento.estadoSeguridad = "RIESGO";
    } else {
        elemento.estadoSeguridad = "SOBRECARGA";
    }
}

// Parte 5 — Identificación del elemento más comprometido
Elemento* obtenerElementoCritico(Elemento elementos[], int cantidad) {
    if (cantidad <= 0) return nullptr;

    Elemento* critico = &elementos[0];
    for (int i = 1; i < cantidad; i++) {
        if (elementos[i].factorUtilizacion > critico->factorUtilizacion) {
            critico = &elementos[i];
        }
    }
    return critico;
}

// Parte 6 — Simulación de incremento de carga
void aumentarCargas(Elemento &elemento, float porcentaje) {
    elemento.cargas[0] *= (1.0f + porcentaje / 100.0f);
    elemento.cargas[1] *= (1.0f + porcentaje / 100.0f);
    elemento.cargas[2] *= (1.0f + porcentaje / 100.0f);

    // Recalcular métricas tras el aumento
    calcularFactor(&elemento);
    determinarSeguridad(elemento);
}

// Parte 7 — Informe
void generarInforme(Elemento elementos[], int cantidad) {
    cout << "\n================================ INFORME GENERAL ================================\n";
    cout << left << setw(10) << "Código" 
         << setw(20) << "Nombre" 
         << setw(18) << "Carga Prom. (N)" 
         << setw(15) << "Factor Util." 
         << setw(15) << "Estado" << "\n";
    cout << "--------------------------------------------------------------------------------\n";

    int cantSeguro = 0, cantPrecaucion = 0, cantRiesgo = 0, cantSobrecarga = 0;
    float sumaFactores = 0.0f;

    for (int i = 0; i < cantidad; i++) {
        float cargaPromedio = (elementos[i].cargas[0] + elementos[i].cargas[1] + elementos[i].cargas[2]) / 3.0f;

        cout << left << setw(10) << elementos[i].codigo
             << setw(20) << elementos[i].nombre
             << setw(18) << fixed << setprecision(2) << cargaPromedio
             << setw(15) << setprecision(2) << elementos[i].factorUtilizacion
             << setw(15) << elementos[i].estadoSeguridad << "\n";

        if (elementos[i].estadoSeguridad == "SEGURO") cantSeguro++;
        else if (elementos[i].estadoSeguridad == "PRECAUCION") cantPrecaucion++;
        else if (elementos[i].estadoSeguridad == "RIESGO") cantRiesgo++;
        else if (elementos[i].estadoSeguridad == "SOBRECARGA") cantSobrecarga++;

        sumaFactores += elementos[i].factorUtilizacion;
    }

    float factorPromedioEstructura = sumaFactores / cantidad;

    cout << "--------------------------------------------------------------------------------\n";
    cout << "CONTEO POR ESTADO:\n";
    cout << "  - SEGURO: " << cantSeguro << "\n";
    cout << "  - PRECAUCION: " << cantPrecaucion << "\n";
    cout << "  - RIESGO: " << cantRiesgo << "\n";
    cout << "  - SOBRECARGA: " << cantSobrecarga << "\n";
    cout << "\nFACTOR DE UTILIZACIÓN PROMEDIO DE LA ESTRUCTURA: " << fixed << setprecision(2) << factorPromedioEstructura << "\n";
    cout << "================================================================================\n";
}

int main() {
    Elemento elementos[10];
    int cantidad = 0;

    // Validación de la cantidad de elementos (1 a 10)
    do {
        cout << "Ingrese la cantidad de elementos a registrar (1 a 10): ";
        cin >> cantidad;
        if (cantidad < 1 || cantidad > 10) {
            cout << "Cantidad fuera de rango. Intente nuevamente.\n";
        }
    } while (cantidad < 1 || cantidad > 10);

    // Registro y cálculo de factores
    for (int i = 0; i < cantidad; i++) {
        cout << "\n>>> REGISTRO DEL ELEMENTO [" << (i + 1) << " DE " << cantidad << "] <<<";
        registrarElemento(elementos[i]);

        // Procesamiento mediante puntero requeridos en la Parte 3
        calcularFactor(&elementos[i]);
        determinarSeguridad(elementos[i]);
    }

    // Parte 5: Identificar y mostrar elemento más comprometido
    Elemento* critico = obtenerElementoCritico(elementos, cantidad);
    if (critico != nullptr) {
        cout << "\n================ ELEMENTO MÁS COMPROMETIDO (CRÍTICO) ================\n";
        cout << "Código: " << critico->codigo << "\n";
        cout << "Nombre: " << critico->nombre << "\n";
        cout << "Longitud: " << critico->longitud << " m\n";
        cout << "Carga 1: " << critico->cargas[0] << " N\n";
        cout << "Carga 2: " << critico->cargas[1] << " N\n";
        cout << "Carga 3: " << critico->cargas[2] << " N\n";
        cout << "Capacidad Máxima: " << critico->capacidadMaxima << " N\n";
        cout << "Factor de Utilización: " << fixed << setprecision(2) << critico->factorUtilizacion << "\n";
        cout << "Estado de Seguridad: " << critico->estadoSeguridad << "\n";

        // Parte 6: Simulación de incremento de carga sobre el elemento crítico
        float porcentaje;
        cout << "\n--- Simulación de Incremento de Cargas ---";
        cout << "\nIngrese el porcentaje de aumento para el elemento " << critico->codigo << " (%): ";
        cin >> porcentaje;

        aumentarCargas(*critico, porcentaje);

        cout << "\n[NUEVO ESTADO TRAS EL INCREMENTO]\n";
        cout << "Nuevas cargas: [" << critico->cargas[0] << ", " << critico->cargas[1] << ", " << critico->cargas[2] << "] N\n";
        cout << "Nuevo Factor de Utilización: " << fixed << setprecision(2) << critico->factorUtilizacion << "\n";
        cout << "Nuevo Estado de Seguridad: " << critico->estadoSeguridad << "\n";
    }

    // Parte 7: Generar el informe general final
    generarInforme(elementos, cantidad);

    return 0;
}