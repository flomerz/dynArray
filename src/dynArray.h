/*
 * dynArray.h
 *
 *  Created on: Nov 27, 2014
 *      Author: flo
 */

#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <vector>

template<typename T> class dynArray {
	using array_type=std::vector<T>;
	array_type array { };
public:
	using size_type = typename array_type::size_type;
	using iterator = typename array_type::iterator;
	using const_iterator = typename array_type::const_iterator;
	using reverse_iterator = typename array_type::reverse_iterator;
	using const_reverse_iterator = typename array_type::const_reverse_iterator;

	dynArray() = default;
	dynArray(std::initializer_list<T> list) :
			array { list } {
	}
	dynArray(size_type n, T const &v) :
			array(n, v) {
	}
	template<typename ITER>
	dynArray(ITER begin, ITER end) :
			array { begin, end } {
	}

	T & at(int index) {
		if (index >= 0)
			return array.at(index);
		else
			return array.at(size() + index);
	}
	T const & at(int index) const {
		if (index >= 0)
			return array.at(index);
		else
			return array.at(size() + index);
	}

	T& operator[](int index) {
		return at(index);
	}
	T const& operator[](int index) const {
		return at(index);
	}

	size_type size() const {
		return array.size();
	}
	bool empty() const {
		return array.empty();
	}

	void push_back(T const & t) {
		array.push_back(t);
	}
	void pop_back() {
		array.pop_back();
	}

	T const & front() const {
		return array.front();
	}
	T & front() {
		return array.front();
	}
	T const& back() const {
		return array.back();
	}
	T & back() {
		return array.back();
	}

	iterator begin() {
		return array.begin();
	}
	iterator end() {
		return array.end();
	}
	const_iterator begin() const {
		return array.begin();
	}
	const_iterator end() const {
		return array.end();
	}
	reverse_iterator rbegin() {
		return array.rbegin();
	}
	reverse_iterator rend() {
		return array.rend();
	}
	const_reverse_iterator rbegin() const {
		return array.rbegin();
	}
	const_reverse_iterator rend() const {
		return array.rend();
	}
	const_iterator cbegin() const {
		return array.cbegin();
	}
	const_iterator cend() const {
		return array.cend();
	}
	const_reverse_iterator crbegin() const {
		return array.crbegin();
	}
	const_reverse_iterator crend() const {
		return array.crend();
	}

	void resize(size_type newsize) {
		array.resize(newsize);
	}

	iterator erase(iterator pos) {
		return array.erase(pos);
	}
	const_iterator erase(const_iterator pos) {
		return array.erase(pos);
	}
	iterator erase(iterator first, iterator last) {
		return array.erase(first, last);
	}
	const_iterator erase(const_iterator first, const_iterator last) {
		return array.erase(first, last);
	}
};

template<typename T>
dynArray<T> makeDynArray(std::initializer_list<T> l) {
	return dynArray<T>(l);
}

#endif /* DYNARRAY_H_ */
