/*
 * AbstractEvent.hpp
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_ABSTRACTEVENT_HPP_
#define VISUALIZER_ABSTRACTEVENT_HPP_

#include <iostream>

template <typename T = int>
class AbstractEvent {

private:
	T code;

public:
	AbstractEvent(const T& _code) {
		code = _code;
	}

	virtual ~AbstractEvent() { };

	T getCode() const {
		return code;
	}

	void setCode(T _code) {
		this->code = _code;
	}

	virtual void doEvent() {
		std::cout << "NIENTE" << std::endl;
	}

};

#endif /* VISUALIZER_ABSTRACTEVENT_HPP_ */