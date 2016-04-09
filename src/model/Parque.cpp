/*
 * Parque.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Parque.h"

Parque::Parque(ConfiguracionParque configuracionParque) {
	crearJuegos(configuracionParque.getConfiguracionesJuegos());
	crearPersonas(configuracionParque.getConfiguracionesPersonas());


}

void Parque::crearJuegos(list<ConfiguracionJuego> configuracionJuegos) {
	vector<Juego> juegosTmp;
	for (list<ConfiguracionJuego>::iterator it=configuracionJuegos.begin(); it != configuracionJuegos.end(); ++it) {
		juegosTmp.push_back(Juego(*it));
	}
	//crear lista de juegos
}

void Parque::crearPersonas(list<ConfiguracionPersona> configuracionPersonas) {
	for (list<ConfiguracionPersona>::iterator it=configuracionPersonas.begin(); it != configuracionPersonas.end(); ++it) {
		Persona* persona = new Persona(*it, this->juegos);
		personas.push_back(persona);
	}

}

Parque::~Parque() {
	// TODO Auto-generated destructor stub
}

