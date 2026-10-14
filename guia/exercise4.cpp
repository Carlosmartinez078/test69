//actualizar saldo referencia

#include <iostream>

struct cuenta {
    int saldo;
};

void actualizarSaldo (cuenta& Pcuenta, int monto); // por referencia

main(){
    cuenta Cuenta1;
    Cuenta1.saldo= 500;

    actualizarSaldo (Cuenta1, 200);

    return 0;
}

void actualizarSaldo (cuenta& Pcuenta, int monto){
    if (Pcuenta.saldo >= monto) {
        cout << "Su saldo es: " << Pcuenta.saldo << std::endl;
        cout << "el monto de su compra es: " << monto << std::endl;
        
        Pcuenta.saldo = Pcuenta.saldo - monto; // se actualiza el valor dentro de la funcion por enviar por referencia 

        cout << "Transacción exitosa. Nuevo Saldo: " << Pcuenta.saldo << std::endl;
    } else {
        // Es buena práctica agregar un aviso si la condición no se cumple
        cout << "Transacción denegada: Saldo insuficiente." << std::endl;
    }
}

// cuando hago paso por referencia hago solo eso del main ya que se actualiza siempre