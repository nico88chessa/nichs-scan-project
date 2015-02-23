/*
 * ControllerCyclicRunnable.hpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_CONTROLLERCYCLICRUNNABLE_HPP_
#define THREADING_CONTROLLERCYCLICRUNNABLE_HPP_

#include <CyclicRunnable.h>
#include <ThreadController.hpp>
#include <boost/shared_ptr.hpp>

class ControllerCyclicRunnable : public CyclicRunnable {

private:
	ThreadController::ConstPtr threadController;

public:

	typedef ControllerCyclicRunnable * Ptr;
	typedef const ControllerCyclicRunnable * ConstPtr;

	ControllerCyclicRunnable(ThreadController::ConstPtr controller);

	virtual ~ControllerCyclicRunnable();

	bool ControllerCyclicRunnable::hasCycle();

};

#endif /* THREADING_CONTROLLERCYCLICRUNNABLE_HPP_ */
