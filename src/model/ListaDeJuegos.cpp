/*
 * ListaDeJuegos.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include <iostream>

#include "ListaDeJuegos.h"
#include "../log/Logger.h"

#define ARCHIVO "src/Concupark.cpp"
#define ARCHIVO_JUEGO "src/concuPark.conf"

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) : juegosCompartidos(juegos),
	semaforoFila(ARCHIVO, 0, juegos.size()), semaforoJuego(ARCHIVO_JUEGO, 0, juegos.size()),
	lockJuego(ARCHIVO_JUEGO), cantidad(juegos.size()){
}

ListaDeJuegos::~ListaDeJuegos() {
	semaforoFila.eliminar();
	semaforoJuego.eliminar();

}

Juego ListaDeJuegos::getJuego(int posicion) {
    return this->juegosCompartidos.getJuego(posicion);
}

int ListaDeJuegos::getCantidad(){
	return this->cantidad;
}

void ListaDeJuegos::entrarJuego(int posicion, string persona){
	Juego juego = this->juegosCompartidos.entrarFila(posicion);
	Logger::insert(Logger::TYPE_INFO, persona + " esta en la cola del " + juego.toString());
	this->jugar(juego, posicion, persona);
}

void ListaDeJuegos::jugar(Juego juego, int posicion, string persona){
	if (juego.haySuficientesPersonasParaJugar()){
		this->ejecutarJuego(juego, posicion, persona);
	}else{
		//TODO si soy el primero en llegar, hay que hacer un timed wait
		this->semaforoFila.wait(posicion);
		Logger::insert(Logger::TYPE_INFO, persona + " entro al " + juego.toString());
		this->semaforoJuego.wait(posicion);
	}
	Logger::insert(Logger::TYPE_INFO, persona + " salio del " + juego.toString());
}

void ListaDeJuegos::ejecutarJuego(Juego juego, int posicion, string persona){
	this->lockJuego.tomarLock(posicion);
	//tomo lock por si hay alguien jugando, hay que esperar q termine
	Logger::insert(Logger::TYPE_DEBUG, "Comienza ejecucion del " + juego.toString());
	Logger::insert(Logger::TYPE_INFO, persona + " entro al " + juego.toString());
	this->sacarPersonasDeLaFila(juego.getCapacidad() - 1, posicion);
	sleep(juego.getDuracion());
	this->sacarPersonasDelJuego(juego.getCapacidad() - 1, posicion);
	//En ambos casos se sacan capacidad - 1 porque uno es el proceso
	//que esta haciendo esto
	this->lockJuego.liberarLock(posicion);
}

void ListaDeJuegos::sacarPersonasDeLaFila(int cantidad, int posicion){
	for (int i = 0; i < cantidad; i++)
		//liberar tantos procesos de la fila como capacidad tenga el juego
		this->semaforoFila.signal(posicion);
}

void ListaDeJuegos::sacarPersonasDelJuego(int cantidad, int posicion){
	for (int i = 0; i < cantidad; i++)
		//liberar tantos procesos del juego como capacidad tenga el juego
		this->semaforoJuego.signal(posicion);
}

void ListaDeJuegos::salirJuego(int posicion){
	this->juegosCompartidos.salirJuego(posicion);
}
