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
	iterator = images.end()-1;
}

ImageScroller::ImageScroller(vector<Mat>&& _images): images(std::move(_images)) {
	iterator = images.end()-1;
}

ImageScroller::ImageScroller(const ImageScroller& _imageScroller):
		images(_imageScroller.images), iterator(_imageScroller.iterator) {
}

ImageScroller::ImageScroller(ImageScroller&& _imageScroller):
		images(std::move(_imageScroller.images)),
		iterator(std::move(_imageScroller.iterator)) {
}

bool ImageScroller::hasNext() {
	return iterator != (images.end()-1);
}

bool ImageScroller::hasPrevious() const {
	return iterator != images.begin();
}

ImageScroller::~ImageScroller() {
}

const cv::Mat& ImageScroller::next() {
	if (hasNext())
		iterator++;
	else
		iterator = images.begin();
	vector<Mat>::const_iterator temp = iterator;
	return *temp;
}

const cv::Mat& ImageScroller::previos() {
	if (hasPrevious())
		iterator--;
	else
		iterator = (images.end()-1);
	vector<Mat>::const_iterator temp = iterator;
	return *temp;
}
