/*
 * Prova.hpp
 *
 *  Created on: 13/gen/2015
 *      Author: nicola
 */

#ifndef PROVA_HPP_
#define PROVA_HPP_

#include <iostream>

class Prova {

private:
	std::string testo;
	int number;

public:
	Prova();
	Prova(std::string _testo, int _number);
	~Prova();

	int getNumber() const;
	void setNumber(int number);

	const std::string& getTesto() const;
	void setTesto(const std::string& testo);

};

#endif /* PROVA_HPP_ */
