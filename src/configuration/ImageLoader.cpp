/*
 * ImageLoader.cpp
 *
 *  Created on: 10/feb/2015
 *      Author: nicola
 */

#include <ImageLoader.hpp>

using namespace std;
using namespace cv;

ImageLoader::ImageLoader(const std::string& inputFolder) {

}

ImageLoader::ImageLoader(const std::vector<std::string>& inputItems) {

	images = vector<Mat>();

	if (inputItems == NULL)
		return;

	vector<string>::const_iterator it = inputItems.iterator();
	while (it != inputItems.end()) {
		string currentFileName = *it++;
		cv::Mat img = cv::imread(currentFileName);
		images.push_back(img);
	}
}

ImageLoader::~ImageLoader() {
}

const std::vector<cv::Mat>& ImageLoader::getImages() const {
	return images;
}
