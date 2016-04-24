/*
 * Juego.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_JUEGO_H_
#define MODEL_JUEGO_H_

#include "Serializable.h"

class ConfiguracionJuego;

using namespace std;

class Juego : public Serializable{
private:
	int id;
	int capacidad;
	int duracion;
	int personasJugando;
	int personasEnFila;
	int costo;
	int dineroAcumulado;
public:
	Juego(int id, ConfiguracionJuego conf);
	int getId();
	int getCosto();
	int getDuracion();
	int getCapacidad();
	void setCosto(int costo);
	bool haySuficientePersonasParaJugar();
	void cobrarEntrada();
	void aumentarPersonasJugando();
	void disminuirPersonasJugando();
	void aumentarPersonasEnFila();
	void disminuirPersonasEnFila();
	string toString();
	virtual ~Juego();
};

#endif /* MODEL_JUEGO_H_ */
