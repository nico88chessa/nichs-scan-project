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

ImageScroller::ImageScroller(vector<Mat>&& _images): images(std::move(_images)) {
	iterator = images.begin();
}

ImageScroller::ImageScroller(const ImageScroller& _imageScroller):
		images(_imageScroller.images), iterator(_imageScroller.iterator) {
}

ImageScroller::ImageScroller(ImageScroller&& _imageScroller):
		images(std::move(_imageScroller.images)),
		iterator(std::move(_imageScroller.iterator)) {
}

bool ImageScroller::hasNext() {
	return iterator != images.end();
}

bool ImageScroller::hasPrevious() const {
	return iterator != images.begin();
}

ImageScroller::~ImageScroller() {
}

const cv::Mat& ImageScroller::next() {
	vector<Mat>::const_iterator temp = iterator;
	iterator++;
	if (!hasNext())
		iterator = images.begin();
	return *temp;
}

const cv::Mat& ImageScroller::previos() {
	vector<Mat>::const_iterator temp = iterator;
	if (hasPrevious())
		iterator--;
	else
		iterator = (images.end()-1);
	return *temp;
}
