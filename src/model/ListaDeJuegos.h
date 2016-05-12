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
#include "../ipc/LockFile.h"
#include "../ipc/Semaforo.h"
#include <vector>

class ListaDeJuegos {
private:
	JuegosCompartidos juegosCompartidos;
	Semaforo semaforoFila;
	Semaforo semaforoJuego;
	LockFile lockJuego;
	int cantidad;
	/*
	 * Ejecuta el juego o espera en cola dependiendo si hay la cantidad
	 * de gente necesaria para comenzar
	 * */
	void jugar(Juego juego, int posicion, string persona);
	/*
	 * Inicia la ejecucion del juego, tardando su correspondiente tiempo.
	 * */
	void ejecutarJuego(int posicion, string persona);
	/*
	 * Saca del juego a las personas que actualmente estan jugando
	 * */
	void sacarPersonasDelJuego(int cantidad, int posicion);
	/*
	 * Saca de la fila a las personas que estan esperando
	 * */
	void sacarPersonasDeLaFila(int cantidad, int posicion);
	/*
	 * Entra al juego y espera a que termine
	 * */
	void entrarJuego(int posicion, string persona, string juego);
	/*
	 * Entra a la cola hasta que sea su turno o se canse de esperar
	 * */
	void esperarCola(int posicion, string persona, string juego);

public:
	ListaDeJuegos(vector<Juego> vec);
	/*
	 * getJuego solo se usa para lectura no usa locks.
	 */
	Juego getJuego(int posicion);
	void entrarFila(int posicion, string persona);
	/*
	 * Obtiene la recaudacion total de los juegos sin lockear
	 * */
	int obtenerRecaudacionCaja();
	void salirJuego(int posicion);
	int getCantidad();

	virtual ~ListaDeJuegos();
};



#endif /* MODEL_LISTADEJUEGOS_H_ */
