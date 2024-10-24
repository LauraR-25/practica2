#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct persona{
    char nombre[100];
    int cedula;
    int id;
    int edad;
    float peso;
    float altura;
    char genero;
}p;

int main(){

    fstream FILE("./archivo.bin", ios::in| ios::binary);
    FILE.seekg(sizeof(p)*0, ios::beg);

    cout<< FILE.tellg()<< endl;
    FILE.read(reinterpret_cast<char*>(&p), sizeof(p));
    cout<< "==="<< endl;
     
    cout<< "id: ";
    cin>> p.id;
    cout<< "nombre: ";
    cin>> p.nombre;
    cout<< "cedula: ";
    cin>> p.cedula;
    cout<< "edad: ";
    cin>> p.edad;
    cout<< "peso: ";
    cin>> p.peso;
    cout<< "altura: ";
    cin>> p.altura;
    cout<< "genero: ";
    cin>> p.genero;

    FILE.close();

    return 0;
}