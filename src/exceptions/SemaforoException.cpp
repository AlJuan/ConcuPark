/*
 * MemoriaCompartidaException.cpp
 *
 *  Created on: May 11, 2016
 *      Author: juan
 */

#include "SemaforoException.h"
using namespace std;

string SemaforoException::TYPE_FTOK = "Error al crear semaforo - FTOK";
string SemaforoException::TYPE_SEMGET = "Error al crear semaforo - SEMGET";
string SemaforoException::TYPE_SEMCTL= "Error al iniciar/liberar el semaforo - SEMCTL";
string SemaforoException::TYPE_SEMOP = "Error al operar con el semaforo - SEMOP";
string SemaforoException::TYPE_SEMTIMEDOP= "Error al esperar el semaforo - SEMTIMEDOP";

SemaforoException::SemaforoException(string msg, int code) : IPCException(msg, code){

}

SemaforoException::~SemaforoException() {
}

