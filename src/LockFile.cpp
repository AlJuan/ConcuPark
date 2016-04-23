#include "LockFile.h"

template <class T> LockFile<T> :: LockFile ( const string nombre ) {

	this->nombre = nombre;
	this->fl.l_type = F_WRLCK;
	this->fl.l_whence = SEEK_SET;
	this->fl.l_start = 0;
	this->fl.l_len = 0;
	this->fd = open ( this->nombre.c_str(),O_CREAT|O_WRONLY,0777 );
}

template <class T> int LockFile<T> :: tomarLock (int pos) {
	this->fl.l_type = F_WRLCK;
	this->fl.l_len = sizeof(T);
	this->fl.l_start =  sizeof(T) * pos;
	return fcntl ( this->fd,F_SETLKW,&(this->fl) );
}

template <class T> int LockFile<T> :: liberarLock (int pos) {
	this->fl.l_type = F_UNLCK;
	this->fl.l_len = sizeof(T);
	this->fl.l_start =  sizeof(T) * pos
	return fcntl ( this->fd,F_SETLK,&(this->fl) );
}

template <class T> ssize_t LockFile<T> :: escribir ( const void* buffer,const ssize_t buffsize ) const {
	lseek ( this->fd,0,SEEK_END );
	return write ( this->fd,buffer,buffsize );
}

template <class T> LockFile<T> :: ~LockFile () {
	close ( this->fd );
}
