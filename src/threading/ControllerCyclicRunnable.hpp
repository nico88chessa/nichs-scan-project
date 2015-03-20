/*
 * ControllerCyclicRunnable.hpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_CONTROLLERCYCLICRUNNABLE_HPP_
#define THREADING_CONTROLLERCYCLICRUNNABLE_HPP_

#include "ThreadController.hpp"
#include <boost/shared_ptr.hpp>
#include "CyclicRunnable.hpp"

class ControllerCyclicRunnable : public CyclicRunnable {

private:
	ThreadController::ConstPtr threadController;

public:

	typedef ControllerCyclicRunnable * Ptr;
	typedef const ControllerCyclicRunnable * ConstPtr;

	ControllerCyclicRunnable(ThreadController::Ptr controller);

	virtual ~ControllerCyclicRunnable();

	bool hasCycle();

	virtual bool hasNext() = 0;

};

#endif /* THREADING_CONTROLLERCYCLICRUNNABLE_HPP_ */
