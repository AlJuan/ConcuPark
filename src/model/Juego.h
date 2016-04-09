/*
 * Juego.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_JUEGO_H_
#define MODEL_JUEGO_H_

class ConfiguracionJuego;

using namespace std;

class Juego {
private:
	int id;
	int capacidad;
	int personasJugando;
	int costo;
	int dineroAcumulado;
public:
	Juego(int id, ConfiguracionJuego conf);
	int getCosto();
	void setCosto(int costo);
	bool estaLleno();
	void cobrarEntrada();
	virtual ~Juego();
};

#endif /* MODEL_JUEGO_H_ */
