/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"

Persona::Persona(ListaDeJuegos* juegos): itListaJuegos(juegos) {

}

Persona::~Persona() {
	// TODO Auto-generated destructor stub
}


void Persona::jugarSiguienteJuego(){
	//Si no puede jugar niguno se va del parque
	if (!this->puedePagarAlgunJuego()){
		this->salirDelParque();
		return;
	}
	//Si puede avanza hasta que encuentra uno que puede jugar y juega
	Juego juegoActual = this->itListaJuegos.getSiguienteJuego();
	while (!this->puedeJugarJuego(juegoActual)) {
		juegoActual = this->itListaJuegos.getSiguienteJuego();
	}
	this->jugar(juegoActual);
}

bool Persona::puedePagarAlgunJuego(){
	IteradorListaDeJuegos it (this->itListaJuegos.getLista());
	while (!it.esElUltimoJuego()) {
		if (this->puedePagarJuego(it.getSiguienteJuego())) return true;
	}
	return false;
}

void Persona::salirDelParque(){
    //TODO
}

void Persona::jugar(Juego juego){
    //TODO
}

bool Persona::puedeJugarJuego(Juego juego){
	return !juego.estaLleno() && this->puedePagarJuego(juego);
}

bool Persona::puedePagarJuego(Juego juego){
	return this->presupuestoRestante >= juego.getCosto();
}

void Persona::pagarEntrada(Juego* juego){
	this->presupuestoRestante -= juego->getCosto();
	juego->cobrarEntrada();
}
