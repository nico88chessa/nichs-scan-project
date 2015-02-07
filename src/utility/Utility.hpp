/*
 * Utility.hpp
 *
 *  Created on: 17/gen/2015
 *      Author: nicola
 */

#ifndef UTILITY_UTILITY_HPP_
#define UTILITY_UTILITY_HPP_

#include <iostream>

class Utility {
public:
	Utility();
	virtual ~Utility();

	static const char* string2char(const std::string& stringa);
};

#endif /* UTILITY_UTILITY_HPP_ */
