/*
 * IteradorListaDeJuegos.cpp
 *
 *  Created on: Apr 3, 2016
 *      Author: juan
 */

#include "IteradorListaDeJuegos.h"

IteradorListaDeJuegos::IteradorListaDeJuegos(ListaDeJuegos* ptr): lista(ptr) {
	this->posicion = 0;
}

IteradorListaDeJuegos::~IteradorListaDeJuegos() {
	// TODO Auto-generated destructor stub
}

Juego IteradorListaDeJuegos::getSiguienteJuego(){
	if (this->posicion == this->lista->getCantidad() - 1){
		this->posicion = 0;
	}
	return this->lista->getJuego(this->posicion++);
}

