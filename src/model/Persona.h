/*
 * Persona.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_PERSONA_H_
#define MODEL_PERSONA_H_

#include <iterator>
#include <list>
#include "Juego.h"

using namespace std;

class Persona {
private:
	int presupuestoInicial;
	int presupuestoRestante;
	list<Juego>::iterator it;
	void jugar(Juego* juego);
public:
	Persona();
	void entrarAlParque();
	void jugarSiguienteJuego();
	void pagarEntrada(int costo);
	void salirDelParque();
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
