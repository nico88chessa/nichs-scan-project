/*
 * ExitEvent.hpp
 *
 *  Created on: 07/apr/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_ExitEvent_HPP_
#define VISUALIZER_EVENTS_ExitEvent_HPP_

#include "../AbstractEvent.hpp"
#include "Events.hpp"

class ExitEvent : public AbstractEvent<int>{
public:
	ExitEvent(const Visualizer::ConstPtr& _vis, ImageScroller::Ptr _imageScroller):
		AbstractEvent<int>(EVENTS_CODE::EXIT) {
	}

	~ExitEvent() {
	}

	void doEvent() {
		// do nothing
	}
};

#endif /* VISUALIZER_EVENTS_EXITEVENT_HPP_ */
