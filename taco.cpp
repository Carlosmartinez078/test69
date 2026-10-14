#include <iostream>
#include <stack>

int main() {
    std::stack<int> miPila;

    // 1. Insertamos elementos con .push()
    miPila.push(10);
    miPila.push(20);
    miPila.push(30); // Pila actual (de abajo a arriba): [10, 20, 30]

    // 2. Consultamos el elemento superior con .top()
    cout << "Elemento arriba: " << miPila.top() << std::endl; // Imprime: 30

    // 3. Eliminamos el elemento superior con .pop()
    miPila.pop(); // Elimina el 30. Pila actual: [10, 20]

    // Consultamos de nuevo
    cout << "Nuevo elemento arriba: " << miPila.top() << std::endl; // Imprime: 20

    // Recorrer y vaciar la pila ordenadamente
    cout << "Vaciando la pila: ";
    while (!miPila.empty()) {
        cout << miPila.top() << " "; // Leemos el de arriba
        miPila.pop();                     // Lo quitamos
    }
    // Salida: 20 10

    return 0;
}