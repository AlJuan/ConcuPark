/*
 * IteradorListaDeJuegos.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: juan
 */

#include "IteradorListaDeJuegos.h"

IteradorListaDeJuegos::IteradorListaDeJuegos(ListaDeJuegos* ptr): lista(ptr) {
	this->posicion = -1;
}

IteradorListaDeJuegos::~IteradorListaDeJuegos() {
	// TODO Auto-generated destructor stub
}

bool IteradorListaDeJuegos::esElUltimoJuego() {
	return (this->posicion == this->lista->getCantidad() - 1);
}

Juego IteradorListaDeJuegos::getSiguienteJuego(){
	this->posicion++;
	if (this->posicion == this->lista->getCantidad()){
		this->posicion = 0;
	}
	return this->lista->getJuego(this->posicion);
}

ListaDeJuegos* IteradorListaDeJuegos::getLista(){
	return this->lista;
}

void IteradorListaDeJuegos::entrarJuegoActual(string persona){
	this->lista->entrarJuego(this->posicion, persona);
}
void IteradorListaDeJuegos::salirJuegoActual(){
	this->lista->salirJuego(this->posicion);
}
