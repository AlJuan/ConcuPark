#ifndef LOCKFILE_H_
#define LOCKFILE_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>

using namespace std;

template <class T> class LockFile {

private:
	struct flock fl;
	int fd;
	std::string nombre;

public:
	LockFile ( const std::string nombre );
	~LockFile();

	int tomarLock (int pos);
	int liberarLock (int pos);
	ssize_t escribir ( const void* buffer,const ssize_t buffsize ) const;
};

#endif /* LOCKFILE_H_ */
