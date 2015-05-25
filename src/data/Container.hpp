/*
 * Container.hpp
 *
 *  Created on: 03/mag/2015
 *      Author: nicola
 */

#ifndef DATA_CONTAINER_HPP_
#define DATA_CONTAINER_HPP_

#include <boost/container/map.hpp>

template <typename K, typename T>
class Container {
public:
	typedef Container<K, T>* Ptr;
	typedef const Container<K, T>* ConstPtr;
	friend class CyclicIterator;

	class CyclicIterator {
	private:
		typedef typename boost::container::map<K, T>::const_iterator MapIterator;
		Container::ConstPtr ptr;
		MapIterator current;

	public:
		CyclicIterator() : ptr(new Container<K, T>()), current(ptr->buffer.end()) {
		}

		CyclicIterator(Container::ConstPtr _ptr) : ptr(_ptr), current(ptr->buffer.end()) {
		}

		CyclicIterator(const CyclicIterator& _iterator)
			: current(_iterator.current), ptr(_iterator.ptr) {
		}

		CyclicIterator(CyclicIterator&& _iterator)
			: current(std::move(_iterator.current)), ptr(_iterator.ptr) {
		}

		virtual ~CyclicIterator() {
		}

		CyclicIterator& operator=(CyclicIterator&& _iterator) {
			this->ptr = std::move(_iterator.ptr);
			this->current = std::move(_iterator.current);
			return *this;
		}

		CyclicIterator& operator=(const CyclicIterator& _iterator) {
			this->ptr = _iterator.ptr;
			this->current = _iterator.current;
			return *this;
		}

		// return true iif current is last item
		bool hasNext() const {
			return current != --ptr->buffer.end();
		}

		bool hasPrevious() const {
			return current != ptr->buffer.begin();
		}

		const T& next() {
			if (current == ptr->buffer.end())
				current = ptr->buffer.begin();
			else {
				if (hasNext())
					current++;
				else
					current = ptr->buffer.begin();
			}
			return current->second;
		}

		const T& previous() {
			if (current == ptr->buffer.end())
				current = --ptr->buffer.end();
			else {
				if (hasPrevious())
					current--;
				else
					current = --ptr->buffer.end();
			}
			return current->second;
		}

		const T& at(const K& key) {
			current = ptr->buffer.find(key);
			return current->second;
		}

	};

private:
	boost::container::map<K, T> buffer;

public:
	Container() : buffer() {
	}

	virtual ~Container() {
	}

	Container(const Container& _Container)
		: buffer(_Container.buffer) {
	}

	Container(Container&& _Container)
		: buffer(std::move(_Container.buffer)) {
	}

	template <typename U, typename V>
	bool add(U&& key, V&& value) {
		if (buffer.count(key) == 0) {
			buffer.insert(std::make_pair<U,V>(std::forward<U>(key), std::forward<V>(value)));
			return true;
		} else
			return false;
	}

	const T& getValue(K&& key) const {
		try {
			return buffer.at(key);
		} catch (const std::out_of_range& oor) {
			std::cerr << "Item with key: " << key << " not found." << std::endl;
		}
		return K();
	}

//	std::vector<K> getKeys() const {
//		std::vector<K> keys;
//		typename boost::container::map<K, T>::iterator it;
//		for (it = buffer.begin(); it != buffer.end(); it++)
//			keys.push_back(it->first);
//		return keys;
//	}

	std::vector<T> getValues() const {
		std::vector<T> values;
		typename boost::container::map<K, T>::const_iterator it = buffer.cbegin();
		for (; it != buffer.cend(); it++)
			values.push_back(it->second);
		return values;
	}

	CyclicIterator iterator() const {
		return CyclicIterator(this);
	}

	int size() const {
		return buffer.size();
	}
};

#endif /* DATA_CONTAINER_HPP_ */
