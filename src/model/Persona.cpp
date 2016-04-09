/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"
#include <unistd.h>

Persona::Persona(int id, ConfiguracionPersona conf, ListaDeJuegos* juegos): itListaJuegos(juegos) {
	this->id = id;
	this->presupuestoInicial = conf.getSaldoInicial();
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
	while (!this->puedePagarJuego(juegoActual)) {
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
	//wait
	//sleep
	//signal
}

void Persona::init(){
	int id = fork();
	if (id == 0) {
		//Si es el hijo comienza su ejecucion
		this->entrarAlParque();
	}
	//Si es el padre no hace nada...
}

void Persona::entrarAlParque(){

}

bool Persona::puedePagarJuego(Juego juego){
	return this->presupuestoRestante >= juego.getCosto();
}

void Persona::pagarEntrada(Juego* juego){
	this->presupuestoRestante -= juego->getCosto();
	juego->cobrarEntrada();
}
