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
	int duracion;
public:
	ConfiguracionJuego(int capacidad, int costo, int duracion);
	int getCapacidad();
	int getDuracion();
	int getCosto();
	virtual ~ConfiguracionJuego();
};

#endif /* CONFIGURACIONES_CONFIGURACIONJUEGO_H_ */
