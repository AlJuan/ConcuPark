//============================================================================
// Name        : Concupark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>

#include "model/Parque.h"
#include "model/Juego.h"
#include "parser/Parser.h"
#include "configuraciones/ConfiguracionParque.h"
#include "ipc/MemoriaCompartida.h"
#include "ipc/Semaforo.h"
#include "log/Logger.h"

using namespace std;

int main(int argc, char* argv[]) {
	string archivo ( "concuPark.conf" );
	Parser parser;
	ConfiguracionParque confParque = parser.parse(archivo);

	Parque parque(confParque);
	Logger::insert(Logger::TYPE_DEBUG, "Abre el parque");
	int pid = parque.abrirParque();
	if (pid != 0){
		//TODO algo mas copado que devolver este pid fake
		int cantPersonas = confParque.getConfiguracionesPersonas().size();
		int status;
		// Espera a que todas las personas salgan del parque
		for (int i = 0; i < cantPersonas; i++) {
			wait(&status);
		}
		stringstream ss;
		ss << parque.obtenerRecaudacionCaja();
		Logger::insert(Logger::TYPE_DEBUG, "Cierra el parque");
		Logger::insert(Logger::TYPE_INFO, "Recaudacion total: $" + ss.str());
	}

	return 0;
}
