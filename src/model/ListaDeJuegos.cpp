/*
 * ListaDeJuegos.cpp
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#include "ListaDeJuegos.h"

ListaDeJuegos::ListaDeJuegos(vector<Juego> juegos) {
	string archivo ( "../concuPark.conf" );
	MemoriaCompartida<Juego> memoria;
	this->cantidad = juegos.size();
	int estadoMemoria = memoria.crear ( archivo,'R', juegos.size());
	for (int index = 0; index < juegos.size(); index++){
		memoria.escribir(juegos[index], index);
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

void ListaDeJuegos::setJuego(Juego* juego, int posicion) {
	if (posicion >= cantidad) return;
	this->mem.escribir(*juego, posicion);
}

