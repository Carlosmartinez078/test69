#include <iostream>
#include <list>

using namespace std;

int main(){

    list <int> numbers; 

    numbers.push_front(50);
    numbers.push_front(70);

    for (int i : numbers){
        cout << i 
    }
    
}