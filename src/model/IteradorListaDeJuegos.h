/*
 * IteradorListaDeJuegos.h
 *
 *  Created on: Apr 3, 2016
 *      Author: juan
 */

#ifndef MODEL_ITERADORLISTADEJUEGOS_H_
#define MODEL_ITERADORLISTADEJUEGOS_H_

#include "ListaDeJuegos.h"

using namespace std;

//Iterador circular de la lista de juegos.
class IteradorListaDeJuegos {
private:
	ListaDeJuegos* lista;
	int posicion;
public:
	IteradorListaDeJuegos(ListaDeJuegos* ptr);
	ListaDeJuegos* getLista();
	Juego getSiguienteJuego();
	void entrarJuegoActual(string persona);
	void salirJuegoActual();
	bool esElUltimoJuego();
	virtual ~IteradorListaDeJuegos();
};


#endif /* MODEL_ITERADORLISTADEJUEGOS_H_ */
