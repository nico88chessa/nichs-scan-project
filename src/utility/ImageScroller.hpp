/*
 * ImageScroller.hpp
 *
 *  Created on: 28/mar/2015
 *      Author: nicola
 */

#ifndef UTILITY_IMAGESCROLLER_HPP_
#define UTILITY_IMAGESCROLLER_HPP_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <opencv2/core/core.hpp>
#include <utility>

class ImageScroller {
public:
	typedef boost::shared_ptr<ImageScroller> Ptr;
	typedef boost::shared_ptr<const ImageScroller> ConstPtr;

private:
	std::vector<cv::Mat> images;
	std::vector<cv::Mat>::const_iterator iterator;
	bool hasNext();
	bool hasPrevious() const;

public:
	ImageScroller(const std::vector<cv::Mat>& _images);
	ImageScroller(std::vector<cv::Mat>&& _images);
	ImageScroller(const ImageScroller& _imageScroller);
	ImageScroller(ImageScroller&& _imageScroller);
	virtual ~ImageScroller();

	const cv::Mat& next();
	const cv::Mat& previos();

};

#endif /* UTILITY_IMAGESCROLLER_HPP_ */
