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
		Node<T>* curr = m_head;
		Node<T>* prev = nullptr;
		while (curr) {
			prev = curr;
			curr = curr->GetNext();
			delete prev;
		}
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
		Node<T>* temp = m_head;
		while (index--)
			temp = temp->GetNext();
		temp->SetData(item);
	}

	T GetItem(int index) const override {
		Node<T>* temp = m_head;
		while (index--)
			temp = temp->GetNext();
		return temp->GetData();
	}

	~LinkedList() {
		Clear();
	}
};