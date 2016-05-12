#include "Semaforo.h"

#include "../exceptions/SemaforoException.h"
#include "../log/Logger.h"

#define SEMAFORO_EXT "tmp"

Semaforo :: Semaforo ( const std::string& nombre,const int valorInicial, int cantidad):valorInicial(valorInicial), cantidad(cantidad), nombreArchivo(nombre) {
	string nombreArchivo = FileHelper::crearArchivo(nombre, SEMAFORO_EXT);
	key_t clave = ftok ( nombreArchivo.c_str(), 'a' );
	if (clave == -1 ) throw SemaforoException(SemaforoException::TYPE_FTOK, errno);
	this->id = semget ( clave, cantidad,0666 | IPC_CREAT );
	if (id == -1) throw SemaforoException(SemaforoException::TYPE_SEMGET, errno);
	this->inicializar ();
	this->pidCreador = getpid();
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
		resultado = semctl ( this->id,i,SETVAL,init );
		if (resultado == -1) throw SemaforoException(SemaforoException::TYPE_SEMCTL, errno);
	}
	Logger::insert(Logger::TYPE_DEBUG, "Semaforo creado correctamente (" + nombreArchivo + ")");
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
	if (resultado == -1 && errno != EAGAIN) //Si el error no fue por timeout tira exception
		throw SemaforoException(SemaforoException::TYPE_SEMTIMEDOP, errno);
	else return (resultado < 0)? errno : resultado;
}

void Semaforo :: wait (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = 0;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );
	if (resultado == -1) throw SemaforoException(SemaforoException::TYPE_SEMOP, errno);
}

void Semaforo :: signal (int pos) const {

	struct sembuf operacion;

	operacion.sem_num = pos;	// numero de semaforo
	operacion.sem_op  = 1;	// sumar 1 al semaforo
	operacion.sem_flg = 0;
	//El ultimo param de semop es la longitud del segundo parametro
	//en este caso siempre es uno
	int resultado = semop ( this->id,&operacion, 1 );
	if (resultado == -1) throw SemaforoException(SemaforoException::TYPE_SEMOP, errno);
}

void Semaforo :: eliminar () const {
	if (this->pidCreador == getpid()){
		for (int i = 0; i < cantidad; i++)
			semctl ( this->id, i, IPC_RMID );
		FileHelper::borrarArchivo(nombreArchivo, SEMAFORO_EXT);
	}

}
