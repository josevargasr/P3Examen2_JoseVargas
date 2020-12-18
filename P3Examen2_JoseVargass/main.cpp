/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josevargas
 *
 * Created on December 18, 2020, 1:10 PM
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include "Relacion.h"
#include "Tupla.h"

void abrirRelaciones(string);
string abrirRelacion(int);
void guardarTupla(string, vector<string>, int);
string agarrarAtributos(string);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    vector<string> encabezados;
    vector<string> atributos_t;
    int valid = true;
    while (valid) {
        int option = 0;
        cout << "      MENU" << endl
                << "1. Crear Relacion" << endl
                << "2. Ver Relaciones" << endl
                << "3. Insertar tupla" << endl
                << "4. Salir" << endl
                << "Ingrese una opcion: ";
        cin >> option;
        switch (option) {
            case 1:
            {
                string crear_encabezado = "s";
                string nombre, encabezado;
                cout << "Ingrese el nombre de la relacion: ";
                cin >> nombre;
                encabezados.push_back("ID");
                while (crear_encabezado == "S" || crear_encabezado == "s") {
                    cout << "Ingrese un encabezado: ";
                    cin >> encabezado;
                    cout << "¿Desea crear otro encabezado?(S/N): ";
                    cin >> crear_encabezado;
                    encabezados.push_back(encabezado);
                }
                Relacion *r = new Relacion(nombre, encabezados);
                cout << "La relación fue creada con éxito" << endl;
                cout << endl;
                break;
            }
            case 2:
            {
                string nom_relacion = "";
                int posicion_rel;
                abrirRelaciones("relaciones.txt");
                cout << "Ingrese la posicion de la relacion que desea ver(Empezando en 0): ";
                cin >> posicion_rel;
                nom_relacion = abrirRelacion(posicion_rel);
                nom_relacion += ".txt";
                abrirRelaciones(nom_relacion);
                cout << endl;
                break;
            }
            case 3:
            {
                int id;
                string nom_relacion = "", atributos;
                int posicion_rel;
                abrirRelaciones("relaciones.txt");
                cout << "Ingrese la posicion de la relacion que desea agregar(Empezando en 0): ";
                cin >> posicion_rel;
                nom_relacion = abrirRelacion(posicion_rel);
                atributos = agarrarAtributos(nom_relacion);
                nom_relacion += ".txt";
                id = rand() % 8999 + 1000;
                stringstream stream(atributos);
                string atri;
                while (stream.good()) {
                    string substr;
                    getline(stream, substr, ';');
                    if (substr == "" || substr == "ID") {

                    } else {
                        cout << substr << ": ";
                        cin >> atri;
                        atributos_t.push_back(atri);
                    }
                }
                Tupla *tupla = new Tupla(id, atributos_t);
                guardarTupla(nom_relacion, atributos_t, id);
                cout << "La tupla se guardó con éxito" << endl;
                cout << endl;
                break;
            }
            case 4:
            {
                valid = false;
                cout << endl;
                break;
            }
        }
    }
    return 0;
}

void abrirRelaciones(string filename) {
    ifstream file(filename);
    string linea;
    if (file.is_open()) {
        while (getline(file, linea)) {
            cout << linea << endl;
        }
        file.close();
    }
}

//solo obtiene el nombre de la relacion

string abrirRelacion(int pos) {
    int cont_lineas = 0;
    string nom_relacion;
    ifstream file("relaciones.txt");
    string linea;
    if (file.is_open()) {
        if (pos == 0) {
            file >> nom_relacion;
        } else {
            while (getline(file, linea)) {
                if (linea == "---------------------------------------") {
                    cont_lineas++;
                    if (cont_lineas == pos) {
                        file >> nom_relacion;
                    }
                }
            }
        }
        file.close();
    }
    return nom_relacion;
}

void guardarTupla(string filename, vector<string> atributos_t, int id) {
    ofstream output;
    output.open(filename, ofstream::out | ofstream::app);
    output << id << "    ";
    for (int i = 0; i < atributos_t.size(); i++) {
        output << atributos_t[i] << "    ";
    }
    output << endl;
    output << "---------------------------------------" << endl;
    output.close();
}

string agarrarAtributos(string nombre) {
    string atributos;
    ifstream file("relaciones.txt");
    string linea;
    if (file.is_open()) {
        while (getline(file, linea)) {
            if (linea == nombre) {
                file >> atributos;
            }
        }
        file.close();
    }
    return atributos;
}
