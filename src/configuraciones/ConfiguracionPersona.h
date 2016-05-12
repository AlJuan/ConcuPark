/*
 * ConfiguracionPersona.h
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#ifndef CONFIGURACIONES_CONFIGURACIONPERSONA_H_
#define CONFIGURACIONES_CONFIGURACIONPERSONA_H_


/*
 * Configuracion utilizada para crear una persona.
 * */
class ConfiguracionPersona {
private:
	int saldoInicial;
public:
	ConfiguracionPersona(int presupuesto);
	int getSaldoInicial();
	virtual ~ConfiguracionPersona();
};

#endif /* CONFIGURACIONES_CONFIGURACIONPERSONA_H_ */
