/*
 * MemoriaCompartidaException.cpp
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#include "MemoriaCompartidaException.h"

using namespace std;

string MemoriaCompartidaException::TYPE_FTOK = "Error al crear memoria compartida - FTOK";
string MemoriaCompartidaException::TYPE_SHMGET = "Error al crear memoria compartida - SHMGET";
string MemoriaCompartidaException::TYPE_SHMAT = "Error al crear memoria compartida - SHMAT";

MemoriaCompartidaException::MemoriaCompartidaException(string msg, int code) : runtime_error(msg), code(code){

}

int MemoriaCompartidaException::getCode(){
	return code;
}

MemoriaCompartidaException::~MemoriaCompartidaException() {
}

