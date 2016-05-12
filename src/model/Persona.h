/*
 * Persona.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_PERSONA_H_
#define MODEL_PERSONA_H_

#include "../configuraciones/ConfiguracionPersona.h"
#include "IteradorListaDeJuegos.h"
#include "Juego.h"
#include <iostream>
#include <stdlib.h>
#include "Serializable.h"

using namespace std;

class Persona : public Serializable{
private:
	int presupuestoRestante;
	IteradorListaDeJuegos itListaJuegos;
	void jugar(Juego juego);
	bool puedePagarJuego(Juego);
	bool puedePagarAlgunJuego();
public:
	Persona( int id, ConfiguracionPersona conf, ListaDeJuegos* juegos);
	/*
	 * Entra al parque y cuando termina de jugar sale
	 * */
	void ejecutar();
	/*
	 * Juega a los juegos hasta que no pueda pagar ninguno
	 * */
	void entrarAlParque();
	/*
	 * Recorre los juegos buscando alguno que pueda pagar y juega
	 * en ese
	 * */
	void jugarSiguienteJuego();
	/*
	 * Disminuye el presupuesto restante el precio que cueste el
	 * juego
	 * */
	void pagarEntrada(Juego juego);
	void salirDelParque();
	string toString();
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
