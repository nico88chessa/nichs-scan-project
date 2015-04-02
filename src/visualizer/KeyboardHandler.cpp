/*
 * KeyboardHandler.cpp
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#include "KeyboardHandler.hpp"

using namespace std;

KeyboardHandler::KeyboardHandler() : events(), events2char() {
	events.insert(pair<int, AbstractEvent<>::Ptr>(1, (AbstractEvent<>::Ptr) new EventProva()));
	events.insert(pair<int, AbstractEvent<>::Ptr>(2, (AbstractEvent<>::Ptr) new EventProva(2)));
	events.insert(pair<int, AbstractEvent<>::Ptr>(3, (AbstractEvent<>::Ptr) new AbstractEvent<>(-1)));
	events.insert(pair<int, AbstractEvent<>::Ptr>(3, (AbstractEvent<>::Ptr) new EventProva()));

	events2char.insert(pair<char, int>('1', 1));
	events2char.insert(pair<char, int>('2', 2));
	events2char.insert(pair<char, int>('a', 3));
	events2char.insert(pair<char, int>('b', 1));
}

KeyboardHandler::~KeyboardHandler() {
}

AbstractEvent<>& KeyboardHandler::process(char c) {
	cout << "Carattere Stampato: " << c << endl;

	try {
		return *events.at(events2char.at(c));
	} catch (const out_of_range& ext) {
		return *(new AbstractEvent<>(-1));
	}
}

void KeyboardHandler::addEvent(AbstractEvent<>::Ptr& event, char input) {
	events.insert(pair<int, AbstractEvent<>::Ptr>(event->getCode(), event));
	events2char.insert(pair<char, int>(input, event->getCode()));
}

int KeyboardHandler::getEventCodeFromInput(char input) const {
	MapCharEvents::const_iterator it = events2char.find(input);
	if (it != events2char.end())
		return it->second;
	else
		return -1;

}
