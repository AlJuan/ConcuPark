#include "LockFile.h"

#define ARCHIVO_LOCK_EXT "tmp"

LockFile :: LockFile ( const std::string nombre ) {
	std::string nombreCompleto = FileHelper::crearArchivo(nombre, ARCHIVO_LOCK_EXT);
	this->creadorPid = getpid();
	this->nombre = nombre;
	this->fl.l_type = F_WRLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = sizeof(char);
	//TODO manejar si falla
	this->fd = open ( nombreCompleto.c_str(),O_CREAT|O_WRONLY,0777 );
}

int LockFile :: tomarLock (int pos) {
	this->fl.l_type = F_WRLCK;
	this->fl.l_start = sizeof(char) * pos;
	//TODO manejar ERRNO si falla
	return fcntl ( this->fd,F_SETLKW,&(this->fl) );
}

int LockFile :: liberarLock (int pos) {
	this->fl.l_type = F_UNLCK;
	this->fl.l_start = sizeof(char) * pos;
	//TODO manejar ERRNO si falla
	return fcntl ( this->fd,F_SETLK,&(this->fl) );
}

ssize_t LockFile :: escribir ( const void* buffer,const ssize_t buffsize ) const {
	lseek ( this->fd,0,SEEK_END );
	//TODO manejar ERRNO si falla
	return write ( this->fd,buffer,buffsize );
}

LockFile :: ~LockFile () {
	close ( this->fd );
	if (this->creadorPid == getpid())
		FileHelper::borrarArchivo(this->nombre, ARCHIVO_LOCK_EXT);
}

