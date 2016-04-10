/*
 * Juego.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Juego.h"

#include "../configuraciones/ConfiguracionJuego.h"
#include <sstream>

Juego::Juego(int id, ConfiguracionJuego conf) {
	this->id = id;
	this->capacidad = conf.getCapacidad();
	this->duracion = conf.getDuracion();
	this->personasJugando = 0;
	this->dineroAcumulado = 0;
	this->costo = conf.getCosto();
}

void Juego::setCosto(int costo) {
	this->costo = costo;
}

int Juego::getCosto(){
	return costo;
}

int Juego::getId(){
	return id;
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

int Juego::getDuracion(){
	return duracion;
}

void Juego::aumentarPersonasJugando(){
	this->personasJugando++;
}
void Juego::disminuirPersonasJugando(){
	this->personasJugando--;
}

string Juego::toString(){
	stringstream stream;
	stream << "Juego "<< id;
	return stream.str();
}

