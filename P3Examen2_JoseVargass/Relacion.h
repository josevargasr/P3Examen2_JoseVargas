/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.h
 * Author: josevargas
 *
 * Created on December 18, 2020, 1:15 PM
 */

#ifndef RELACION_H
#define RELACION_H
#include "Tupla.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Relacion {
public:
    Relacion();
    Relacion(string, vector<string>);
    Relacion(const Relacion& orig);
    void guardarRelacion();
    virtual ~Relacion();
private:
    string nombre;
    vector<string> encabezados;
    vector<Tupla> tuplas;
};

#endif /* RELACION_H */

