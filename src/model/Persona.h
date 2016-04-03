/*
 * Persona.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_PERSONA_H_
#define MODEL_PERSONA_H_

#include "Juego.h"
#include "ListaDeJuegos.h"
#include "IteradorListaDeJuegos.h"
using namespace std;

class Persona {
private:
	int presupuestoInicial;
	int presupuestoRestante;
	IteradorListaDeJuegos itListaJuegos;
	void jugar(Juego* juego);
public:
	Persona(ListaDeJuegos* juegos);
	void entrarAlParque();
	void jugarSiguienteJuego();
	void pagarEntrada(Juego* juego);
	void salirDelParque();
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
