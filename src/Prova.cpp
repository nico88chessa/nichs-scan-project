/*
 * Prova.cpp
 *
 *  Created on: 13/gen/2015
 *      Author: nicola
 */

#include "Prova.hpp"

Prova::Prova() {
	std::cout << "PASSA" << std::endl;
	testo = "ciao";
	number = 0;
}

Prova::Prova(std::string _testo, int _number):
		testo(_testo), number(_number) {
}

Prova::~Prova() {
}

int Prova::getNumber() const {
	return number;
}

void Prova::setNumber(int number) {
	this->number = number;
}

const std::string& Prova::getTesto() const {
	return testo;
}

void Prova::setTesto(const std::string& testo) {
	this->testo = testo;
}
