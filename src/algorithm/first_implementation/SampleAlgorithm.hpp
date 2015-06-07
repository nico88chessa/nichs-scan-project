/*
 * Sample.hpp
 *
 *  Created on: 02/giu/2015
 *      Author: nicola
 */

#ifndef ALGORITHM_FIRST_IMPLEMENTATION_SAMPLEALGORITHM_HPP_
#define ALGORITHM_FIRST_IMPLEMENTATION_SAMPLEALGORITHM_HPP_

#include "../AbstractAlgorithm.hpp"
#include <opencv2/opencv.hpp>

class SampleAlgorithm : public AbstractAlgorithm<cv::Mat, std::vector<cv::Mat> > {
private:
    const int NUM_IMAGES = 10;
public:
    SampleAlgorithm();
    virtual ~SampleAlgorithm();

protected:
    std::vector<cv::Mat> process(const cv::Mat& input);

};

#endif /* ALGORITHM_FIRST_IMPLEMENTATION_SAMPLEALGORITHM_HPP_ */
