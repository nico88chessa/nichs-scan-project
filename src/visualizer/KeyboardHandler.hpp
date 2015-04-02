/*
 * KeyboardHandler.hpp
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_KEYBOARDHANDLER_HPP_
#define VISUALIZER_KEYBOARDHANDLER_HPP_

#include "AbstractEvent.hpp"
#include "EventHandler.hpp"
#include "events/EventProva.hpp"
#include <map>
#include <stdexcept>

class KeyboardHandler : public EventHandler<char, AbstractEvent<> > {
public:
	typedef boost::shared_ptr<KeyboardHandler> Ptr;
	typedef std::map<int, AbstractEvent<>::Ptr> MapEvents;
	typedef std::map<char, int> MapCharEvents;

private:
	MapEvents events;
	MapCharEvents events2char;

public:
	KeyboardHandler();
	virtual ~KeyboardHandler();

	AbstractEvent<>& process(char c);

	void addEvent(AbstractEvent<>::Ptr& event, char input);

	int getEventCodeFromInput(char input) const;
};

#endif /* VISUALIZER_KEYBOARDHANDLER_HPP_ */
