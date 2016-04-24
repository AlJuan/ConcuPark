#include "Semaforo.h"

Semaforo :: Semaforo ( const std::string& nombre,const int valorInicial, int cant ):valorInicial(valorInicial) {
	key_t clave = ftok ( nombre.c_str(), 'a' );
	this->id = semget ( IPC_PRIVATE, cant,0666 | IPC_CREAT );
	this->cant = cant;
	this->inicializar ();
}

Semaforo::~Semaforo() {
}

int Semaforo :: inicializar () const {

	union semnum {
		int val;
		struct semid_ds* buf;
		ushort* array;
	};

	semnum init;
	init.val = this->valorInicial;
	int resultado = 0;
	for (int x = 0; x < cant; x++){
		resultado = semctl ( this->id,x,SETVAL,init );
		if (resultado < 0) return resultado;
	}
	return resultado;
}

int Semaforo :: wait (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );

	return resultado;
}

int Semaforo :: signal (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = 1;	// sumar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );
	return resultado;
}

void Semaforo :: eliminar () const {
	semctl ( this->id,0,IPC_RMID );
}
