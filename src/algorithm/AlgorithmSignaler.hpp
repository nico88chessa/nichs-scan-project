/*
 * AlgorithmSignaler.hpp
 *
 *  Created on: 05/giu/2015
 *      Author: nicola
 */

#ifndef ALGORITHM_ALGORITHMSIGNALER_HPP_
#define ALGORITHM_ALGORITHMSIGNALER_HPP_

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

#include <vector>

template <typename R>
class AlgorithmSignaler {
private:
    mutable boost::mutex mutex;
    mutable boost::condition_variable cond;

    typedef boost::unique_lock<boost::mutex> UniqueLock;

    std::vector<R> results;
    bool ended;

private:
    bool isEnded() {
        return ended == false;
    }

public:

    typedef boost::shared_ptr<AlgorithmSignaler> Ptr;
    typedef boost::shared_ptr<const AlgorithmSignaler> ConstPtr;

    AlgorithmSignaler() : results(), ended(false) {
    }

    virtual ~AlgorithmSignaler() {
    }

    void addResult(const R& result, bool isEnd = false) {
        UniqueLock lock(mutex);
        results.push_back(result);
        ended = isEnd;
        cond.notify_all();
    }

    std::vector<R> getResults(const R& result) {
        UniqueLock lock(mutex);

        if (results.empty && !isEnded())
            cond.wait(lock);

        std::vector<R> temp;
        if (!isEnded()) {
            results.swap(temp);
            results.empty();
        }
        return temp;
    }

};

#endif /* ALGORITHM_ALGORITHMSIGNALER_HPP_ */
