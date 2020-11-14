#pragma once
#include <iostream>
#include "List.h"

template<typename T, int Cap>
class ArrayList : public List<T>{
private:
	T m_list[Cap];
	int size;

public:
	ArrayList() : size(0) {}

	bool IsEmpty() const override {
		return (size == 0);
	}
	int GetSize() const override {
		return size;
	}
	void Clear() override {
		size = 0;
	}
	bool Insert(int index) override {

	}
	bool Remove(int index) override {

	}
	bool Remove(const T& item) override {

	}
	void Replace(int index, const T& item) override {
		m_list[index] = item;
	}
	T GetItem(int index) const override {
		return m_list[index];
	}
};