#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct persona{
    int id_registro;
    string correo;
    string nombre;
    string cedula;
    int edad;
    float peso;
    float altura;
    char genero;
};

int main() {
    int x;
    cout << "Ingrese el número de personas a registrar: ";
    cin >> x;

    persona personas[x];

    for (int i=0; i<x; i++) {
        cout<< "\nDatos de la persona " << i+1 << endl;
        cout<< "id del registro: ";
        cin>> personas[i].id_registro;
        cout<< "orreo electrónico: ";
        cin>> personas[i].correo;
        cout<< "nombre: ";
        cin>> personas[i].nombre;
        cout<< "edad: ";
        cin>> personas[i].edad;
        cout<< "cédula: ";
        cin>> personas[i].cedula;
        cout<< "peso(kg): ";
        cin>> personas[i].peso;
        cout<< "altura(m): ";
        cin>> personas[i].altura;
        cout<< "género(M/F): ";
        cin>> personas[i].genero;
    }

    fstream archivo("personas.data", ios::binary);
    archivo.write(reinterpret_cast<char*>(personas), sizeof(persona)*x);
    archivo.close();
    cout<< "datos guardados en el archivo personas.data" << endl;

    return 0;
}