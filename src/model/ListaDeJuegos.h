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
#include "../LockFile.h"
#include "../Semaforo.h"
#include <vector>

class ListaDeJuegos {
private:
	MemoriaCompartida<Juego> mem;
	LockFile lock;
	Semaforo semaforoFila;
	Semaforo semaforoJuego;
	LockFile lockJuego;
	int cantidad;
	void setJuego(Juego juego, int posicion);
	Juego tomarJuego(int posicion);
	void liberarJuego(int posicion);
	void esperarAQueSeLlene(Juego juego, int posicion);

public:
	ListaDeJuegos(vector<Juego> vec);
	/*
	 * getJuego se usa para solo lectura!
	 */
	Juego getJuego(int posicion);
	void entrarJuego(int posicion);
	void salirJuego(int posicion);
	int getCantidad();

	virtual ~ListaDeJuegos();
};



#endif /* MODEL_LISTADEJUEGOS_H_ */
