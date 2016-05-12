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

/*
 * Configuracion utilizada para crear un parque.
 * */
class ConfiguracionParque {
private:
	list<ConfiguracionJuego> configuracionesJuegos;
	list<ConfiguracionPersona> configuracionesPersonas;
	bool creadoCorrectamente;
public:
	ConfiguracionParque();
	list<ConfiguracionJuego> getConfiguracionesJuegos();
	list<ConfiguracionPersona> getConfiguracionesPersonas();
	bool isCreadoCorrectamente();
	void setCreadoCorrectamente(bool creadoCorrectamente);
	void agregarConfiguracionJuego(ConfiguracionJuego conf);
	void agregarConfiguracionPersona(ConfiguracionPersona conf);
	virtual ~ConfiguracionParque();

};

#endif /* CONFIGURACIONES_CONFIGURACIONPARQUE_H_ */
