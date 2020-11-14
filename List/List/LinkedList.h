#pragma once
#include <iostream>
#include "List.h"
#include "Node.h"

template<typename T>
class LinkedList : public List<T> {
private:
	Node<T>* m_head;
	int size;

public:
	LinkedList() : size(0), m_head(nullptr) {}
	LinkedList(const LinkedList& lst) {
	}
	LinkedList& operator=(const LinkedList& lst) {
	}
	bool IsEmpty() const override {
		return (m_head == nullptr);
	}
	int GetSize() const override {
		return size;
	}
	void Clear() override {
	}
	bool Insert(int index, const T& item) override {
		if (index < 0 || index > size)
			return false;

		if (!index) {
			Node<T>* newNode = new Node<T>(item, m_head);
			m_head = newNode;
		}
		else {
			Node<T>* temp = m_head;
			while (--index)
				temp = temp->GetNext();
			Node<T>* newNode = new Node<T>(item, temp->GetNext());
			temp->SetNext(newNode);
		}
		++size;
		return true;
	}
	bool RemoveAt(int index) override {
	}
	bool Remove(const T& item) override {
	}
	void Replace(int index, const T& item) override {
	}
	T GetItem(int index) const override {
	}

	~LinkedList() {
		Clear();
	}
};