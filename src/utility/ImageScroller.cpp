/*
 * ImageScroller.cpp
 *
 *  Created on: 28/mar/2015
 *      Author: nicola
 */

#include "ImageScroller.hpp"

using namespace std;
using namespace cv;

ImageScroller::ImageScroller(const vector<Mat>& _images): images(_images) {
	iterator = images.begin();
}

ImageScroller::ImageScroller(const ImageScroller& _imageScroller): images(_imageScroller.images) {
	iterator = images.begin();
}

bool ImageScroller::hasNext() {
	vector<Mat>::const_iterator temp = iterator;
	return ++temp != images.end();
}

bool ImageScroller::hasPrevious() const {
	vector<Mat>::const_iterator temp = iterator;
	return --temp != images.begin();
}

ImageScroller::~ImageScroller() {
}

const cv::Mat& ImageScroller::next() {
	if (hasNext())
		iterator++;
	else
		iterator = images.begin();
	return *iterator;
}

const cv::Mat& ImageScroller::previos() {
	if (hasPrevious())
		iterator--;
	else
		iterator = images.end();
	return *iterator;
}
