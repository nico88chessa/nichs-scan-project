/*
 * Visualizer.hpp
 *
 *  Created on: 12/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_VISUALIZER_HPP_
#define VISUALIZER_VISUALIZER_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <boost/shared_ptr.hpp>

class Visualizer {

public:
	typedef boost::shared_ptr<const Visualizer> ConstPtr;
	typedef boost::shared_ptr<Visualizer> Ptr;

private:
	std::string windowName;
	int flags;

public:
	Visualizer(std::string _windowName);
	Visualizer(std::string _windowName, int _flags);
	virtual ~Visualizer();

	virtual void showWindow() const;
	const std::string& getWindowName() const;
	void setWindowName(const std::string& windowName);
	void updateImage(cv::Mat& _image) const;
};

#endif /* VISUALIZER_VISUALIZER_HPP_ */
