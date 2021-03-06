/*
 * JuegosCompartidos.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: juan
 */

#include "JuegosCompartidos.h"

#define ARCHIVO_MEMORIA "memoriacompartida"
#define ARCHIVO_LOCK_ENTRADA "lockjuegosentrada"
#define ARCHIVO_LOCK_SALIDA "lockjuegossalida"

JuegosCompartidos::JuegosCompartidos(vector<Juego> juegos) : lockEntrada(ARCHIVO_LOCK_ENTRADA), lockSalida(ARCHIVO_LOCK_SALIDA) {
	mem.crear( ARCHIVO_MEMORIA, 'R', juegos.size());
	for (unsigned int index = 0; index < juegos.size(); index++) {
		mem.escribir(juegos[index], index);
	}
}

JuegosCompartidos::~JuegosCompartidos() {
	try {
		mem.liberar(ARCHIVO_MEMORIA);
	} catch (MemoriaCompartidaException& e) {
		Logger::insertError(e.what(), e.getCode());
	}

}

Juego JuegosCompartidos::tomarJuegoSalida(int posicion) {
	this->lockSalida.tomarLock(posicion);
	return this->mem.leer(posicion);
}
void JuegosCompartidos::liberarJuegoSalida(int posicion){
	this->lockSalida.liberarLock(posicion);
}

Juego JuegosCompartidos::tomarJuegoEntrada(int posicion) {
	this->lockEntrada.tomarLock(posicion);
	return this->mem.leer(posicion);

}
void JuegosCompartidos::liberarJuegoEntrada(int posicion){
	this->lockEntrada.liberarLock(posicion);
}

Juego JuegosCompartidos::entrarFila(int posicion){
	Juego juego = this->tomarJuegoEntrada(posicion);
	juego.aumentarPersonasEnFila();
	juego.cobrarEntrada();
	this->mem.escribir(juego, posicion);
	this->liberarJuegoEntrada(posicion);
	return juego;
}

void JuegosCompartidos::salirFila(int posicion, int cantidad){
	Juego juego = this->tomarJuegoEntrada(posicion);
	juego.disminuirPersonasEnFila(cantidad);
	this->mem.escribir(juego, posicion);
	this->liberarJuegoEntrada(posicion);
}

Juego JuegosCompartidos::getJuego(int posicion) {
    return this->mem.leer(posicion);
}

void JuegosCompartidos::salirJuego(int posicion, int cantidad){
	Juego juego = this->tomarJuegoSalida(posicion);
	juego.disminuirPersonasJugando(cantidad);
	this->mem.escribir(juego, posicion);
	this->liberarJuegoSalida(posicion);
}

int JuegosCompartidos::consultarRecaudacion(int cantidadJuegos){
	int dineroAcumulado = 0;
	MemoriaCompartida<Juego> compartido;
	compartido.crear( ARCHIVO_MEMORIA, 'R', cantidadJuegos);
	for (int index = 0; index < cantidadJuegos; index++) {
		dineroAcumulado += compartido.leer(index).getDineroAcumulado();
	}
	return dineroAcumulado;

}

