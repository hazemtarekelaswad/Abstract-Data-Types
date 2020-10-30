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
		Node<T>* temp = m_head;
		while (temp) {
			m_head = m_head->GetNext();
			delete temp;
			--size;
			temp = temp->GetNext();
		}

	}

	int GetFrequencyOf(const T& item) const override {
		int count = 0;
		Node<T>* temp = m_head;
		while (temp) {
			if (temp->GetData() == item)
				++count;
			temp = temp->GetNext();
		}
		return count;

	}

	bool Contains(const T& item) const override {
		Node<T>* temp = m_head;
		while (temp) {
			if (temp->GetData() == item)
				return true;
			temp = temp->GetNext();
		}
		return false;
	}

	friend std::ostream& operator<<(std::ostream& out, const LinkedBag& bag) {
		Node<T>* temp = bag.m_head;
		while (temp) {
			out << temp->GetData() << ' ';
			temp = temp->GetNext();
		}
		return out;
	}

	std::vector<T> ToVector() const override {
		std::vector<T> vec(size);
		Node<T>* temp = m_head;
		while (temp) {
			vec.push_back(temp->GetData());
			temp = temp->GetNext();
		}
		return vec;
	}

	~LinkedBag() {
		Clear();
	}
};



