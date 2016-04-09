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

using namespace std;

class Persona {
private:
	int id;
	int presupuestoInicial;
	int presupuestoRestante;
	IteradorListaDeJuegos itListaJuegos;
	void jugar(Juego juego);
	bool puedeJugarJuego(Juego juego);
	bool puedePagarJuego(Juego);
	bool puedePagarAlgunJuego();
public:
	Persona( int id, ConfiguracionPersona conf, ListaDeJuegos* juegos);
	void entrarAlParque();
	void jugarSiguienteJuego();
	void pagarEntrada(Juego* juego);
	void salirDelParque();
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
