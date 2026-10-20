#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int array[] = {5,2,9,1,5,6,3};
    int n = sizeof(array)/sizeof(array[0]);

    sort(array, array+n);

    int inicio = 0;
    int fin = n - 1;
    
    int search = 3;

    while (inicio <= fin){
        int mitad = (inicio + fin) / 2;

        if (array[mitad]=search){
            cout << "Elemento es " << mitad << endl;
            break;
        } else if (array[mitad] < search){
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }
    


    return 0;
}