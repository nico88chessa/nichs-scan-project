/*
 * KeyboardHandler.cpp
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#include "KeyboardHandler.hpp"

KeyboardHandler::KeyboardHandler() : events(), events2char() {
	events.insert(std::pair<int, AbstractEventPtr>(1, (AbstractEventPtr) new EventProva()));
	events.insert(std::pair<int, AbstractEventPtr>(2, (AbstractEventPtr) new EventProva(2)));
	events.insert(std::pair<int, AbstractEventPtr>(3, (AbstractEventPtr) new AbstractEvent<>(-1)));
	events.insert(std::pair<int, AbstractEventPtr>(3, (AbstractEventPtr) new EventProva()));

	events2char.insert(std::pair<char, int>('1', 1));
	events2char.insert(std::pair<char, int>('2', 2));
	events2char.insert(std::pair<char, int>('a', 3));
	events2char.insert(std::pair<char, int>('b', 1));
}

KeyboardHandler::~KeyboardHandler() {
}

AbstractEvent<>& KeyboardHandler::process(char c) {
	std::cout << "Carattere Stampato: " << c << std::endl;

	return *events.at(events2char.at(c));

//	if (c == '1') {
//		std::cout << "Passa 1" << std::endl;
//		return *(new EventProva());
//	} else if (c == '2') {
//		std::cout << "Passa 2" << std::endl;
//		return *(new EventProva(2));
//	} else {
//		std::cout << "Passa Other" << std::endl;
//		return *(new AbstractEvent<int>(-1));
//	}
}
