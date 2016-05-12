//============================================================================
// Name        : Concupark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <sys/wait.h>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "configuraciones/ConfiguracionParque.h"
#include "exceptions/MemoriaCompartidaException.h"
#include "exceptions/IPCException.h"
#include "log/Logger.h"
#include "model/JuegosCompartidos.h"
#include "model/Parque.h"
#include "parser/Parser.h"

#define OPT_CONSULTA "-c"
#define OPT_DEBUG "-d"

#define ARCHIVO_CONFIG "concuPark.conf"

using namespace std;

bool existeParametro(int argc, char* argv[], string nombreParam);
void consultarRecaudacion();

int main(int argc, char* argv[]) {

	if (existeParametro(argc, argv, OPT_DEBUG)) {
		Logger::MODE_DEBUG = true;
	}
	if (existeParametro(argc, argv, OPT_CONSULTA)){
		consultarRecaudacion();
	} else {
		ConfiguracionParque confParque = Parser::parse(ARCHIVO_CONFIG);
		if (!confParque.isCreadoCorrectamente())
			return -1;

		try {
			Parque parque(confParque);
			Logger::insert(Logger::TYPE_INFO, "Abre el parque");
			int pid = parque.abrirParque();
			if (pid != 0){
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
		} catch (IPCException& e){
			Logger::insertError(e.what(), e.getCode());
		}

	}
	return 0;
}

void consultarRecaudacion(){
	try {
		int recaudacion = JuegosCompartidos::consultarRecaudacion(Parser::obtenerCantidadJuegos(ARCHIVO_CONFIG));
		cout << recaudacion << endl;
	} catch (MemoriaCompartidaException& e){
		Logger::insertError(e.what(), e.getCode());
	}
}

bool existeParametro(int argc, char* argv[], string nombreParam){
	for (int i = 1; i < argc; ++i) {
		string param = argv[i];
		if (param == nombreParam) return true;
	}
	return false;
}
