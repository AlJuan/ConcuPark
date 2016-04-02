/*
 * Juego.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Juego.h"

Juego::Juego() {
	// TODO Auto-generated constructor stub

}

void Juego::setCosto(int costo) {
	this->costo = costo;
}

int Juego::getCosto(){
	return costo;
}

Juego::~Juego() {
	// TODO Auto-generated destructor stub
}

bool Juego::estaLleno(){
	return this->capacidad == this->personasJugando;
}

void Juego::cobrarEntrada(){
	dineroAcumulado += this->costo;
}

