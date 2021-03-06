/*
 * MemoriaCompartidaException.h
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#ifndef IPCEXCEPTION_H_
#define IPCEXCEPTION_H_

#include <stdexcept>
#include <string>

using namespace std;

/*
 * Exception base para cualquier problema de comunicacion
 * entre procesos o sincronizacion.
 * */

class IPCException: public runtime_error {
	int code;
public:
	IPCException(string msg, int code);
	virtual ~IPCException();
	int getCode();
};

#endif
