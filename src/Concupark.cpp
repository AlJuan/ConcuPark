//============================================================================
// Name        : Concupark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>

#include "MemoriaCompartida.h"
#include "model/Parque.h"
#include "model/Juego.h"
#include "parser/Parser.h"
#include "configuraciones/ConfiguracionParque.h"
#include "log/Logger.h"

using namespace std;

int main() {
	string archivo ( "/home/juan/git/ConcuPark/src/concuPark.conf" );

	Parser parser;
	ConfiguracionParque confParque = parser.parse(archivo);

	Parque parque(confParque);
	parque.abrirParque();
	//Pongo este sleep porque los juegos tardan un rato. si este proc termina antes entonces no se ve el result de las personas
	sleep(30);
	Logger::insert(Logger::TYPE_INFO, "TERMINO");

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
