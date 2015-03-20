/*
 * ControllerCyclicRunnable.cpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#include "ControllerCyclicRunnable.hpp"

ControllerCyclicRunnable::ControllerCyclicRunnable(ThreadController::Ptr controller):
	threadController(controller) {
}

ControllerCyclicRunnable::~ControllerCyclicRunnable() {
}

bool ControllerCyclicRunnable::hasCycle() {
	return threadController->canStep() && hasNext();
}
