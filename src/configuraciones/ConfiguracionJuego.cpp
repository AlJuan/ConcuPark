/*
 * ConfiguracionJuego.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionJuego.h"

ConfiguracionJuego::ConfiguracionJuego(int capacidad, int costo) {
	this->capacidad = capacidad;
	this->costo = costo;
}

int ConfiguracionJuego::getCapacidad() {
	return capacidad;
}
int ConfiguracionJuego::getCosto() {
	return costo;
}

ConfiguracionJuego::~ConfiguracionJuego() {
	// TODO Auto-generated destructor stub
}

