/*
 * ConfiguracionJuego.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionJuego.h"

ConfiguracionJuego::ConfiguracionJuego(int capacidad, int costo, int duracion) {
	this->capacidad = capacidad;
	this->costo = costo;
	this->duracion = duracion;
}

int ConfiguracionJuego::getCapacidad() {
	return capacidad;
}
int ConfiguracionJuego::getCosto() {
	return costo;
}

int ConfiguracionJuego::getDuracion(){
	return duracion;
}

ConfiguracionJuego::~ConfiguracionJuego() {
	// TODO Auto-generated destructor stub
}

