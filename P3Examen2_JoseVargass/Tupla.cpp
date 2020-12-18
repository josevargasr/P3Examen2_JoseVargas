/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.cpp
 * Author: josevargas
 * 
 * Created on December 18, 2020, 1:17 PM
 */

#include "Tupla.h"

Tupla::Tupla() {
}

Tupla::Tupla(int id, vector<string> atributos){
    this->id = id;
    this->atributos = atributos;
}

Tupla::Tupla(const Tupla& orig) {
}

Tupla::~Tupla() {
}

