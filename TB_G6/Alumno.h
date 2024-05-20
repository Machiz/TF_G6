#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Alumno 
{
private:
    string nombre;
    int edad;
    int a�oEscolar;
    string seccion;

public:
    Alumno(const string& nombre, int edad, int a�oEscolar, const string& seccion)
        : nombre(nombre), edad(edad), a�oEscolar(a�oEscolar), seccion(seccion) {}
    Alumno() {}

    //informaci�n del alumno
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    int getA�oEscolar() const { return a�oEscolar; }
    string getSeccion() const { return seccion; }

    
    void OrdenMerito() 
    {
        ofstream archivo("datos_alumno.csv", ios::app); 
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escribir." << endl;
            return;
        }     
        if (archivo.tellp() == 0) 
        {
            archivo << "Nombre,Orden de M�rito" << endl; 
        }       
        string nombreAlumno;
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore(); 
        getline(cin, nombreAlumno);

        int ordenMerito = rand() % 40 + 1; 
        // Guardar en el CSV
        archivo << nombreAlumno << "," << ordenMerito << endl;
        archivo.close(); 
        cout << "Alumno: " << nombreAlumno << " - Orden de m�rito: " << ordenMerito << endl; 
    }
    // Funci�n para mostrar datos del CSV
    void mostrarCSV(const string& nombreArchivo)
    {
        ifstream archivo(nombreArchivo);

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
};
#endif ALUMNO_H
