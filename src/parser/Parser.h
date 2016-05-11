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
	static void parsePersonas(ConfiguracionParque* confParque, string presupuestosStr);
	static bool parseJuegos(ConfiguracionParque* confParque, string capacidadesStr, string costosStr, string duracionesStr);
	static string obtenerValores(string linea, char delimitador);
	static vector<string> split(const string s, char delim);
	static bool faltanPropiedadesDeJuegos(int duraciones, int capacidades, int costos);
	static bool leerArchivo(string nombreArchivo, string& capacidadesStr, string& costosStr, string& duracionesStr, string& presupuestosStr);
public:
	static ConfiguracionParque parse(string nombreArchivo);
	static int obtenerCantidadJuegos(string nombreArchivo);
	virtual ~Parser();
};

#endif /* PARSER_PARSER_H_ */
