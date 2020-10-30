#pragma once
#include <iostream>
#include <vector>
#include "Bag.h"

template<typename T, int Cap>
class ArrayBag : public Bag<T> {
private:
	T m_bag[Cap];
	int size;

public:
	ArrayBag() : size(0) {}

	int GetSize() const override {
		return size;
	}

	bool IsEmpty() const override {
		return size == 0;
	}

	bool Add(const T& item) override {
		if (size == Cap)
			return false;
		m_bag[size++] = item;
		return true;
	}

	bool Remove(const T& item) override {
		for (int i = 0; i < size; ++i) {
			if (m_bag[i] == item) {
				m_bag[i] = m_bag[size - 1];
				--size;
				return true;
			}
		}
		return false;
	}

	void Clear() override {
		size = 0;
	}

	int GetFrequencyOf(const T& item) const override {
		int count = 0;
		for (int i = 0; i < size; ++i)
			if (m_bag[i] == item)
				++count;
		return count;
	}

	bool Contains(const T& item) const override {
		for (int i = 0; i < size; ++i)
			if (m_bag[i] == item)
				return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayBag& bag) {
		for (int i = 0; i < bag.size; ++i)
			out << bag.m_bag[i] << ' ';
		return out;
	}

	std::vector<T> ToVector() const override {
		std::vector<T> vec(size);
		for (int i = 0; i < size; ++i)
			vec.push_back(m_bag[i]);
		return vec;
	}
};

