/*
 * ConfiguracionParque.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionParque.h"

ConfiguracionParque::ConfiguracionParque() {

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

ConfiguracionParque::~ConfiguracionParque() {
}

