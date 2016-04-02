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
	int presupuesto_inicial;
	int presupuesto_restante;
	list<Juego>::iterator it;

public:
	Persona();
	void jugar(Juego* juego);
	virtual ~Persona();
};

#endif /* MODEL_PERSONA_H_ */
