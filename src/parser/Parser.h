/*
 * Parser.h
 *
 *  Created on: 3 de abr. de 2016
 *      Author: kevin
 */

#ifndef PARSER_PARSER_H_
#define PARSER_PARSER_H_

#include <vector>
#include "../configuraciones/ConfiguracionParque.h"
#include "../configuraciones/ConfiguracionJuego.h"
#include "../configuraciones/ConfiguracionPersona.h"

class Parser {
private:
	void parsePersonas(ConfiguracionParque* confParque, string presupuestosStr);
	void parseJuegos(ConfiguracionParque* confParque, string capacidadesStr, string costosStr, string duracionesStr);
	string obtenerValores(string linea, char delimitador);
	vector<string> split(const string s, char delim);
	void leerArchivo(string nombreArchivo, string& capacidadesStr, string& costosStr, string& duracionesStr, string& presupuestosStr);
public:
	Parser();
	ConfiguracionParque parse(string nombreArchivo);
	int obtenerCantidadJuegos(string nombreArchivo);
	virtual ~Parser();
};

#endif /* PARSER_PARSER_H_ */
