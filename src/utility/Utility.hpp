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
#include "../data/Image.hpp"
#include "../data/Container.hpp"

class Utility {
private:
	Utility();
	virtual ~Utility();

public:
	static const char* string2char(const std::string& stringa);

	static short loadImagesFromPath(const std::string& pathFolder, std::vector<cv::Mat>&);

	static short loadImagesFromPath(const std::string& pathFolder, Container<std::string, Image>&);

	static short loadImagesFromList(const std::vector<std::string>& imagesNames, std::vector<cv::Mat>&);

	static short loadImagesFromList(const std::vector<std::string>& imagesNames, Container<std::string, Image>&);

};

#endif /* UTILITY_UTILITY_HPP_ */
