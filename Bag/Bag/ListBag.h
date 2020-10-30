#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include "Bag.h"

template<typename T>
class LinkedBag : public Bag<T> {
private:
	Node<T>* m_head;
	int size;

public:
	LinkedBag() : m_head(nullptr), size(0) {}

	int GetSize() const override {
		return size;
	}

	bool IsEmpty() const override {
		return size == 0;
	}

	bool Add(const T& item) override {
		Node<T>* newNode = new Node<T>(item, m_head);
		m_head = newNode;
		++size;
		return true;
	}

	bool Remove(const T& item) override {
		Node<T>* temp = m_head;
		while (temp) {
			if (temp->GetData() == item) {
				temp->SetData(m_head->GetData());
				temp = m_head;
				m_head = m_head->GetNext();
				delete temp;
				--size;
				return true;
			}
			temp = temp->GetNext();
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



