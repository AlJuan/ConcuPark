/*
 * Parque.cpp
 *
 *  Created on: 2 de abr. de 2016
 *      Author: kevin
 */

#include "Parque.h"

Parque::Parque(ConfiguracionParque configuracionParque) {
	crearJuegos(configuracionParque.getConfiguracionesJuegos());
	crearPersonas(configuracionParque.getConfiguracionesPersonas());


}

void Parque::crearJuegos(list<ConfiguracionJuego> configuracionJuegos) {
	//crear juegos
	//crear lista de juegos
}

void Parque::crearPersonas(list<ConfiguracionPersona> configuracionPersonas) {

}

Parque::~Parque() {
	// TODO Auto-generated destructor stub
}

