/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"

Persona::Persona() {
	// TODO Auto-generated constructor stub

}

Persona::~Persona() {
	// TODO Auto-generated destructor stub
}

void Persona::pagarEntrada(int costo){
	this->presupuestoRestante -= costo;
}
