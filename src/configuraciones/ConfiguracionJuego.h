/*
 * ConfiguracionJuego.h
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#ifndef CONFIGURACIONES_CONFIGURACIONJUEGO_H_
#define CONFIGURACIONES_CONFIGURACIONJUEGO_H_

class ConfiguracionJuego {
private:
	int capacidad;
	int costo;
public:
	ConfiguracionJuego(int capacidad, int costo);
	int getCapacidad();
	int getCosto();
	virtual ~ConfiguracionJuego();
};

#endif /* CONFIGURACIONES_CONFIGURACIONJUEGO_H_ */
