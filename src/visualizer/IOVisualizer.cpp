/*
 * IOVisualizer.cpp
 *
 *  Created on: 22/mar/2015
 *      Author: nicola
 */

#include "IOVisualizer.hpp"

using namespace std;
using namespace cv;

IOVisualizer::IOVisualizer(std::string _windowName):
	Visualizer(_windowName), keyRunnable(this), mouseCallback(this), keyboardHandler() {
	showWindow();
	setMouseCallback(_windowName, callback, this);
	keyListener = boost::thread(boost::ref(keyRunnable));
}

IOVisualizer::IOVisualizer(std::string _windowName, const KeyboardHandler::Ptr& _keyboardHandler):
	Visualizer(_windowName), keyRunnable(this), mouseCallback(this), keyboardHandler(_keyboardHandler) {
	showWindow();
	setMouseCallback(_windowName, callback, this);
	keyListener = boost::thread(boost::ref(keyRunnable));
};

IOVisualizer::IOVisualizer(std::string _windowName, int _flags, const KeyboardHandler::Ptr& _keyboardHandler):
	Visualizer(_windowName, _flags), keyRunnable(this), mouseCallback(this), keyboardHandler(_keyboardHandler) {
	showWindow();
	setMouseCallback(_windowName, callback, this);
	keyListener = boost::thread(boost::ref(keyRunnable));
}

IOVisualizer::~IOVisualizer() {
}


void IOVisualizer::processEvent(char c) const {
	UniqueLock(mutex);
	keyboardHandler.get()->process(c).doEvent();
}


void callback(int event, int x, int y, int flags, void* userdata) {
	IOVisualizer *v = (IOVisualizer*) userdata;
	v->callMouse(event, x, y, flags, userdata);
}

void IOVisualizer::callMouse(int event, int x, int y, int flags, void* userdata) {
	mouseCallback.callback(event, x, y, flags, userdata);
}

void IOVisualizer::wait() {
	keyListener.join();
}
