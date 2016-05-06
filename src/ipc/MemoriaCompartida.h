#ifndef IPC_MEMORIACOMPARTIDA_H_
#define IPC_MEMORIACOMPARTIDA_H_

#define SHM_OK			 0
#define	ERROR_FTOK		-1
#define ERROR_SHMGET	-2
#define	ERROR_SHMAT		-3

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include "FileHelper.h"

#define MEMORIA_EXT "tmp"

template <class T> class MemoriaCompartida {

private:
	int shmId;
	T*	ptrDatos;

	int cantidadProcesosAdosados () const;

public:
	MemoriaCompartida ();
	~MemoriaCompartida ();
	int crear ( const std::string& archivo,const char letra, int cat );
	void liberar (std::string nombreArchivo);
	void escribir ( const T& dato, int pos );
	T leer (int pos) const;

};

template <class T> MemoriaCompartida<T> :: MemoriaCompartida() : shmId(0), ptrDatos(NULL) {
}

template <class T> MemoriaCompartida<T> :: ~MemoriaCompartida() {
}

template <class T> int MemoriaCompartida<T> :: crear ( const std::string& archivo,const char letra, int cant ) {
	string nombreArchivo = FileHelper::crearArchivo(archivo, MEMORIA_EXT);
	// generacion de la clave
	key_t clave = ftok ( nombreArchivo.c_str(),letra );
	if ( clave == -1 )
		return ERROR_FTOK;
	else {
		// creacion de la memoria compartida
		this->shmId = shmget ( clave,sizeof(T) * cant,0644|IPC_CREAT );

		if ( this->shmId == -1 )
			return ERROR_SHMGET;
		else {
			// attach del bloque de memoria al espacio de direcciones del proceso
			void* ptrTemporal = shmat ( this->shmId,NULL,0 );

			if ( ptrTemporal == (void *) -1 ) {
				return ERROR_SHMAT;
			} else {
				this->ptrDatos = static_cast<T*> (ptrTemporal);
				return SHM_OK;
			}
		}
	}
}


template <class T> void MemoriaCompartida<T> :: liberar (std::string nombreArchivo) {
	// detach del bloque de memoria
	shmdt ( static_cast<void*> (this->ptrDatos) );

	int procAdosados = this->cantidadProcesosAdosados ();

	if ( procAdosados == 0 ) {
		shmctl ( this->shmId,IPC_RMID,NULL );
		FileHelper::borrarArchivo(nombreArchivo, MEMORIA_EXT);
	}
}

template <class T> void MemoriaCompartida<T> :: escribir ( const T& dato, int pos ) {
	this->ptrDatos[pos] = dato;
}

template <class T> T MemoriaCompartida<T> :: leer (int pos) const {
	return ( this->ptrDatos[pos] );
}

template <class T> int MemoriaCompartida<T> :: cantidadProcesosAdosados () const {
	shmid_ds estado;
	shmctl ( this->shmId,IPC_STAT,&estado );
	return estado.shm_nattch;
}


#endif /* IPC_MEMORIACOMPARTIDA_H_ */
