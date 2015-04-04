/*
 * Utility.hpp
 *
 *  Created on: 17/gen/2015
 *      Author: nicola
 */

#ifndef UTILITY_UTILITY_HPP_
#define UTILITY_UTILITY_HPP_

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <boost/filesystem.hpp>

class Utility {
private:
	Utility();
	virtual ~Utility();

public:
	static const char* string2char(const std::string& stringa);

	static std::vector<cv::Mat> loadImagesFromPath(const std::string& pathFolder);

	static std::vector<cv::Mat> loadImagesFromList(const std::vector<std::string>& imagesNames);
};

#endif /* UTILITY_UTILITY_HPP_ */
