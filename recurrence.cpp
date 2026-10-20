#include <iostream>
#include <algorithm>

using namespace std;

void contarHastaN(int n){
    if (n = 0) return;
    
    
    contarHastaN(n - 1);
    cout << n;
}

//factorial




int main(){

    int n = 5;

    return 0;
}
