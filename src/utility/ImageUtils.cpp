/*
 * ImageUtils.cpp
 *
 *  Created on: 25/apr/2015
 *      Author: nicola
 */

#include "ImageUtils.hpp"

QImage ImageUtils::cv2Qimage(const cv::Mat& cvImage) {
	int imageType = cvImage.type();

	switch (imageType) {
	case CV_8UC1:
		return QImage();
	case CV_8UC3: {
		QImage image = QImage(cvImage.data, cvImage.cols, cvImage.rows, cvImage.step, QImage::Format_RGB888);
//		image = QImage("../samples/3a.jpg");
		return image.rgbSwapped();
	}
	case CV_8UC4:
	default:
		break;
	}
	return QImage();

}

QImage ImageUtils::cv2Qimage(const cv::Mat* cvImage) {
	if (cvImage!=NULL)
		return QImage();
	else
		return cv2Qimage(*cvImage);
}

cv::Mat ImageUtils::qimage2cv(const QImage& qimage) {
	return cv::Mat();
}

cv::Mat ImageUtils::qimage2cv(const QImage* qimage) {
	if (qimage==NULL) {
		return cv::Mat();
	}
	else
		return qimage2cv(*qimage);
}
