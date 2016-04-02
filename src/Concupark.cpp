//============================================================================
// Name        : Concupark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include <unistd.h>

#include "MemoriaCompartida.h"
#include "model/Juego.h"

using namespace std;

int main() {
	int cant_juegos = 5;

	string archivo ( "/home/kevin/Escritorio/ConcuPark/notas.txt" );
	MemoriaCompartida<Juego> memoria;
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

	}


	//ConfiguracionParque confParque = Parser.parse();
	//parque = crearParque(confParque);
	//parque.abrir();
	return 0;
}
