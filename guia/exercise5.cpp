//comparar nota estudiante, referencia

#include <iostream>

struct estudiante {
    std::string nombre;
    float nota;
};

void mayorNota(estudiante& estudiante1, estudiante& estudiante2);
void showStudent(estudiante& estudiante1, estudiante& estudiante2);

int main(){

    estudiante student1 {"Pablito", 10};
    estudiante student2 {"Juanita", 4};

    showStudent(student1, student2);
    mayorNota(student1, student2);

    return 0;
}

void showStudent(estudiante& estudiante1, estudiante& estudiante2){
    std::cout<<"Nombre: " << estudiante1.nombre << std::endl; 
    std::cout<<"Nota: " <<estudiante1.nota << std::endl;
    std::cout<<"Nombre: " << estudiante2.nombre << std::endl; 
    std::cout<<"Nota: " <<estudiante2.nota << std::endl;
}


void mayorNota(estudiante& estudiante1, estudiante& estudiante2){
    if (estudiante1.nota > estudiante2.nota) {
        std::cout  << "El estudiante 1 tiene mayor nota." << std::endl;
    } else {
        std::cout << "El estudiante 2 tiene mayor nota." << std::endl;
    }
}