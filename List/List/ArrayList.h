#pragma once
#include <iostream>
#include "List.h"

template<typename T, int capacity>
class ArrayList : public List<T> {
private:
	T m_list[capacity];
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
	bool Insert(int index, const T& item) override {
		if (size == capacity || index < 0 || index > size)
			return false;

		for (int i = size - 1; i >= index; --i)
			m_list[i + 1] = m_list[i];
		m_list[index] = item;
		++size;
		return true;
	}
	bool RemoveAt(int index) override {
		if (index < 0 || index >= size)
			return false;

		for (int i = index; i < size - 1; ++i)
			m_list[i] = m_list[i + 1];
		--size;
		return true;

	}
	bool Remove(const T& item) override {
		for (int i = 0; i < size; ++i) {
			if (m_list[i] == item) {
				for (int j = i; j < size - 1; ++j)
					m_list[j] = m_list[j + 1];
				--size;
				return true;
			}
		}
		return false;
	}

	void Replace(int index, const T& item) override {
		if (index < 0 || index >= size)
			return;
		m_list[index] = item;
	}
	T GetItem(int index) const override {
		/*if (index < 0 || index >= size)
			return;*/
		return m_list[index];
	}
};