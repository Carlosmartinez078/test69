#include <iostream>

//son punteros que entran al valor de la variable x y y
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x =7 , y =4;
    std::cout << "Antes del cambio" << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

    swap (&x, &y);

    std::cout<< "Despues del cambio" << std::endl;
    std::cout<< "X:" << x << std::endl;
    std::cout<< "Y:" << y << std::endl;

    return 0;
}