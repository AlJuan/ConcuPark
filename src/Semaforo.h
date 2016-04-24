#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <string>

class Semaforo {

private:
	int id;
	int valorInicial;
	int cant;
	int inicializar () const;

public:
	Semaforo ( const std::string& nombre,const int valorInicial, int cant );
	~Semaforo();

	int wait (int pos) const; // decrementa
	int signal (int pos) const; // incrementa
	void eliminar () const;
};

#endif /* SEMAFORO_H_ */
