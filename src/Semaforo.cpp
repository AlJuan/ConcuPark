#include "Semaforo.h"
#include "log/Logger.h"

Semaforo :: Semaforo ( const std::string& nombre,const int valorInicial, int cantidad):valorInicial(valorInicial), cantidad(cantidad) {
	key_t clave = ftok ( nombre.c_str(), 'a' );
	this->id = semget ( clave, cantidad,0666 | IPC_CREAT );
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
	int resultado;
	for (int i = 0; i < this->cantidad; i++){
		//TODO manejo de errores!
		resultado = semctl ( this->id,i,SETVAL,init );
	}

	return resultado;
}

int Semaforo :: timedWait (int pos, int seconds) {
	struct sembuf operacion;
	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = 0;
	struct timespec time;
	time.tv_sec = seconds;
	time.tv_nsec = 0;
	int resultado = semtimedop ( this->id,&operacion, 1, &time );

	return (resultado < 0)? errno : resultado;
}

int Semaforo :: wait (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = 0;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );

	return (resultado < 0)? errno : resultado;
}

int Semaforo :: signal (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = 1;	// sumar 1 al semaforo
	operacion.sem_flg = 0;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );
	return resultado;
}

void Semaforo :: eliminar () const {
	for (int i = 0; i < cantidad; i++)
		semctl ( this->id, i, IPC_RMID );
}
