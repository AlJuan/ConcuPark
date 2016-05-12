/*
 * JuegosCompartidos.h
 *
 *  Created on: Apr 23, 2016
 *      Author: juan
 */

#ifndef MODEL_JUEGOSCOMPARTIDOS_H_
#define MODEL_JUEGOSCOMPARTIDOS_H_

#include "../log/Logger.h"
#include <vector>

#include "../ipc/LockFile.h"
#include "../ipc/MemoriaCompartida.h"
#include "Juego.h"

using namespace std;

class JuegosCompartidos {
private:
	MemoriaCompartida<Juego> mem;
	LockFile lockEntrada;
	LockFile lockSalida;

	Juego tomarJuegoEntrada(int posicion);
	void liberarJuegoEntrada(int posicion);
	Juego tomarJuegoSalida(int posicion);
	void liberarJuegoSalida(int posicion);
public:
	JuegosCompartidos(vector<Juego> juegos);
	virtual ~JuegosCompartidos();
	/*
	 * Aumenta cantidad de personas en fila y cobra la entrada
	 * */
	Juego entrarFila(int posicion);
	/*
	 * Disminuye la cantidad de personas en la fila
	 * */
	void salirFila(int posicion, int cantidad);
	/*
	 * Disminuye la cantidad de personas jugando
	 * */
	void salirJuego(int posicion, int cantidad);
	/*
	 * getJuego no utiliza locks, se usa solo para lectura.
	 */
	Juego getJuego(int posicion);
	/*
	 * Lee de la memoria compartida la recaudacion de los juegos.
	 */
	static int consultarRecaudacion(int cantidadJuegos);
};

#endif /* MODEL_JUEGOSCOMPARTIDOS_H_ */
