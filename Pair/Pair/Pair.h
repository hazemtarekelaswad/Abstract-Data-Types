#pragma once
#include <iostream>
#include "Defs.h"

template<typename K, typename T>
class Pair {
private:
	K key_;
	T item_;

	Status status_;
	
public:
	Pair() : status_(Status::EMPTY){}
	Pair(const K& key, const T& item) : key_(key), item_(item), status_(Status::OCCUPIED) {}

	void SetStatus(const Status& stat) {
		status_ = stat;
	}

	Status GetStatus() const {
		return status_;
	}

	void SetItem(const T& item) {
		item_ = item;
	}
	K GetKey() const {
		return key_;
	}
	T GetItem() const {
		return item_;
	}
	friend bool operator==(const Pair& pair1, const Pair& pair2) {
		return (pair1.key_ == pair2.key_ && pair1.item_ == pair2.item_);
	}
	friend std::ostream& operator<<(std::ostream& out, const Pair& pair) {
		out << pair.key_ << ' ' << pair.item_ << ' ';
		return out;
	}
};
