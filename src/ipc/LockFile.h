#ifndef IPC_LOCKFILE_H_
#define IPC_LOCKFILE_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "FileHelper.h"

class LockFile {

private:
	struct flock fl;
	int fd;
	std::string nombre;
	pid_t creadorPid;

public:
	LockFile ( const std::string nombre );
	~LockFile();

	int tomarLock (int pos);
	int liberarLock (int pos);
	ssize_t escribir ( const void* buffer,const ssize_t buffsize ) const;
};

#endif /* IPC_LOCKFILE_H_ */
