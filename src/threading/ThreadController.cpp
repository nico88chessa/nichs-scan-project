/*
 * ThreadController.cpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#include "ThreadController.hpp"

ThreadController::ThreadController(bool startStopped) :
	isEnded(false), isRunning(!startStopped), runStep(false), mode(RUN) {

}

ThreadController::~ThreadController() { }

bool ThreadController::canStep() {
	UniqueLock lock(mutex);
//	while (!isEnded && !isRunning)
	while (waitingCondition())
		cond.wait(lock);

	if (mode==STEP)
		runStep=false;

	return !isEnded;
}

void ThreadController::doStep() {
	UniqueLock lock(mutex);
	mode = STEP;
	runStep = true;
	cond.notify_all();
}

void ThreadController::play() {
	UniqueLock lock(mutex);
	mode = RUN;
	isRunning = true;
	cond.notify_all();
}

void ThreadController::pause() {
	UniqueLock lock(mutex);
	isRunning = false;
}


void ThreadController::stop() {
	UniqueLock lock(mutex);
	isRunning = false;
	isEnded = true;
}

/**
 * WARNING: this method is not Thread Safe! Be careful!
 */
bool ThreadController::waitingCondition() {

	if (!isEnded) {
//		!isEnded && !isRunning
		if (mode == RUN) {
			return !isRunning;
		} else {
			return !runStep;
		}
	} else
		return false;
}
