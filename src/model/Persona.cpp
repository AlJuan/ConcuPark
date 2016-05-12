/*
 * Persona.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Persona.h"
#include "../log/Logger.h"

#include <unistd.h>
#include <sstream>

Persona::Persona(int id, ConfiguracionPersona conf, ListaDeJuegos* juegos): itListaJuegos(juegos) {
	this->id = id;
	this->presupuestoRestante = conf.getSaldoInicial();
}

Persona::~Persona() {
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
	Logger::insert(Logger::TYPE_INFO, this->toString() + " salio del parque");
}

void Persona::jugar(Juego juego){
	this->itListaJuegos.entrarJuegoActual(this->toString());
	this->pagarEntrada(juego);
	this->itListaJuegos.salirJuegoActual();

}

void Persona::ejecutar(){
	this->entrarAlParque();
	this->salirDelParque();
}

void Persona::entrarAlParque(){
	Logger::insert(Logger::TYPE_INFO, this->toString() + " entro al parque");
	//Si no puede pagar niguno sale
	while (this->puedePagarAlgunJuego()) {
		try {
			this->jugarSiguienteJuego();
		} catch (IPCException& e){//hubo un error asi que termina
			Logger::insertError(e.what(), e.getCode());
		}
	}
}

bool Persona::puedePagarJuego(Juego juego){
	return this->presupuestoRestante >= juego.getCosto();
}

void Persona::pagarEntrada(Juego juego){
	this->presupuestoRestante -= juego.getCosto();
}

string Persona::toString(){
	stringstream stream;
	stream << "Persona "<< id;
	return stream.str();
}
