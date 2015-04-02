/*
 * Visualizer.cpp
 *
 *  Created on: 12/mar/2015
 *      Author: nicola
 */

#include "Visualizer.hpp"

using namespace std;
using namespace cv;

Visualizer::Visualizer(std::string _windowName) : windowName(_windowName) {
	flags = CV_WINDOW_NORMAL;
	cout << "ok" << endl;

}

Visualizer::Visualizer(std::string _windowName, int _flags) :
		windowName(_windowName), flags(_flags) {
}

Visualizer::~Visualizer() {
	destroyWindow(windowName);
}

void Visualizer::showWindow() const {
	namedWindow(windowName, flags);
	waitKey(1); // delay 1ms per mostrare la finestra
	cout << "win creata" << endl;
}

const std::string& Visualizer::getWindowName() const {
	return windowName;
}

void Visualizer::setWindowName(const std::string& windowName) {
	this->windowName = windowName;
}

void Visualizer::updateImage(cv::Mat& _image) const {
	imshow(windowName, _image);
}
