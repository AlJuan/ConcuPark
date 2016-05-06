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
	int id = 1;
	for (list<ConfiguracionJuego>::iterator it=configuracionJuegos.begin(); it != configuracionJuegos.end(); ++it) {
		juegosTmp.push_back(Juego(id, *it));
		id ++;
	}
	this->juegos = new ListaDeJuegos(juegosTmp);
}

void Parque::crearPersonas(list<ConfiguracionPersona> configuracionPersonas) {
	int id = 1;
	for (list<ConfiguracionPersona>::iterator it=configuracionPersonas.begin(); it != configuracionPersonas.end(); ++it) {
		Persona* persona = new Persona(id, *it, this->juegos);
		personas.push_back(persona);
		id ++;
	}
}

int Parque::abrirParque(){
	// Cada persona entra al parque en un proceso diferente
	for (list<Persona* >::iterator it = personas.begin(); it != personas.end(); ++it){
		Persona* p = (*it);
		int id = fork();
		if (id == 0) {
			//Si es el hijo comienza su ejecucion
			p->ejecutar();
			return id;
		}
		//Si es el padre no hace nada...
	}
	return getpid();
}

int Parque::obtenerRecaudacionCaja() {
	int recaudacion = 0;
	for (int i = 0; i < juegos->getCantidad(); i++) {
		Juego j = juegos->getJuego(i);
		recaudacion += j.getDineroAcumulado();
	}
	return recaudacion;
}

Parque::~Parque() {
	delete juegos;
	for (list<Persona* >::iterator it = personas.begin(); it != personas.end(); ++it){
		Persona* p = (*it);
		delete p;
	}
}

