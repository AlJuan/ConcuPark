/*
 * Juego.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_JUEGO_H_
#define MODEL_JUEGO_H_

#include "Persona.h"

class Juego {
private:
	int capacidad;
	int personasJugando;
	int costo;
	int dineroAcumulado;
public:
	Juego();
	int getCosto();
	void setCosto(int costo);
	bool estaLleno();
	void cobrarEntrada(Persona* persona);
	virtual ~Juego();
};

#endif /* MODEL_JUEGO_H_ */
