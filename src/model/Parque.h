/*
 * Parque.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_PARQUE_H_
#define MODEL_PARQUE_H_

#include <list>
#include "Juego.h"
#include "configuraciones/ConfiguracionParque.h"

using namespace std;

class Parque {
private:
	list<Juego*> juegos;
	void crearPersonas();
	void crearJuegos();
public:
	Parque(ConfiguracionParque configuracionParque);
	int obtenerRecaudacionCaja();
	virtual ~Parque();
};

#endif /* MODEL_PARQUE_H_ */
