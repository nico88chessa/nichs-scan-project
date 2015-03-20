#include <iostream>
#include <boost/thread.hpp>

#include "threading/ControllerCyclicRunnable.hpp"

using namespace std;


class ProvaThread : public ControllerCyclicRunnable {
private:
	int count;

public:

	ProvaThread(ThreadController::Ptr tc) :
		ControllerCyclicRunnable(tc), count(0) {
	}

	~ProvaThread() { };

	void doCycle() {
		cout << "iterazione: " << count++ << endl;
		usleep(500*1000);
	}

	bool hasNext() {
		return true;
	}

};


int main(int argc, char** argv) {

	cout << "Thread ControllerCyclicRunnable" << endl;

	ThreadController::Ptr tc(new ThreadController());
	ProvaThread pt(tc);

	boost::thread th(pt);

	for (int i=0; ; i++) {
		if (i%2==0) {
			tc->pause();
			cout << "Thread Paused" << endl;
		} else {
			tc->play();
			cout << "Thread Restart" << endl;
		}
		sleep(3);
	}

}
