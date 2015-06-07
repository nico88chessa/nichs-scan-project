/*
 * SampleAlgorithm.cpp
 *
 *  Created on: 07/giu/2015
 *      Author: nicola
 */

#include "SampleAlgorithm.hpp"

std::vector<cv::Mat> SampleAlgorithm::process(const cv::Mat& input) {
    std::vector<cv::Mat> vet;
    for (int i=0; i<NUM_IMAGES; i++) {
        vet.push_back(input.clone());
    }
    usleep(2*1000);
    return vet;
}
