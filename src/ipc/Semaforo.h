#ifndef IPC_SEMAFORO_H_
#define IPC_SEMAFORO_H_

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <cerrno>
#include "FileHelper.h"

class Semaforo {

private:
	int id;
	int valorInicial;
	int cantidad;
	pid_t pidCreador;
	string nombreArchivo;
	int inicializar () const;

public:
	Semaforo ( const std::string& nombre,const int valorInicial, int cantidad);
	~Semaforo();
	int timedWait(int pos, int seconds);
	void wait (int pos) const; // decrementa
	void signal (int pos) const; // incrementa
	void eliminar () const;
};

#endif /* IPC_SEMAFORO_H_ */
