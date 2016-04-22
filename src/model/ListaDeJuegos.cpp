/*
 * ListaDeJuegos.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include <iostream>

#include "ListaDeJuegos.h"
#include "../log/Logger.h"

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) {

	//TODO:Hay que hacer un lock o mutex o algo en esta clase porque puede suceder
	//que proc1 lea, proc2 lea, modifiquen y escriban los dos sobreescribiendo el
	//Cambio del que escribio primero.

	string archivo ( "src/concuPark.conf" );
	this->cantidad = juegos.size();
	int estadoMemoria = mem.crear ( archivo,'R', juegos.size());
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
	this->esperarAQueSeLlene(juego);
}

void ListaDeJuegos::esperarAQueSeLlene(Juego juego){
	if (juego.estaLleno()){}
		//Signal del semaforo que espera a que se llene
		//Tambien se puede poner el wait aca en vez de que lo haga cada proceso y
		//tirar el signal post sleep
	else{}
		//wait del semaforo que espera a que se llene

}

void ListaDeJuegos::salirJuego(int posicion){
	Juego juego = this->tomarJuego(posicion);
	juego.disminuirPersonasJugando();
	this->liberarJuego(posicion);
}

Juego ListaDeJuegos::tomarJuego(int posicion) {
	//TODO ACA TIENE QUE ESTAR EL WAIT DEL SEMAFORO
	return this->mem.leer(posicion);

}
void ListaDeJuegos::liberarJuego(int posicion){
	//TODO ESTE ES EL SIGNAL DEL SEMAFORO

}
