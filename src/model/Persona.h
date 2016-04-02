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

using namespace std;

class Persona {
private:
	int presupuestoInicial;
	int presupuestoRestante;
	ListaDeJuegos* juegos;
	void jugar(Juego* juego);
	void getSiguienteJuego();
public:
	Persona();
	void entrarAlParque();
	void jugarSiguienteJuego();
	void pagarEntrada(Juego* juego, int costo);
	void salirDelParque();
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
