#pragma once
#include <iostream>
#include "List.h"

template<typename T>
class LinkedList : public List<T> {
private:
	
	int size;

public:
	LinkedList() : size(0) {}

	bool IsEmpty() const override {
	}
	int GetSize() const override {
	}
	void Clear() override {
	}
	bool Insert(int index, const T& item) override {
	}
	bool RemoveAt(int index) override {
	}
	bool Remove(const T& item) override {
	}

	void Replace(int index, const T& item) override {
	}
	T GetItem(int index) const override {
	}
};