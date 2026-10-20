//Suma de 1 a n
//n = 5 5 + 4 +3 +2 +1


#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int n){
    //caso base
    if(n==0) return 0;

    //caso recursivo
    return n + factorial(n - 1);    
}

int main() {
    int n = 5;
    cout<<factorial(5);

    return 0;
}