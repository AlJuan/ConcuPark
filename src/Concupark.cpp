//============================================================================
// Name        : Concupark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#include "MemoriaCompartida.h"
#include "Semaforo.h"
#include "model/Parque.h"
#include "model/Juego.h"
#include "parser/Parser.h"
#include "configuraciones/ConfiguracionParque.h"
#include "log/Logger.h"

using namespace std;

int main() {
//	string archivo ( "/home/kevin/Escritorio/ConcuPark/src/concuPark.conf" );
//
//	Parser parser;
//	ConfiguracionParque confParque = parser.parse(archivo);
//
//	Parque parque(confParque);
//	parque.abrirParque();
//
//	int cantPersonas = confParque.getConfiguracionesPersonas().size();
//	int status;
//	for (int i = 0; i < cantPersonas; i++) {
//		wait(&status);
//	}
//	Logger::insert(Logger::TYPE_INFO, "TERMINO");

	//// TEST PARSER ////
	/**list<ConfiguracionJuego> lista_configuracion_juegos = confParque.getConfiguracionesJuegos();
	list<ConfiguracionPersona> lista_configuracion_personas = confParque.getConfiguracionesPersonas();
	for (list<ConfiguracionJuego>::iterator it=lista_configuracion_juegos.begin(); it != lista_configuracion_juegos.end(); ++it) {
		cout << (*it).getCapacidad() << " " << (*it).getCosto() << endl;
	}
	for (list<ConfiguracionPersona>::iterator it=lista_configuracion_personas.begin(); it != lista_configuracion_personas.end(); ++it) {
		cout << (*it).getSaldoInicial() << endl;
	}*/
	//////////

	/*
	 *
	 * Prueba de forks y semaforos
	 *
	 * */

	Semaforo sem ("src/concuPark.conf", 1); //Si dejo la funcion FTOK como generador de clave y pongo cant > 1 se rompe todo
												//No se que tiene IPC_PRIVATE que hace que esto funcione, no se si funconaria en el juego
												//La cosa es que tendriamos que hacer un semaforo por proceso. Tampoco se si lo podemos usar
												//hay que mandar mail!
	int id = fork();
	if (id == 0) {
		int id2 = fork();
		if (id2 == 0) {
			cout << "PROCESO HIJO DEL HIJO WAIT" << endl;
			sem.wait(0);
			cout << "PROCESO HIJO DEL HIJO DESBLOQUEADO" << endl;
		} else {
			cout << "PROCESO HIJO WAIT" << endl;
			sem.wait(0);
			cout << "PROCESO HIJO DESBLOQUADO" << endl;
		}
	} else {
		//Proceso padre
		sleep(5);
		cout << "PROCESO PADRE SIGNAL" << endl;
		sem.signal(0);
		sleep(5);
		cout << "PROCESO PADRE SIGNAL" << endl;
		sem.signal(0);
	}






	//// TEST MEMORIA COMPARTIDA ////
	/**MemoriaCompartida<Juego> memoria;
	int estadoMemoria = memoria.crear ( archivo,'R', 5 );

	if ( estadoMemoria == SHM_OK ) {
		cout << "OK" << endl;
	} else {
		cout << "ERROR memoria compartida" << endl;
	}
	Juego juego;
	juego.setCosto(1);
	memoria.escribir(juego, 0);

	pid_t procId = fork ();

	if ( procId == 0 ) {
		juego.setCosto(2);
		sleep(2);
		memoria.escribir(juego, 0);
	} else {
		while (true){
			Juego j = memoria.leer(0);
			cout << j.getCosto() << endl;
			sleep(3);
		}

	}*/
	//////////

	return 0;
}
