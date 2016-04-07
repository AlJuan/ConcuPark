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
#include "model/Juego.h"
#include "parser/Parser.h"
#include "configuraciones/ConfiguracionParque.h"


using namespace std;

int main() {
	int cant_juegos = 5;

	string archivo ( "/home/juan/git/ConcuPark/src/concuPark.conf" );
	MemoriaCompartida<Juego> memoria;
	int estadoMemoria = memoria.crear ( archivo,'R', 5 );
	if ( estadoMemoria == SHM_OK ) {
		cout << "OK" << endl;
	} else {
		cout << "ERROR memoria compartida" << endl;
	}

	//// TEST PARSER ////
	Parser parser;
	ConfiguracionParque confParque = parser.parse(archivo);
	list<ConfiguracionJuego> lista_configuracion_juegos = confParque.getConfiguracionesJuegos();
	list<ConfiguracionPersona> lista_configuracion_personas = confParque.getConfiguracionesPersonas();

	for (list<ConfiguracionJuego>::iterator it=lista_configuracion_juegos.begin(); it != lista_configuracion_juegos.end(); ++it) {
		cout << (*it).getCapacidad() << " " << (*it).getCosto() << endl;
	}
	for (list<ConfiguracionPersona>::iterator it=lista_configuracion_personas.begin(); it != lista_configuracion_personas.end(); ++it) {
		cout << (*it).getSaldoInicial() << endl;
	}
	//////////


	//// TEST MEMORIA COMPARTIDA ////
	/**Juego juego;
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
