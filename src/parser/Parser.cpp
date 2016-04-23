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

#define DELIMITADOR_VALORES ','
#define DELIMITADOR_LABEL ':'

Parser::Parser() {
	// TODO Auto-generated constructor stub

}

ConfiguracionParque Parser::parse(string nombreArchivo) {
	string capacidadesStr, costosStr, presupuestosStr, duracionesStr;

	ifstream archivo (nombreArchivo.c_str());
	getline(archivo, duracionesStr);
	getline(archivo, capacidadesStr);
	getline(archivo, costosStr);
	getline(archivo, presupuestosStr);
    archivo.close();

	ConfiguracionParque confParque;

    parseJuegos(&confParque, capacidadesStr, costosStr, duracionesStr);
    parsePersonas(&confParque, presupuestosStr);

	return confParque;

}

string Parser::obtenerValores(string linea, char delimitador) {
	vector<string> lineaSpliteada = split(linea, delimitador);
	return lineaSpliteada[lineaSpliteada.size() - 1];
}

void Parser::parseJuegos(ConfiguracionParque* confParque, string capacidadesStr, string costosStr, string duracionesStr) {
	vector<string> duraciones = split(obtenerValores(duracionesStr, DELIMITADOR_LABEL), DELIMITADOR_VALORES);
	vector<string> capacidades = split(obtenerValores(capacidadesStr, DELIMITADOR_LABEL), DELIMITADOR_VALORES);
	vector<string> costos = split(obtenerValores(costosStr, DELIMITADOR_LABEL), DELIMITADOR_VALORES);

	for (unsigned int i = 0; i < capacidades.size(); i++) {
		ConfiguracionJuego conf (atoi(capacidades[i].c_str()), atoi(costos[i].c_str()), atoi(duraciones[i].c_str()));
		confParque->agregarConfiguracionJuego(conf);
	}

}

void Parser::parsePersonas(ConfiguracionParque* confParque, string presupuestosStr) {
	vector<string> presupuestos = split(obtenerValores(presupuestosStr, DELIMITADOR_LABEL), DELIMITADOR_VALORES);

	for ( unsigned int i = 0; i < presupuestos.size(); i++) {
		ConfiguracionPersona conf (atoi(presupuestos[i].c_str()));
		confParque->agregarConfiguracionPersona(conf);
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

