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

#define OPT_CONSULTA "-c"

using namespace std;

bool existeParametro(int argc, char* argv[], string nombreParam);

int main(int argc, char* argv[]) {

	if (existeParametro(argc, argv, OPT_CONSULTA)){
		//consultarRecaudacion!
	} else {
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
	}
	return 0;
}

bool existeParametro(int argc, char* argv[], string nombreParam){
	for (int i = 1; i < argc; ++i) {
		string param = argv[i];
		if (param == nombreParam) return true;
	}
	return false;
}
