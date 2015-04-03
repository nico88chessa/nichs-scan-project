/*
 * EventNextImage.hpp
 *
 *  Created on: 26/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_
#define VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_

#include "AbstractEvent.hpp"
#include "Visualizer.hpp"
#include "ImageScroller.hpp"

class PreviousImageEvent : public AbstractEvent<int>{
private:
	Visualizer::ConstPtr vis;
	ImageScroller::Ptr imageScroller;

public:
	// 11 e' per prova
	PreviousImageEvent(const Visualizer::ConstPtr& _vis, ImageScroller::Ptr _imageScroller):
		AbstractEvent<int>(11), vis(_vis), imageScroller(_imageScroller) {
	}
	~PreviousImageEvent() {
	}

	void doEvent() {
		cv::Mat temp = (*imageScroller).previos().clone();
		vis->updateImage(temp);
	}
};

#endif /* VISUALIZER_EVENTS_PREVIOUSIMAGEEVENT_HPP_ */
