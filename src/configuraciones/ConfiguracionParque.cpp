/*
 * ConfiguracionParque.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionParque.h"

ConfiguracionParque::ConfiguracionParque() {
	creadoCorrectamente = true;

}

list<ConfiguracionJuego> ConfiguracionParque::getConfiguracionesJuegos(){
	return configuracionesJuegos;
}

list<ConfiguracionPersona> ConfiguracionParque::getConfiguracionesPersonas(){
	return configuracionesPersonas;
}

void ConfiguracionParque::agregarConfiguracionJuego(ConfiguracionJuego conf) {
	configuracionesJuegos.push_back(conf);
}

void ConfiguracionParque::agregarConfiguracionPersona(ConfiguracionPersona conf) {
	configuracionesPersonas.push_back(conf);
}

bool ConfiguracionParque::isCreadoCorrectamente() {
	return creadoCorrectamente;
}

void ConfiguracionParque::setCreadoCorrectamente(bool creadoCorrectamente) {
	this->creadoCorrectamente = creadoCorrectamente;
}

ConfiguracionParque::~ConfiguracionParque() {
}

