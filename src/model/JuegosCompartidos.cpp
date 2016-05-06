/*
 * JuegosCompartidos.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: juan
 */

#include "JuegosCompartidos.h"

#define ARCHIVO_MEMORIA "memoriacompartida"
#define ARCHIVO_LOCK "concuPark.conf"

JuegosCompartidos::JuegosCompartidos(vector<Juego> juegos) : lock(ARCHIVO_LOCK) {
	int estadoMemoria = mem.crear( ARCHIVO_MEMORIA, 'R', juegos.size());
	if (estadoMemoria == SHM_OK) {
		Logger::insert(Logger::TYPE_DEBUG, "Memoria compartida creada correctamente");
	} else {
		Logger::insert(Logger::TYPE_ERROR, "Error al crear memoria compartida");
	}
	for (unsigned int index = 0; index < juegos.size(); index++) {
		mem.escribir(juegos[index], index);
	}

}

JuegosCompartidos::~JuegosCompartidos() {
	mem.liberar(ARCHIVO_MEMORIA);
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

void JuegosCompartidos::salirFila(int posicion, int cantidad){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasEnFila(cantidad);
	this->mem.escribir(juego, posicion);
	this->liberarJuego(posicion);
}

Juego JuegosCompartidos::getJuego(int posicion) {
    return this->mem.leer(posicion);
}

void JuegosCompartidos::salirJuego(int posicion, int cantidad){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasJugando(cantidad);
	this->liberarJuego(posicion);
}

