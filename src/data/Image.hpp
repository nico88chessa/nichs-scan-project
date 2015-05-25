/*
 * Image.hpp
 *
 *  Created on: 22/mag/2015
 *      Author: nicola
 */

#ifndef DATA_IMAGE_HPP_
#define DATA_IMAGE_HPP_

#include <opencv2/opencv.hpp>
#include <string>

class Image {
private:
	cv::Mat image;
	std::string imageName;

public:
	Image() : imageName(), image() {
	}

	Image(const std::string& _imageName, const cv::Mat& _image)
		: imageName(_imageName), image(_image) {
	}

	Image(std::string&& _imageName, cv::Mat&& _image)
		: imageName(std::move(_imageName)), image(std::move(_image)) {
	}

	virtual ~Image() {
	}

	const std::string& getImageName() const {
		return imageName;
	}

	const cv::Mat& getImage() const {
		return image;
	}

	cv::Mat getImageCopy() const {
		return image;
	}

	void setImageName(const std::string& imageName) {
		this->imageName = imageName;
	}

	void setImageName(std::string&& _imageName) {
		std::swap(imageName, _imageName);
	}

	void setImage(const cv::Mat& image) {
		this->image = image;
	}

	void setImage(cv::Mat&& _image) {
		std::swap(image, _image);
	}

};

#endif /* DATA_IMAGE_HPP_ */
