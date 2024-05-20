#ifndef PADRE_H
#define PADRE_H
#include <fstream>
#include <iostream>
#include <string>
#include "Alumno.h" // Aseg�rate de que la clase Alumno est� definida correctamente
#include "ListaEnlazada.h" // Aseg�rate de que ListaEnlazada est� implementada
using namespace std;

class Padre
{
private:
    string nombre; 
    ListaEnlazada<Alumno> alumnos; 

public:
    Padre() {}
    Padre(const string& nombre) : nombre(nombre) {} 

    // Getters
    string getNombre() const { return nombre; }

    void registrarAlumno() 
    {
        ofstream archivo("alumnos.csv", ios::app);

        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }
        if (archivo.tellp() == 0) 
        {
            archivo << "Nombre,Edad,A�oEscolar,Secci�n" << endl;
        }
      
        string nombreAlumno;
        int edadAlumno;
        int a�oAlumno;
        string seccionAlumno;
        cout << "Registrar Alumno: " << endl;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore(); 
        getline(cin, nombreAlumno); 

        cout << "Ingrese la edad del alumno: ";
        cin >> edadAlumno;

        cout << "Ingrese el a�o escolar del alumno: ";
        cin >> a�oAlumno; 

        cin.ignore();

        cout << "Ingrese la secci�n del alumno(A/B): ";
        getline(cin, seccionAlumno); 

        archivo << nombreAlumno << ","
            << edadAlumno << ","
            << a�oAlumno << ","
            << seccionAlumno << endl;

        archivo.close(); 

        int opcion;
        cout << "Qu� desea hacer ahora?" << endl;
        cout << "1. Imprimir datos guardados\n2. Regresar al men� principal" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Imprimir los datos del archivo CSV
        {
            ifstream archivo("alumnos.csv");

            if (!archivo.is_open())
            {
                cerr << "Error: No se pudo abrir el archivo para leer." << endl;
                return;
            }

            string linea;
            while (getline(archivo, linea))
            {
                cout << linea << endl; 
            }

            archivo.close(); 
        }
        break;

        case 2:
            cout << "Regresando al men� principal..." << endl;
            break;

        default:
            cout << "Opci�n no v�lida." << endl;
            break;
        }
    }
};
#endif PADRE_H