/*
 * EventNextImage.hpp
 *
 *  Created on: 26/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_
#define VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_

#include "../AbstractEvent.hpp"
#include "../Visualizer.hpp"
#include "../data/Container.hpp"
#include "Events.hpp"

class PreviousImageEvent : public AbstractEvent<int>{
private:
	Visualizer::ConstPtr vis;
	Container<std::string, Image>::CyclicIterator::Ptr imageScroller;

public:
	PreviousImageEvent(const Visualizer::ConstPtr& _vis, Container<std::string, Image>::CyclicIterator::Ptr _imageScroller):
		AbstractEvent<int>(EVENTS_CODE::PREVIOUS_IMAGE), vis(_vis), imageScroller(_imageScroller) {
	}
	~PreviousImageEvent() {
	}

	void doEvent() {
		cv::Mat&& temp = imageScroller->previous().getImageCopy();
		vis->updateImage(temp);
	}
};

#endif /* VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_ */
