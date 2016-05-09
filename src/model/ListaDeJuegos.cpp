/*
 * ListaDeJuegos.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include <iostream>

#include "ListaDeJuegos.h"
#include "../log/Logger.h"

#define ARCHIVO_SEM_FILA "semaforofila"
#define ARCHIVO_JUEGO "locklistadejuegos"
#define ARCHIVO_SEM_JUEGO "semaforojuego"
#define ESPERAR_JUEGO 60 //1min

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) : juegosCompartidos(juegos),
	semaforoFila(ARCHIVO_SEM_FILA, 0, juegos.size()), semaforoJuego(ARCHIVO_SEM_JUEGO, 0, juegos.size()),
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

void ListaDeJuegos::entrarFila(int posicion, string persona){
	Juego juego = this->juegosCompartidos.entrarFila(posicion);
	Logger::insert(Logger::TYPE_INFO, persona + " esta en la cola del " + juego.toString());
	this->jugar(juego, posicion, persona);
}

void ListaDeJuegos::entrarJuego(int posicion, string persona, string juego) {
	// Entro al juego y espera a que termine
	Logger::insert(Logger::TYPE_INFO, persona + " entro al " + juego);
	this->semaforoJuego.wait(posicion);
}

void ListaDeJuegos::esperarCola(int posicion, string persona, string juego) {
	int err = this->semaforoFila.timedWait(posicion, ESPERAR_JUEGO);
	if (err == EAGAIN){
		// Timeout: Comienza el juego aunque la fila no este llena
		this->ejecutarJuego(posicion, persona);
	}else{
		entrarJuego(posicion, persona, juego);
	}

}

void ListaDeJuegos::jugar(Juego juego, int posicion, string persona){
	if (juego.haySuficientesPersonasParaJugar()){
		this->ejecutarJuego(posicion, persona);
	}else{
		esperarCola(posicion, persona, juego.toString());
	}
	Logger::insert(Logger::TYPE_INFO, persona + " salio del " + juego.toString());
}

void ListaDeJuegos::ejecutarJuego(int posicion, string persona){
	// Toma Lock por si hay alguien jugando, hay que esperar a que termine
	this->lockJuego.tomarLock(posicion);
	Juego juego = this->juegosCompartidos.getJuego(posicion);
	//Se resta uno porque uno de los procesos es este
	int cantidadPersonasAJugar = juego.getCantidadListosParaJugar() - 1;
	Logger::insert(Logger::TYPE_DEBUG, "Comienza ejecucion del " + juego.toString());
	Logger::insert(Logger::TYPE_INFO, persona + " entro al " + juego.toString());
	this->juegosCompartidos.salirFila(posicion, 1);
	this->sacarPersonasDeLaFila(cantidadPersonasAJugar, posicion);
	sleep(juego.getDuracion()); // Simula tiempo jugando
	Logger::insert(Logger::TYPE_DEBUG, "Termina ejecucion del " + juego.toString());
	this->sacarPersonasDelJuego(cantidadPersonasAJugar, posicion);
	this->lockJuego.liberarLock(posicion);
}

void ListaDeJuegos::sacarPersonasDeLaFila(int cantidad, int posicion){
	this->juegosCompartidos.salirFila(posicion, cantidad);
	for (int i = 0; i < cantidad; i++)
		this->semaforoFila.signal(posicion);
}

void ListaDeJuegos::sacarPersonasDelJuego(int cantidad, int posicion){
	for (int i = 0; i < cantidad; i++)
		this->semaforoJuego.signal(posicion);
}

void ListaDeJuegos::salirJuego(int posicion){
	this->juegosCompartidos.salirJuego(posicion, 1);
}

int ListaDeJuegos::obtenerRecaudacionCaja(){
	int recaudacion = 0;
	for (int i = 0; i < this->getCantidad(); i++) {
		Juego j = this->getJuego(i);
		recaudacion += j.getDineroAcumulado();
	}
	return recaudacion;
}
