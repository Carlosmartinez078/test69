#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void agregarOActualizar(unordered_map<string, int>& tablaHash, const string& juego, int cantidad){
    tablaHash[juego] = cantidad;
    cout << "Se agrego o actualizo correctamente: " << juego << " (" << cantidad << " unidades)" << endl;
}

void consultarStock(unordered_map<string, int>& tablaHash, const string& juego){
    auto it = tablaHash.find(juego);
    if(it != tablaHash.end()){
        cout << "El juego existe. Stock disponible: " << it->second << endl;
    }else{
        cout << "El elemento no existe en el inventario" << endl;
    }
}

void eliminarJuego(unordered_map<string, int>& tablaHash, const string& juego){
    if(tablaHash.erase(juego)){
        cout << "Se elimino correctamente el juego" << endl;
    }else{
        cout << "El elemento no existe" << endl;
    }
}

void mostrarInventario(unordered_map<string, int>& tablaHash) {
    if(tablaHash.empty()) {
        cout << "El inventario esta vacio" << endl;
        return;
    }

    for(const auto& par : tablaHash) {
        // par.first es la clave (el juego)
        // par.second es el valor (la cantidad)
        cout << "Juego: " << par.first << " | Stock: " << par.second << endl;
    }
}

void limpiar(unordered_map<string, int>& tablaHash){
    tablaHash.clear();
    cout << "Inventario limpiado por completo." << endl;
}

int main() {
    unordered_map<string, int> inventarioTienda;

    agregarOActualizar(inventarioTienda, "Zelda: TotK", 10);
    agregarOActualizar(inventarioTienda, "Minecraft", 25);
    agregarOActualizar(inventarioTienda, "Zelda: TotK", 8); // ¡Ahora sí actualiza el stock a 8!

    cout << "\n--- Inventario Actual ---" << endl;
    mostrarInventario(inventarioTienda);

    cout << "\n--- Consultando juegos ---" << endl;
    consultarStock(inventarioTienda, "Minecraft");
    consultarStock(inventarioTienda, "Halo Infinite"); // No debería existir

    cout << "\n--- Retirando un juego ---" << endl;
    eliminarJuego(inventarioTienda, "Minecraft");

    cout << "\n--- Inventario Final ---" << endl;
    mostrarInventario(inventarioTienda);

    return 0;
}