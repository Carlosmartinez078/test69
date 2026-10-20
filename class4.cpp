#include <iostream>

using namespace std;

bool isEven(int number);

bool isOdd(int number);

int main(){

    int number = 4;

    if (isEven(number)){
        cout << "El numero es par" << endl;
    } else {
        cout << "El numero no es par" << endl;
    }
    

    return 0;
}

bool isEven(int number){
    if (number ==0){
        return true;
    }
    
    return isOdd(number-1);
}

bool isOdd(int number){
    if (number ==0){
        return false;
    }
    
    return isEven(number-1);
}