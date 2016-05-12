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
	int getCantidadPersonasEnFila();
	int getDineroAcumulado();
	int getCantidadListosParaJugar();
	void setCosto(int costo);
	/*
	 * Indica si la cantidad de persona esperando entrar al juego
	 * supera a la cantidad necesaria para comenzar
	 * */
	bool haySuficientesPersonasParaJugar();
	/*
	 * SOLO Aumenta la recaudacion del juego
	 * */
	void cobrarEntrada();
	void aumentarPersonasJugando();
	void disminuirPersonasJugando(int cantidad);
	void aumentarPersonasEnFila();
	void disminuirPersonasEnFila(int cantidad);
	string toString();
	virtual ~Juego();
};

#endif /* MODEL_JUEGO_H_ */
