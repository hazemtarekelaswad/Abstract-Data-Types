#pragma once
#include <iostream>
#include <cassert>
#include "Pair/Pair/Pair.h"
#include "Dictionary.h"

template<typename K, typename T, int capacity>
class ArrayDictionary : public Dictionary<K, T> {
private:
	Pair<K, T> data_[capacity];
	int size_;

public:
	ArrayDictionary() : size_(0) {}

	bool IsEmpty() const override{
		return size_ == 0;
	}
	int GetSize() const override {
		return size_;
	}
	void Clear() override {
		size_ = 0;
	}
	bool Add(const K& key, const T& item) override {
		if (size_ == capacity)
			return false;
		// Find the proper position for the key
		int index = 0;
		while (index < size_ && key >= data_[index].GetKey())
			++index;

		// Shift all items to the right in order to free space for the new pair
		for (int i = size_; i > index; --i)
			data_[i] = data_[i - 1];

		// Shift and find the proper position at the same time
		/*int index = size_;
		while (index > 0 && key < data_[index - 1].GetKey()) {
			data_[index] = data_[index - 1];
			--index;
		}*/

		// Add the new pair to its proper position
		data_[index] = Pair<K, T>(key, item);
		++size_;
		return true;
	}

	bool Remove(const K& key) override {
		if (IsEmpty())
			return false;

		int index = 0;
		while (index < size_ && data_[index].GetKey() != key)
			++index;

		if (index == size_)
			return false;

		for (int i = index + 1; i < size_; ++i)
			data_[i - 1] = data_[i];

		--size_;
		return true;
	}

	T GetItem(const K& key) override {
		int i;
		for (i = 0; i < size_; ++i) {
			if (data_[i].GetKey() == key)
				return data_[i].GetItem();
		}
		assert(i != size_ && "This key is not found!");
	}

	bool Contains(const K& key) override {
		for (int i = 0; i < size_; ++i) {
			if (data_[i].GetKey() == key)
				return true;
		}
		return false;
	}

	std::ostream& Print() const {
		for (int i = 0; i < size_; ++i)
			std::cout << data_[i] << '\n';
		return std::cout;
	}

	virtual ~ArrayDictionary() {}
};