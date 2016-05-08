/*
 * ConfiguracionPersona.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ConfiguracionPersona.h"

ConfiguracionPersona::ConfiguracionPersona(int presupuesto) {
	this->saldoInicial = presupuesto;

}

int ConfiguracionPersona::getSaldoInicial() {
	return saldoInicial;
}

ConfiguracionPersona::~ConfiguracionPersona() {
}

