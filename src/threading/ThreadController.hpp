/*
 * ThreadController.hpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#ifndef THREADING_THREADCONTROLLER_HPP_
#define THREADING_THREADCONTROLLER_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

class ThreadController {
private:
	typedef boost::unique_lock<boost::mutex> UniqueLock;

	enum RunningMode {RUN, STEP};

	boost::mutex mutex;
	boost::condition_variable cond;
	bool isRunning, isEnded, runStep;
	RunningMode mode;

	bool waitingCondition();


public:
	typedef boost::shared_ptr<ThreadController> Ptr;
	typedef const boost::shared_ptr<ThreadController> ConstPtr;

	ThreadController(bool _startStopped = false);

	virtual ~ThreadController();

	bool canStep();

	void play();

	void pause();

	void stop();

	void doStep();

};

#endif /* THREADING_THREADCONTROLLER_HPP_ */
