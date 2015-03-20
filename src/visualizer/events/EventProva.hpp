/*
 * EventProva.h
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_EVENTPROVA_HPP_
#define VISUALIZER_EVENTS_EVENTPROVA_HPP_

#include "../AbstractEvent.hpp"
#include <iostream>

class EventProva : public AbstractEvent<int> {
public:
	EventProva() : AbstractEvent<int>(1) {
	};

	EventProva(int _code) : AbstractEvent<int>(_code) {
	};

	virtual ~EventProva() { };

	void doEvent() {
		std::cout << "Evento: " << getCode() << " chiamato con successo." << std::endl;
	}
};


#endif /* VISUALIZER_EVENTS_EVENTPROVA_HPP_ */
