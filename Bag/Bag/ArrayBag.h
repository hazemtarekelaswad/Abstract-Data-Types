#pragma once
#include <iostream>
#include <vector>
#include "Bag.h"

template<typename T, int Cap>
class ArrayBag : Bag<T> {
private:
	T m_bag[Cap];
	int size;

public:
	ArrayBag() : size(0) {}

	int GetSize() const {
		return size;
	}

	bool IsEmpty() const {
		return size == 0;
	}

	bool Add(const T& item) {
		if (size == Cap)
			return false;
		m_bag[size++] = item;
		return true;
	}

	bool Remove(const T& item) {
		
	}

	void Clear() {
		size = 0;
	}

	int GetFrequencyOf(const T& item) const {}
	bool Contains(const T& item) const {}
	std::vector<T> ToVector() const {}
};

