/*
 * Parque.h
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#ifndef MODEL_PARQUE_H_
#define MODEL_PARQUE_H_

#include <list>

#include "../configuraciones/ConfiguracionJuego.h"
#include "../configuraciones/ConfiguracionParque.h"
#include "Juego.h"
#include "Persona.h"
#include "ListaDeJuegos.h"

using namespace std;

class Parque {
private:
	ListaDeJuegos* juegos;
	list<Persona*> personas;
	void crearPersonas();
	void crearJuegos(list<ConfiguracionJuego> configuracionJuegos);
	void crearPersonas(list<ConfiguracionPersona> configuracionPersona);

public:
	Parque(ConfiguracionParque configuracionParque);
	int obtenerRecaudacionCaja();
	virtual ~Parque();
};

#endif /* MODEL_PARQUE_H_ */
