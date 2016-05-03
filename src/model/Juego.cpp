/*
 * Juego.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Juego.h"

#include "../configuraciones/ConfiguracionJuego.h"
#include <sstream>

Juego::Juego(int id, ConfiguracionJuego conf) {
	this->id = id;
	this->capacidad = conf.getCapacidad();
	this->duracion = conf.getDuracion();
	this->personasJugando = 0;
	this->personasEnFila = 0;
	this->dineroAcumulado = 0;
	this->costo = conf.getCosto();
}

void Juego::setCosto(int costo) {
	this->costo = costo;
}

int Juego::getCosto(){
	return costo;
}

int Juego::getId(){
	return id;
}

int Juego::getCapacidad() {
	return capacidad;
}

int Juego::getDineroAcumulado() {
	return dineroAcumulado;
}

int Juego::getCantidadPersonasEnFila() {
	return personasEnFila;
}

Juego::~Juego() {
	// TODO Auto-generated destructor stub
}

bool Juego::haySuficientesPersonasParaJugar(){
	return personasEnFila > 0 && (personasEnFila % capacidad) == 0;
}

void Juego::cobrarEntrada(){
	dineroAcumulado += this->costo;
}

int Juego::getDuracion(){
	return duracion;
}

void Juego::aumentarPersonasJugando(){
	this->personasJugando++;
}
void Juego::disminuirPersonasJugando(int cantidad){
	this->personasJugando-= cantidad;
}

int Juego::getCantidadListosParaJugar(){
	return (personasEnFila < capacidad)? personasEnFila : capacidad;
}

void Juego::aumentarPersonasEnFila(){
	this->personasEnFila++;
}
void Juego::disminuirPersonasEnFila(int cantidad){
	this->personasEnFila -= cantidad;
}

string Juego::toString(){
	stringstream stream;
	stream << "Juego "<< id;
	return stream.str();
}

