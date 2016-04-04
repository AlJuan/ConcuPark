/*
 * ConfiguracionParque.h
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#ifndef CONFIGURACIONES_CONFIGURACIONPARQUE_H_
#define CONFIGURACIONES_CONFIGURACIONPARQUE_H_

#include <list>

#include "ConfiguracionJuego.h"
#include "ConfiguracionPersona.h"

using namespace std;

class ConfiguracionParque {
private:
	list<ConfiguracionJuego*> configuracionesJuegos;
	list<ConfiguracionPersona*> configuracionesPersonas;
public:
	ConfiguracionParque();
	list<ConfiguracionJuego*> getConfiguracionesJuegos();
	list<ConfiguracionPersona*> getConfiguracionesPersonas();
	void agregarConfiguracionJuego(int capacidad, int costo);
	void agregarConfiguracionPersona(int presupuesto);
	virtual ~ConfiguracionParque();
};

#endif /* CONFIGURACIONES_CONFIGURACIONPARQUE_H_ */
