#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> historial;

    // Navegando por páginas web
    historial.push("google.com"); // 1
    historial.push("github.com"); // 2
    historial.push("stackoverflow.com"); // 3

    cout << "Pagina actual: " << historial.top() << endl; // stackoverflow.com

    // Presionamos el botón "Atrás"
    historial.pop();

    cout << "Pagina despues de regresar: " << historial.top() << endl; // github.com

    return 0;
}