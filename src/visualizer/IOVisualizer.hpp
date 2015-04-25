/*
 * IOVisualizer.hpp
 *
 *  Created on: 22/mar/2015
 *      Author: nicola
 */

#ifndef VISUALIZER_IOVISUALIZER_HPP_
#define VISUALIZER_IOVISUALIZER_HPP_

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_types.hpp>

#include "Visualizer.hpp"
#include "../threading/CyclicRunnable.hpp"
#include "events/Events.hpp"
#include "KeyboardHandler.hpp"

static void callback(int event, int x, int y, int flags, void* userdata);

class IOVisualizer: public Visualizer {
	typedef boost::unique_lock<boost::mutex> UniqueLock;

public:
	typedef boost::shared_ptr<const IOVisualizer> ConstPtr;
	typedef boost::shared_ptr<IOVisualizer> Ptr;

private:
	// KeyRunnable definition
	class KeyRunnable;
	// friend keyword let outer class members' access by inner class
	friend class IOVisualizer::KeyRunnable; // this is no longer valid for recent g++ specification

	mutable class KeyRunnable: public CyclicRunnable {
	private:
		char keyPressed;
		const IOVisualizer* vis;
	public:
		KeyRunnable(const IOVisualizer *v): vis(v), keyPressed(0) { };

		~KeyRunnable() { };

		bool hasCycle() {
			return vis->keyboardHandler->getEventCodeFromInput(keyPressed) != EVENTS_CODE::EXIT;
		};

		void doCycle() {
			std::cout << "Window: " << vis->getWindowName() << std::endl;
			keyPressed = cv::waitKey();
			vis->processEvent(keyPressed);
		};

	} keyRunnable;

	class MouseCallback;
	friend class IOVisualizer::MouseCallback;

	class MouseCallback {
	private:
		const IOVisualizer* vis;
		char mousePressed;
	public:
		MouseCallback(const IOVisualizer *v): vis(v), mousePressed(0) { }
		~MouseCallback() { }

		void callback(int event, int x, int y, int flags, void* userdata) {
			mousePressed = event+0x30;
			std::cout << "callback handler" << mousePressed << std::endl;
			if (event>0)
				std::cout << mousePressed << std::endl;
		}

	} mouseCallback;

	boost::shared_ptr<KeyboardHandler> keyboardHandler;
	// thread safe
	mutable boost::mutex mutex;
	boost::thread keyListener;

	void processEvent(char c) const;

public:
	IOVisualizer(std::string _windowName);
	IOVisualizer(std::string _windowName, const KeyboardHandler::Ptr& _keyboardHandler);
	IOVisualizer(std::string _windowName, int _flags, const KeyboardHandler::Ptr& _keyboardHandler);
	~IOVisualizer();

	void callMouse(int event, int x, int y, int flags, void* userdata);
	void wait();
	void run();
};

#endif /* VISUALIZER_IOVISUALIZER_HPP_ */
