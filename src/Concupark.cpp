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

	Juego juego1;
	Juego juego2;
	juego1.setCosto(3);
	juego2.setCosto(5);

	memoria.escribir(juego1, 0);
	memoria.escribir(juego2, 1);

	Juego j1 = memoria.leer(0);
	Juego j2 = memoria.leer(1);

	if (j1.getCosto() == juego1.getCosto())
		cout << "igual" << endl;
	if (j2.getCosto() == juego2.getCosto())
		cout << "igual" << endl;



	//ConfiguracionParque confParque = Parser.parse();
	//parque = crearParque(confParque);
	//parque.abrir();
	return 0;
}
