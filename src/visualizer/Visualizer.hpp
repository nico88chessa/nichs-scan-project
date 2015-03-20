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

class Visualizer {
private:
	std::string windowName;
	int flags;
public:
	Visualizer(std::string _windowName);
	Visualizer(std::string _windowName, int _flags);
	virtual ~Visualizer();

	void showWindow() const;
};

#endif /* VISUALIZER_VISUALIZER_HPP_ */
