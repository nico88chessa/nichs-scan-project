/*
 * OutputContainer.hpp
 *
 *  Created on: 05/mag/2015
 *      Author: nicola
 */

#ifndef UTILITY_OUTPUTCONTAINER_HPP_
#define UTILITY_OUTPUTCONTAINER_HPP_

#include "ImageContainer.hpp"
#include <boost/container/map.hpp>
#include <string>

template <typename T>
class OutputContainer {
	friend class Iterator;

public:
	class Iterator {
	private:
		OutputContainer* outputContainer;
		typename boost::container::map<T, ImageContainer<T>>::iterator current;
	public:
		Iterator(OutputContainer* _outputContainer)
			: outputContainer(_outputContainer), current(_outputContainer->container.begin()) {
		}

		Iterator(const Iterator& _iterator) // copy constructor
			: outputContainer(_iterator.outputContainer), current(_iterator.current) {
		}

		Iterator(Iterator&& _iterator) // movable constructor
			: outputContainer(std::move(_iterator.outputContainer)), current(std::move(_iterator.current)) {
		}

		bool hasNext() const {
			return current != --outputContainer->container.end();
		}

		bool hasPrevious() const {
			return current != outputContainer->container.begin();
		}

		// r is for reference
		const ImageContainer<T>& rnext() {
			typename boost::container::map<T, ImageContainer<T>>::iterator temp = current;
			if (hasNext())
				current++;
			else
				current = outputContainer->container.begin();
			return temp->second;
		}

		ImageContainer<T> next() {
			return rnext();
		}

		// r is for reference
		const ImageContainer<T>& rprevious() {
			typename boost::container::map<T, ImageContainer<T>>::iterator temp = current;
			if (hasPrevious())
				current--;
			else
				current = --outputContainer->container.end();
			return temp->second;
		}

		ImageContainer<T> previous() {
			return rprevious();
		}

		Iterator& operator=(const Iterator& _iterator) {
			if (&_iterator == this)
				return *this;
			outputContainer = _iterator.outputContainer;
			current = _iterator.current;
			return *this;
		}

		Iterator& operator=(Iterator&& _iterator) {
			outputContainer = std::move(_iterator.outputContainer);
			current = std::move(_iterator.current);
			return *this;
		}
	};

private:
	boost::container::map<T, ImageContainer<T>> container;
	const ImageContainer<T> EMPTY;

public:
	OutputContainer() : container(), EMPTY() {
	}

	OutputContainer(const OutputContainer& _outputContainer)
		: container(_outputContainer.container),
		  EMPTY(_outputContainer.EMPTY) {
	}

	OutputContainer(OutputContainer&& _outputContainer)
		: container(std::move(_outputContainer.container)),
		  EMPTY(std::move(_outputContainer.EMPTY)) {
	}

	virtual ~OutputContainer() { };

	bool add(T&& _name, const ImageContainer<T>& _imageContainer)  {
		if (container.count(_name) == 0) {
			container.insert(std::pair<T, ImageContainer<T>>(_name, _imageContainer));
			return true;
		} else
			return false;
	}

	bool add(T&& _name, ImageContainer<T>&& _imageContainer) {
		if (container.count(_name) == 0) {
			container.insert(std::pair<T, ImageContainer<T>>(_name, std::move(_imageContainer)));
			return true;
		} else
			return false;
	}

	const ImageContainer<T>& getImageContainer(T&& name) const {
		try {
			return container.at(name);
		} catch (const std::out_of_range& oor) {
			std::cerr << "Image " << name << " not found." << std::endl;
			return EMPTY;
		}
	}

	OutputContainer::Iterator iterator() {
		return Iterator(this);
	}
};

#endif /* UTILITY_OUTPUTCONTAINER_HPP_ */
