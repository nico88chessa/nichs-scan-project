/*
 * ImageLoader.hpp
 *
 *  Created on: 10/feb/2015
 *      Author: nicola
 */

#ifndef CONFIGURATION_IMAGELOADER_HPP_
#define CONFIGURATION_IMAGELOADER_HPP_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <boost/filesystem.hpp>

class ImageLoader {
private:
	std::vector<cv::Mat> images;
public:
	ImageLoader(const std::string& inputFolder);
	ImageLoader(const std::vector<std::string>& inputItems);
	~ImageLoader();

	const std::vector<cv::Mat>& getImages() const;
};

#endif /* CONFIGURATION_IMAGELOADER_HPP_ */
