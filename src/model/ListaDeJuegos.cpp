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
	semaforoFila(ARCHIVO, 0, juegos.size()), semaforoJuego(ARCHIVO_JUEGO, 1, juegos.size()),
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

void ListaDeJuegos::entrarJuego(int posicion, string persona){
	Juego juego = this->juegosCompartidos.entrarFila(posicion);
	this->esperarAQueSeLlene(juego, posicion, persona);
}

void ListaDeJuegos::esperarAQueSeLlene(Juego juego, int posicion, string persona){
	if (juego.haySuficientePersonasParaJugar()){
		this->semaforoJuego.wait(posicion);
		for (int i = 0; i < juego.getCapacidad(); i++)
			this->semaforoFila.signal(posicion);
	}
	Logger::insert(Logger::TYPE_INFO, persona + " esta en la cola del " + juego.toString());
	this->semaforoFila.wait(posicion);
	this->juegosCompartidos.salirFila(posicion);
	Logger::insert(Logger::TYPE_INFO, persona + " entro al " + juego.toString());
	sleep(juego.getDuracion());
	if (juego.haySuficientePersonasParaJugar())
		this->semaforoJuego.signal(posicion);


	//this->semaforoJuego.signal(posicion);
	/**if (juego.haySuficientePersonasParaJugar()){
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
	}**/
}

void ListaDeJuegos::salirJuego(int posicion){
	this->juegosCompartidos.salirJuego(posicion);
}
