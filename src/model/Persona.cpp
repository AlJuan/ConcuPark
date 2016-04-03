/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"

Persona::Persona(ListaDeJuegos* juegos): itListaJuegos(juegos) {
	// TODO Auto-generated constructor stub

}

Persona::~Persona() {
	// TODO Auto-generated destructor stub
}

//void Persona::jugarSiguienteJuego(){
//	while () {
//		Juego* juegoActual = this->getSiguienteJuego();
//	}
//
//}

void Persona::pagarEntrada(Juego* juego){
	this->presupuestoRestante -= juego->getCosto();
	juego->cobrarEntrada();
}
