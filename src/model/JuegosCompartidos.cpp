/*
 * JuegosCompartidos.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: juan
 */

#include "JuegosCompartidos.h"

#define ARCHIVO "src/concuPark.conf"

JuegosCompartidos::JuegosCompartidos(vector<Juego> juegos) : lock(ARCHIVO) {
	int estadoMemoria = mem.crear( ARCHIVO, 'R', juegos.size());
	if (estadoMemoria == SHM_OK) {
		Logger::insert(Logger::TYPE_DEBUG,
				"Memoria compartida creada correctamente");
	} else {
		Logger::insert(Logger::TYPE_ERROR, "Error al crear memoria compartida");
	}
	for (unsigned int index = 0; index < juegos.size(); index++) {
		mem.escribir(juegos[index], index);
	}

}

JuegosCompartidos::~JuegosCompartidos() {
}

Juego JuegosCompartidos::tomarJuego(int posicion) {
	this->lock.tomarLock(posicion);
	return this->mem.leer(posicion);

}
void JuegosCompartidos::liberarJuego(int posicion){
	this->lock.liberarLock(posicion);
}

Juego JuegosCompartidos::entrarFila(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.aumentarPersonasEnFila();
	juego.cobrarEntrada();
	this->mem.escribir(juego, posicion);
	this->liberarJuego(posicion);
	return juego;
}

void JuegosCompartidos::salirFila(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasEnFila();
	this->mem.escribir(juego, posicion);
	this->liberarJuego(posicion);
}

Juego JuegosCompartidos::getJuego(int posicion) {
    return this->mem.leer(posicion);
}

void JuegosCompartidos::salirJuego(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasJugando();
	this->liberarJuego(posicion);
}
