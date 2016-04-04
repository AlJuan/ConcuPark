/*
 * Parser.cpp
 *
 *  Created on: 3 de abr. de 2016
 *      Author: kevin
 */

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "Parser.h"

using namespace std;

Parser::Parser() {
	// TODO Auto-generated constructor stub

}

ConfiguracionParque* Parser::parse(string nombreArchivo) {
	string capacidadesStr, costosStr, presupuestosStr;

	ifstream archivo (nombreArchivo.c_str());
	getline(archivo, capacidadesStr);
	getline(archivo, costosStr);
	getline(archivo, presupuestosStr);
    archivo.close();

	ConfiguracionParque* confParque = new ConfiguracionParque();

    parseJuegos(confParque, capacidadesStr, costosStr);
    parsePersonas(confParque, presupuestosStr);

	return confParque;

}


void Parser::parseJuegos(ConfiguracionParque* confParque, string capacidadesStr, string costosStr) {
	vector<string> capacidades = split(capacidadesStr, ',');
	vector<string> costos = split(costosStr, ',');

	for (unsigned int i = 0; i < capacidades.size(); i++) {
		confParque->agregarConfiguracionJuego(atoi(capacidades[i].c_str()), atoi(costos[i].c_str()));
	}

}

void Parser::parsePersonas(ConfiguracionParque* confParque, string presupuestosStr) {
	vector<string> presupuestos = split(presupuestosStr, ',');

	for ( unsigned int i = 0; i < presupuestos.size(); i++) {
		confParque->agregarConfiguracionPersona(atoi(presupuestos[i].c_str()));
	}
}

vector<string> Parser::split(const string s, char delim) {

	vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

