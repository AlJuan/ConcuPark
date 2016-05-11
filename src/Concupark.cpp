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
#define OPT_DEBUG "-d"

#define ARCHIVO_CONFIG "concuPark.conf"

using namespace std;

bool existeParametro(int argc, char* argv[], string nombreParam);

int main(int argc, char* argv[]) {

	if (existeParametro(argc, argv, OPT_DEBUG)) {
		Logger::MODE_DEBUG = true;
	}
	if (existeParametro(argc, argv, OPT_CONSULTA)){
		cout << JuegosCompartidos::consultarRecaudacion(Parser::obtenerCantidadJuegos(ARCHIVO_CONFIG)) << endl;
	} else {
		ConfiguracionParque confParque = Parser::parse(ARCHIVO_CONFIG);
		if (!confParque.isCreadoCorrectamente())
			return -1;

		Parque parque(confParque);
		Logger::insert(Logger::TYPE_INFO, "Abre el parque");
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
			Logger::insert(Logger::TYPE_INFO, "Cierra el parque");
			Logger::insert(Logger::TYPE_DEBUG, "Recaudacion total: $" + ss.str());
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
