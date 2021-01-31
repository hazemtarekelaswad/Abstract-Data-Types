#pragma once
#include <iostream>
#include <cassert>
#include "Pair/Pair/Pair.h"
#include "Dictionary.h"

template<typename K, typename T, int capacity>
class HashTable : public Dictionary<K, T> {
private:
	Pair<K, T> data_[capacity];
	int size_;

public:
	ArrayDictionary() : size_(0) {}

	bool IsEmpty() const override {
		return size_ == 0;
	}
	int GetSize() const override {
		return size_;
	}
	void Clear() override {
		size_ = 0;
	}
	bool Add(const K& key, const T& item) override {
	
	}

	bool Remove(const K& key) override {
		
	}

	T GetItem(const K& key) override {
	
	}

	bool Contains(const K& key) override {
		
	}

	std::ostream& Print() const {
		for (int i = 0; i < size_; ++i)
			std::cout << data_[i] << '\n';
		return std::cout;
	}

	virtual ~HashTable() {}
};