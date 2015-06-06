/*
 * AbstractAlgorithm.hpp
 *
 *  Created on: 02/giu/2015
 *      Author: nicola
 */

#ifndef ALGORITHM_ABSTRACTALGORITHM_HPP_
#define ALGORITHM_ABSTRACTALGORITHM_HPP_

#include <boost/chrono/system_clocks.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

template <typename I, typename O>
class AbstractAlgorithm {

public:
    typedef boost::shared_ptr<const AbstractAlgorithm<I, O> > ConstPtr;
    typedef boost::shared_ptr<AbstractAlgorithm<I, O> > Ptr;

    virtual ~AbstractAlgorithm() { };

    O execute(const I& input) {
        boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
        O output = process(input);
        boost::chrono::system_clock::time_point end = boost::chrono::system_clock::now();
        boost::chrono::milliseconds ms = boost::chrono::duration_cast<boost::chrono::milliseconds>(end - start);
        std::cout << "Execution time: " << ms.count() << std::endl;
        return output;
    }

protected:
    virtual O process(const I& input) = 0;

};

#endif /* ALGORITHM_ABSTRACTALGORITHM_HPP_ */
