/*
 * MemoriaCompartidaException.h
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#ifndef MEMORIACOMPARTIDAEXCEPTION_H_
#define MEMORIACOMPARTIDAEXCEPTION_H_

#include <stdexcept>
#include <string>

using namespace std;

class MemoriaCompartidaException: public runtime_error {
	int code;
public:
	MemoriaCompartidaException(string msg, int code);
	virtual ~MemoriaCompartidaException();
	int getCode();
	static string TYPE_FTOK;
	static string TYPE_SHMGET;
	static string TYPE_SHMAT;
};

#endif
