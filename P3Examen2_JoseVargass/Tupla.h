/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.h
 * Author: josevargas
 *
 * Created on December 18, 2020, 1:17 PM
 */

#ifndef TUPLA_H
#define TUPLA_H
#include <string>
#include <vector>
using namespace std;

class Tupla {
public:
    Tupla();
    Tupla(int, vector<string>);
    Tupla(const Tupla& orig);
    virtual ~Tupla();
private:
    int id;
    vector<string> atributos;
};

#endif /* TUPLA_H */

