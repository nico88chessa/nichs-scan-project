/*
 * ImageUtils.hpp
 *
 *  Created on: 25/apr/2015
 *      Author: nicola
 */

#ifndef UTILITY_IMAGEUTILS_HPP_
#define UTILITY_IMAGEUTILS_HPP_

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/types_c.h>
#include <qimage.h>

class ImageUtils {
public:

	/**
	 * cv (BGR) | qt (RGB)
	 * 8UC4		| ARGB32
	 * 8UC3		| RGB888
	 * 8UC1		| Indexed8
	 */

	static QImage cv2Qimage(const cv::Mat& cvImage);
	static QImage cv2Qimage(const cv::Mat* cvImage);
	static cv::Mat qimage2cv(const QImage& qimage);
	static cv::Mat qimage2cv(const QImage* qimage);

};

#endif /* UTILITY_IMAGEUTILS_HPP_ */
