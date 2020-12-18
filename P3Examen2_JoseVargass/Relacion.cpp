/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.cpp
 * Author: josevargas
 * 
 * Created on December 18, 2020, 1:15 PM
 */

#include "Relacion.h"

Relacion::Relacion() {
}

Relacion::Relacion(string nombre, vector<string> encabezados) {
    this->nombre = nombre;
    this->encabezados = encabezados;
    guardarRelacion();
}

Relacion::Relacion(const Relacion& orig) {
}

Relacion::~Relacion() {
}

void Relacion::guardarRelacion(){
    ofstream output;
    output.open("relaciones.txt", ofstream::out | ofstream::app);
    output << nombre << endl;
    int size = encabezados.size();
    for(int i = 0; i < size; i++){
        output << encabezados[i] << ";";
    }
    output << endl;
    output << "---------------------------------------" << endl;
    output.close();
}

