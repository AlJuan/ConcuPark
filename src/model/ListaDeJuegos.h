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
#include "JuegosCompartidos.h"
#include "../MemoriaCompartida.h"
#include "../LockFile.h"
#include "../Semaforo.h"
#include <vector>

class ListaDeJuegos {
private:
	JuegosCompartidos juegosCompartidos;
	Semaforo semaforoFila;
	Semaforo semaforoJuego;
	LockFile lockJuego;
	int cantidad;

	void jugar(Juego juego, int posicion, string persona);
	void ejecutarJuego(Juego juego, int posicion, string persona);
	void sacarPersonasDelJuego(int cantidad, int posicion);
	void sacarPersonasDeLaFila(int cantidad, int posicion);

public:
	ListaDeJuegos(vector<Juego> vec);
	/*
	 * getJuego se usa para solo lectura!
	 */
	Juego getJuego(int posicion);
	void entrarJuego(int posicion, string persona);
	void salirJuego(int posicion);
	int getCantidad();

	virtual ~ListaDeJuegos();
};



#endif /* MODEL_LISTADEJUEGOS_H_ */
