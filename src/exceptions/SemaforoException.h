/*
 * MemoriaCompartidaException.h
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#ifndef SEMAFOROEXCEPTION_H_
#define SEMAFOROEXCEPTION_H_

#include <string>

#include "IPCException.h"

using namespace std;

class SemaforoException : public IPCException {
public:
	SemaforoException(string msg, int code);
	virtual ~SemaforoException();
	static string TYPE_FTOK;
	static string TYPE_SEMGET;
	static string TYPE_SEMCTL;
	static string TYPE_SEMOP;
	static string TYPE_SEMTIMEDOP;

};

#endif
