/*
 * CyclicRunnable.h
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_CYCLICRUNNABLE_H_
#define THREADING_CYCLICRUNNABLE_H_

#include "Runnable.hpp"

class CyclicRunnable: public Runnable {
public:

	CyclicRunnable();

	virtual ~CyclicRunnable();

	virtual bool hasNext() = 0;

	virtual bool hasCycle() = 0;

	virtual void doCycle() = 0;

	virtual void doBeforeCycle();

	virtual void doAfterCycle();

	void run();

};

#endif /* THREADING_CYCLICRUNNABLE_H_ */
