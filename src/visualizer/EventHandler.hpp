/*
 * EventHandler.hpp
 *
 *  Created on: 07/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTHANDLER_HPP_
#define VISUALIZER_EVENTHANDLER_HPP_

template <typename I, typename O>
class EventHandler {

public:
	virtual ~EventHandler() { };

	virtual O& process(I) = 0;

};

#endif /* VISUALIZER_EVENTHANDLER_HPP_ */
