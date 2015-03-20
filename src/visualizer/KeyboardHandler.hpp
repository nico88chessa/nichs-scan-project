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
#include <boost/shared_ptr.hpp>
#include <map>

class KeyboardHandler : public EventHandler<char, AbstractEvent<> > {
private:
	typedef boost::shared_ptr<AbstractEvent<> > AbstractEventPtr;
public:
	typedef std::map<int, AbstractEventPtr> MapEvents;
	typedef std::map<char, int> MapCharEvents;

private:

	MapEvents events;
	MapCharEvents events2char;

public:
	KeyboardHandler();
	virtual ~KeyboardHandler();

	AbstractEvent<>& process(char c);
};

#endif /* VISUALIZER_KEYBOARDHANDLER_HPP_ */
