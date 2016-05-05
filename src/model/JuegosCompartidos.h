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
	LockFile lock;

	Juego tomarJuego(int posicion);
	void liberarJuego(int posicion);

public:
	JuegosCompartidos(vector<Juego> juegos);
	virtual ~JuegosCompartidos();
	Juego entrarFila(int posicion);
	void salirFila(int posicion, int cantidad);
	void salirJuego(int posicion, int cantidad);
	/*
	 * getJuego se usa para solo lectura!
	 */
	Juego getJuego(int posicion);
};

#endif /* MODEL_JUEGOSCOMPARTIDOS_H_ */
