/*
 * ConfiguracionParque.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionParque.h"

ConfiguracionParque::ConfiguracionParque() {

}

list<ConfiguracionJuego*> ConfiguracionParque::getConfiguracionesJuegos(){
	return configuracionesJuegos;
}

list<ConfiguracionPersona*> ConfiguracionParque::getConfiguracionesPersonas(){
	return configuracionesPersonas;
}

void ConfiguracionParque::agregarConfiguracionJuego(int capacidad, int costo) {
	configuracionesJuegos.push_back(new ConfiguracionJuego(capacidad, costo));
}

void ConfiguracionParque::agregarConfiguracionPersona(int presupuesto) {
	configuracionesPersonas.push_back(new ConfiguracionPersona(presupuesto));
}

ConfiguracionParque::~ConfiguracionParque() {
	// TODO Auto-generated destructor stub
}

