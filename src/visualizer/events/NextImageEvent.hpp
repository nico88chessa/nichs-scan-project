/*
 * EventNextImage.hpp
 *
 *  Created on: 26/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_
#define VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_

#include "../AbstractEvent.hpp"
#include "../Visualizer.hpp"
#include "Events.hpp"

class NextImageEvent : public AbstractEvent<int>{
private:
	Visualizer::ConstPtr vis;
	Container<std::string, Image>::CyclicIterator::Ptr imageScroller;

public:
	NextImageEvent(const Visualizer::ConstPtr& _vis, Container<std::string, Image>::CyclicIterator::Ptr _imageScroller):
		AbstractEvent<int>(EVENTS_CODE::NEXT_IMAGE), vis(_vis), imageScroller(_imageScroller) {
	}
	~NextImageEvent() {
	}

	void doEvent() {
		cv::Mat&& temp = imageScroller->next().getImageCopy();
		vis->updateImage(temp);
	}
};

#endif /* VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_ */
