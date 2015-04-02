/*
 * EventNextImage.hpp
 *
 *  Created on: 26/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_
#define VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_

#include "AbstractEvent.hpp"
#include "Visualizer.hpp"
#include "ImageScroller.hpp"

class NextImageEvent : public AbstractEvent<int>{
private:
	Visualizer::ConstPtr vis;
	ImageScroller imageScroller;

public:
	// 10 e' per prova
	NextImageEvent(const Visualizer::ConstPtr& _vis, const ImageScroller& _imageScroller):
		AbstractEvent<int>(10), vis(_vis), imageScroller(_imageScroller) {
	}
	~NextImageEvent() {
	}

	void doEvent() {
		cv::Mat temp = imageScroller.next().clone();
		vis->updateImage(temp);
	}
};

#endif /* VISUALIZER_EVENTS_NEXTIMAGEEVENT_HPP_ */
