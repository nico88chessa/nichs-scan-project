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

	class KeyRunnable: public CyclicRunnable {
	private:
		IOVisualizer* vis;
	public:
		KeyRunnable(IOVisualizer *v): vis(v) { };

		~KeyRunnable() { };

		bool hasCycle() {
//			return vis->keyboardHandler->getEventCodeFromInput(vis->keyPressed) != EVENTS_CODE::EXIT;
			return vis->keyPressed != 'q';
		};

		void doCycle() {
//			std::cout << "Premere un tasto: ";
			vis->keyPressed = cv::waitKey();
			vis->processEvent(vis->keyPressed);
//			std::cout << vis->keyPressed << std::endl;
		};

	} keyRunnable;

	class MouseCallback;
	friend class IOVisualizer::MouseCallback;

	class MouseCallback {
	private:
		IOVisualizer* vis;
	public:
		MouseCallback(IOVisualizer *v): vis(v) { }
		~MouseCallback() { }

		void callback(int event, int x, int y, int flags, void* userdata) {
			vis->keyPressed = event+0x30;
			if (event>0)
				std::cout << vis->keyPressed << std::endl;
			// std::cout << "callback handler" << std::endl;
		}

	} mouseCallback;

	char keyPressed;
	boost::shared_ptr<KeyboardHandler> keyboardHandler;
	// thread safe
	boost::mutex mutex;

	void processEvent(char c);

public:
	IOVisualizer(std::string _windowName);
	IOVisualizer(std::string _windowName, const KeyboardHandler::Ptr& _keyboardHandler);
	IOVisualizer(std::string _windowName, int _flags, const KeyboardHandler::Ptr& _keyboardHandler);
	~IOVisualizer();
	char getKeyPressed() const;

	void setKeyPressed(char keyPressed);

	void callMouse(int event, int x, int y, int flags, void* userdata);

	void show();

};

#endif /* VISUALIZER_IOVISUALIZER_HPP_ */
