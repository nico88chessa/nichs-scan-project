/*
 * CyclicRunnable.h
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_CYCLICRUNNABLE_HPP_
#define THREADING_CYCLICRUNNABLE_HPP_

#include "Runnable.hpp"

class CyclicRunnable: public Runnable {
public:

	virtual ~CyclicRunnable();

	virtual bool hasCycle() = 0;

	virtual void doCycle() = 0;

	virtual void doBeforeCycle();

	virtual void doAfterCycle();

	void run();

};

#endif /* THREADING_CYCLICRUNNABLE_HPP_ */
