/*
 * ImageContainer.hpp
 *
 *  Created on: 03/mag/2015
 *      Author: nicola
 */

#ifndef UTILITY_IMAGECONTAINER_HPP_
#define UTILITY_IMAGECONTAINER_HPP_

#include <opencv2/core/core.hpp>
#include <boost/container/map.hpp>
#include <string>
#include <iostream>

template <typename T = std::string>
class ImageContainer {
	friend class Iterator;

public:
	class Iterator {
	private:
		ImageContainer* imageContainer;
		typename boost::container::map<T, cv::Mat>::iterator current;

	public:
		Iterator() : imageContainer(NULL) {
		}

		Iterator(ImageContainer* _imageContainer)
			: imageContainer(_imageContainer), current(_imageContainer->container.begin()) {
		}

		Iterator(const Iterator& _iterator) // copy constructor
			: imageContainer(_iterator.imageContainer), current(_iterator.current) {
		}

		Iterator(Iterator&& _iterator) // movable constructor
			: imageContainer(_iterator.imageContainer), current(std::move(_iterator.current)) {
			_iterator.imageContainer = NULL;
		}

		Iterator& operator=(const Iterator& _iterator) {
			if (&_iterator == this)
				return *this;
			imageContainer = _iterator.imageContainer;
			current = _iterator.current;
			return *this;
		}

		Iterator& operator=(Iterator&& _iterator) {
			imageContainer = move(_iterator.imageContainer);
			current = move(_iterator.current);
			return *this;
		}

		bool hasNext() const {
			return current != --imageContainer->container.end();
		}

		bool hasPrevious() const {
			return current != imageContainer->container.begin();
		}

		// r is reference
		const cv::Mat& rnext()  {
			typename boost::container::map<T, cv::Mat>::iterator temp = current;
			if (hasNext())
				current++;
			else
				current = imageContainer->container.begin();
			return temp->second;
		}

		cv::Mat next() {
			return rnext();
		}

		const cv::Mat& rprevious() {
			typename boost::container::map<T, cv::Mat>::iterator temp = current;
			if (hasPrevious())
				current--;
			else
				current = ++imageContainer->container.rbegin().base();
			return temp->second;
		}

		cv::Mat previous() {
			return rprevious();
		}

		// r for reference
		const cv::Mat& rat(T&& name) {
			return getImage(name);
		}

		cv::Mat at(T&& name) {
			return getImage(name);
		}

		T getName() {
			return current->first;
		}
	};

private:
	const cv::Mat EMPTY;
	boost::container::map<T, cv::Mat> container;

public:
	ImageContainer() : container(), EMPTY() {
	}

	virtual ~ImageContainer() {
	}

	ImageContainer(const ImageContainer& _imageContainer)
		: EMPTY(), container(_imageContainer.container) {
	}

	ImageContainer(ImageContainer&& _imageContainer)
		: EMPTY(std::move(_imageContainer.EMPTY)), container(std::move(_imageContainer.container)) {
	}

	bool add(T&& name, const cv::Mat& image) {
		if (container.count(name) == 0) {
			container.insert(std::pair<T, cv::Mat>(name, image));
			return true;
		} else
			return false;
	}

	bool add(T&& name, cv::Mat&& image) {
		if (container.count(name) == 0) {
			container.insert(std::pair<T, cv::Mat>(name, std::move(image)));
			return true;
		} else
			return false;
	}

	const cv::Mat& getImage(T&& name) const {
		try {
			return container.at(name);
		} catch (const std::out_of_range& oor) {
			std::cerr << "Image " << name << " not found." << std::endl;
			return EMPTY;
		}
	}

	Iterator iterator() {
		return ImageContainer<T>::Iterator(this);
	}

};

#endif /* UTILITY_IMAGECONTAINER_HPP_ */
