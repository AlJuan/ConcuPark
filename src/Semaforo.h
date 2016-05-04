#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <cerrno>

class Semaforo {

private:
	int id;
	int valorInicial;
	int cantidad;
	pid_t pidCreador;
	int inicializar () const;

public:
	Semaforo ( const std::string& nombre,const int valorInicial, int cantidad);
	~Semaforo();
	int timedWait(int pos, int seconds);
	int wait (int pos) const; // decrementa
	int signal (int pos) const; // incrementa
	void eliminar () const;
};

#endif /* SEMAFORO_H_ */
