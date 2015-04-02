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
	keyPressed = '0';
}

IOVisualizer::IOVisualizer(std::string _windowName, const KeyboardHandler::Ptr& _keyboardHandler):
	Visualizer(_windowName), keyRunnable(this), mouseCallback(this), keyboardHandler(_keyboardHandler) {

	keyPressed = '0';
};

IOVisualizer::IOVisualizer(std::string _windowName, int _flags, const KeyboardHandler::Ptr& _keyboardHandler):
	Visualizer(_windowName, _flags), keyRunnable(this), mouseCallback(this), keyboardHandler(_keyboardHandler) {
	keyPressed = '0';
}

IOVisualizer::~IOVisualizer() {
}

char IOVisualizer::getKeyPressed() const {
	return keyPressed;
}

void IOVisualizer::processEvent(char c) {
	UniqueLock(mutex);
	keyboardHandler.get()->process(c).doEvent();
}

void IOVisualizer::setKeyPressed(char keyPressed) {
	this->keyPressed = keyPressed;
}

void callback(int event, int x, int y, int flags, void* userdata) {
//	std::cout << "callback handler" << std::endl;
	IOVisualizer *v = (IOVisualizer*) userdata;
	v->callMouse(event, x, y, flags, userdata);
}

void IOVisualizer::callMouse(int event, int x, int y, int flags, void* userdata) {
	mouseCallback.callback(event, x, y, flags, userdata);
}

void IOVisualizer::show() {
	setMouseCallback(getWindowName(), callback, this);
	showWindow();
	keyRunnable.run();
}
