/*
 * ListaDeJuegos.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include <iostream>

#include "ListaDeJuegos.h"
#include "../log/Logger.h"

#define ARCHIVO "src/concuPark.conf"

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) : lock(ARCHIVO),
	sem(ARCHIVO, 0, juegos.size()), cantidad(juegos.size()){

	int estadoMemoria = mem.crear ( ARCHIVO,'R', juegos.size());
	if ( estadoMemoria == SHM_OK ) {
		Logger::insert(Logger::TYPE_DEBUG, "Memoria compartida creada correctamente");
	} else {
		Logger::insert(Logger::TYPE_ERROR, "Error al crear memoria compartida");
	}
	for (unsigned int index = 0; index < juegos.size(); index++){
		mem.escribir(juegos[index], index);
	}
}

ListaDeJuegos::~ListaDeJuegos() {

}

Juego ListaDeJuegos::getJuego(int posicion) {
    return this->mem.leer(posicion);
}

int ListaDeJuegos::getCantidad(){
	return this->cantidad;
}

void ListaDeJuegos::setJuego(Juego juego, int posicion) {
	if (posicion >= cantidad) return;
	this->mem.escribir(juego, posicion);
}

void ListaDeJuegos::entrarJuego(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.aumentarPersonasJugando();
	juego.cobrarEntrada();
	this->mem.escribir(juego, posicion);
	this->liberarJuego(posicion);
	this->esperarAQueSeLlene(juego, posicion);
}

void ListaDeJuegos::esperarAQueSeLlene(Juego juego, int posicion){
	if (juego.estaLleno())
		//Signal
		this->sem.v(posicion);
	else
		//Wait
		this->sem.p(posicion);
}

void ListaDeJuegos::salirJuego(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasJugando();
	this->liberarJuego(posicion);
}

Juego ListaDeJuegos::tomarJuego(int posicion) {
	this->lock.tomarLock(posicion);
	return this->mem.leer(posicion);

}
void ListaDeJuegos::liberarJuego(int posicion){
	this->lock.liberarLock(posicion);

}
