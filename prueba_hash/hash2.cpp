#include <iostream>
#include <string>
#include <unordered_set>

void registrarGamertag(std::unordered_set<std::string>& tablaHash, const std::string& name){
    auto resultado = tablaHash.insert(name);
    // second: true / false
    if(resultado.second){
        std::cout<<"Se agrego correctamente"<<std::endl;
    }else{
        std::cout<<"No se agrego correctamente"<<std::endl;
    }
}

void verificarDisponibilidad(std::unordered_set<std::string>& tablaHash, const std::string& name){
    if (tablaHash.find(name) != tablaHash.end()){
        std::cout << "El nombre ya esta en uso" << std::endl;
    } else {
        std::cout << "El nombre esta disponible" << std::endl;
    }
}

void expulsarJugador(std::unordered_set<std::string>& tablaHash, const std::string& name){
    if (tablaHash.erase(name)){
        std::cout << "Estas eliminado del grupo, cambia de nombre" << std::endl;
    } else {
        std::cout << "Todo bien :)" << std::endl;
    }
}
void mostrarListaJugadores(std::unordered_set<std::string>& tablaHash){
    if(tablaHash.empty()){
        std::cout<<"No hay nada"<<std::endl;
        return;
    }

    for(const auto& n : tablaHash){
        std::cout<<n<<std::endl;
        //cout<<n.size()<<endl;
    }
}

void limpiarDatos(std::unordered_set<std::string>& tablaHash){
    tablaHash.clear();
}

int main(){
    std::unordered_set<std::string> jugadoresServidor;

    // Pruebas que debe pasar tu programa:
    registrarGamertag(jugadoresServidor, "ShadowNinja");
    registrarGamertag(jugadoresServidor, "Valkyrie99");
    registrarGamertag(jugadoresServidor, "ShadowNinja"); // ¡Debería fallar por repetido!

    std::cout << "\n--- Jugadores en línea ---" << std::endl;
    mostrarListaJugadores(jugadoresServidor);

    std::cout << "\n--- Verificando nombres ---" << std::endl;
    verificarDisponibilidad(jugadoresServidor, "Phoenix");
    verificarDisponibilidad(jugadoresServidor, "Valkyrie99");

    std::cout << "\n--- Expulsando a un jugador ---" << std::endl;
    expulsarJugador(jugadoresServidor, "Valkyrie99");

    std::cout << "\n--- Jugadores finales ---" << std::endl;
    mostrarListaJugadores(jugadoresServidor);

    return 0;
}