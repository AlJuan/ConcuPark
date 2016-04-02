/*
 * Juego.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_JUEGO_H_
#define MODEL_JUEGO_H_

class Juego {
private:
	int capacidad;
	int personasJugando;
	int costo;
	int dineroAcumulado;
public:
	Juego();
	int getCosto();
	bool estaLleno();
	virtual ~Juego();
};

#endif /* MODEL_JUEGO_H_ */
