/*
 * Serializable.h
 *
 *  Created on: Apr 10, 2016
 *      Author: juan
 */

#ifndef MODEL_SERIALIZABLE_H_
#define MODEL_SERIALIZABLE_H_

#include <string>

using namespace std;

class Serializable {
protected:
	int id;
public:
	Serializable();
	virtual string toString() = 0;
//	virtual ~Serializable();
	int getId();
};


#endif /* MODEL_SERIALIZABLE_H_ */
