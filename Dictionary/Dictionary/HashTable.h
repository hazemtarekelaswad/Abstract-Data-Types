#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include "Defs.h"
#include "Pair/Pair/Pair.h"
#include "Dictionary.h"

template<typename K, typename T, int capacity>
class HashTable : public Dictionary<K, T> {
private:
	Pair<K, T> table_[capacity];
	int size_;
	const Probing probing_;

private:
	// Hash Function that uses modulo algorithm
	int Hash(const K& key) {
		return key % capacity;
	}

public:
	HashTable(const Probing& prob) : size_(0), probing_(prob) {}

	Probing GetProbingType() const {
		return probing_;
	}

	bool IsEmpty() const override {
		return size_ == 0;
	}
	int GetSize() const override {
		return size_;
	}
	void Clear() override {
		// size_ = 0;
	}
	bool Add(const K& key, const T& item) override {
		if (size_ == capacity)
			return false;

		int hashedKey = Hash(key);
		int step = 0;
		while (table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity].GetStatus() == Status::OCCUPIED)
			++step;
		table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity] = Pair<K, T>(key, item);
		++size_;
		return true;
	}

	bool Remove(const K& key) override {
		return false;
	}

	T GetItem(const K& key) override {
		int hashedKey = Hash(key);
		int step = 0;

		while ((table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity]).GetKey() != key
			&& (table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity]).GetStatus() != Status::EMPTY)
			++step;
		
		assert((table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity]).GetStatus() != Status::EMPTY
			&& "This key is not found!");
			
		return (table_[(hashedKey + static_cast<int>(std::pow(step, static_cast<int>(probing_)))) % capacity]).GetItem();
	}

	bool Contains(const K& key) override {
		return false;
	}

	std::ostream& Print() const {
		for (int i = 0; i < capacity; ++i)
			if(table_[i].GetStatus() == Status::OCCUPIED)
				std::cout << table_[i] << '\n';
		return std::cout;
	}

	virtual ~HashTable() {}
};