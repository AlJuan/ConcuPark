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
#define ARCHIVO_JUEGO "src/concuPark.conf"

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) : juegosCompartidos(juegos),
	semaforoFila(ARCHIVO, 0, juegos.size()), semaforoJuego(ARCHIVO_JUEGO, 0, juegos.size()),
	lockJuego(ARCHIVO_JUEGO), cantidad(juegos.size()){
}

ListaDeJuegos::~ListaDeJuegos() {

}

Juego ListaDeJuegos::getJuego(int posicion) {
    return this->juegosCompartidos.getJuego(posicion);
}

int ListaDeJuegos::getCantidad(){
	return this->cantidad;
}

void ListaDeJuegos::entrarJuego(int posicion){
	Juego juego = this->juegosCompartidos.entrarJuego(posicion);
	this->esperarAQueSeLlene(juego, posicion);
}

void ListaDeJuegos::esperarAQueSeLlene(Juego juego, int posicion){
	if (juego.haySuficientePersonasParaJugar()){
		//Signal
		this->semaforoFila.signal(posicion);//liberar tantos procesos de la fila como capacidad tenga el juego
		this->lockJuego.tomarLock(posicion);
		sleep(juego.getDuracion());
		this->lockJuego.liberarLock(posicion);
		this->semaforoJuego.signal(posicion);//liberar tantos procesos del juego como capacidad tenga el juego

	}else{
		//Wait
		this->semaforoFila.wait(posicion);
		// ACA ENTRO AL JUEGO
		this->semaforoJuego.wait(posicion);
	}
}

void ListaDeJuegos::salirJuego(int posicion){
	this->juegosCompartidos.salirJuego(posicion);
}
