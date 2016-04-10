/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"
#include "../log/Logger.h"

#include <unistd.h>

Persona::Persona(int id, ConfiguracionPersona conf, ListaDeJuegos* juegos): itListaJuegos(juegos) {
	this->id = id;
	this->presupuestoRestante = conf.getSaldoInicial();
}

Persona::~Persona() {
	// TODO Auto-generated destructor stub
}


void Persona::jugarSiguienteJuego(){
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
	Logger::insert(Logger::TYPE_INFO, "Persona " + to_string(id) + " salio del parque");
	exit (0);

}

void Persona::jugar(Juego juego){
	//wait
	Logger::insert(Logger::TYPE_INFO, "Persona " + to_string(id) + " entro al juego " + to_string(juego.getId()));
	this->pagarEntrada(&juego);
	sleep(juego.getDuracion());
	Logger::insert(Logger::TYPE_INFO, "Persona " + to_string(id) + " salio del juego " + to_string(juego.getId()));
	//signal
}

void Persona::init(){
	int id = fork();
	if (id == 0) {
		//Si es el hijo comienza su ejecucion
		this->entrarAlParque();
		this->salirDelParque();
	}
	//Si es el padre no hace nada...
}

void Persona::entrarAlParque(){
	Logger::insert(Logger::TYPE_INFO, "Persona " + to_string(id) + " entro al parque");
	//Si no puede pagar niguno sale
	while (this->puedePagarAlgunJuego()) {
		this->jugarSiguienteJuego();
	}
}

bool Persona::puedePagarJuego(Juego juego){
	return this->presupuestoRestante >= juego.getCosto();
}

void Persona::pagarEntrada(Juego* juego){
	this->presupuestoRestante -= juego->getCosto();
	juego->cobrarEntrada();
}
