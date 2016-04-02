/*
 * ConfiguracionParque.h
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#ifndef MODEL_CONFIGURACIONES_CONFIGURACIONPARQUE_H_
#define MODEL_CONFIGURACIONES_CONFIGURACIONPARQUE_H_

#include <list>

#include "ConfiguracionJuego.h"
#include "ConfiguracionPersona.h"

using namespace std;

class ConfiguracionParque {
private:
	list<ConfiguracionJuego> configuracionesJuegos;
	list<ConfiguracionPersona> configuracionesPersonas;
public:
	ConfiguracionParque();
	virtual ~ConfiguracionParque();
};

#endif /* MODEL_CONFIGURACIONES_CONFIGURACIONPARQUE_H_ */
