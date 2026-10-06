#include <iostream>
#include <list>

using namespace std;

struct Client {
    int id;
    string name;
    int age;
};

int main(){
    list<Client> clients2;

    int option;
    
    do {
        cout << "Ingrese una opcion" << endl;
        cin >> option;

        switch (option) {
        case 1:{
            int id;
            string name;
            int age;
            cout << "Ingree un cliente" << endl;
            cin >> id;
            cout << "Ingree una edad" << endl;
            cin >> age;
            cout << "Ingree un nombre" << endl;
            cin >> name;
            


            clients2.push_back({id,name, age});
            break;
        }
    }
    } while (option !=100);
    


    for (const Client& c: clients2){
        cout << c.id << endl;
        cout << c.name << endl;
        }
    return 0;
    }