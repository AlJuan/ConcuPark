/*
 * ListaDeJuegos.h
 *
 *  Created on: Apr 2, 2016
 *      Author: juan
 */

#ifndef MODEL_LISTADEJUEGOS_H_
#define MODEL_LISTADEJUEGOS_H_

using namespace std;

#include "Juego.h"
#include "../MemoriaCompartida.h"
#include <vector>

class ListaDeJuegos {
private:
	MemoriaCompartida<Juego> mem;
	int cantidad;
public:
	ListaDeJuegos(vector<Juego> vec);
	Juego getJuego(int posicion);
	int getCantidad();
	void setJuego(Juego* juego, int posicion);
	virtual ~ListaDeJuegos();
};



#endif /* MODEL_LISTADEJUEGOS_H_ */
