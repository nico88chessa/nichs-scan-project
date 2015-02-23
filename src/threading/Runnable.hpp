/*
 * Runnable.hpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_RUNNABLE_HPP_
#define THREADING_RUNNABLE_HPP_

class Runnable {
public:

	virtual void run() = 0;

	virtual ~Runnable();

	/**
	 * Not override!!!
	 * This is useful for Boost::Thread libraries
	 */
	void operator()() {
		run();
	}

};



#endif /* THREADING_RUNNABLE_HPP_ */
