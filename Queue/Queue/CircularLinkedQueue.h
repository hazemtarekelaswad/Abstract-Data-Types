#pragma once
#include <iostream>
#include <cassert>
#include "Node.h"
#include "Queue.h"

template<typename T>
class CircularLinkedQueue : public Queue<T> {
private:
	Node<T>* m_rear;
	int size;

public:
	CircularLinkedQueue() : m_rear(nullptr), size(0) {}

	bool IsEmpty() const {
		return m_rear == nullptr;
	}

	bool IsFull() const {
		return false;
	}

	bool Enqueue(const T& item) {
		if (IsFull())
			return false;
		Node<T>* newNode = nullptr;
		if (!m_rear) {
			newNode = new Node<T>(item, nullptr);
			newNode->SetNext(newNode);
		}
		else {
			newNode = new Node<T>(item, m_rear->GetNext());
			m_rear->SetNext(newNode);
		}
		m_rear = newNode;
		++size;
		return true;
	}

	bool Dequeue(T& item) {
		if (IsEmpty())
			return false;
		Node<T>* temp = m_rear->GetNext();
		if (m_rear == m_rear->GetNext())
			m_rear = nullptr;
		else
			m_rear->SetNext(temp->GetNext());
		item = temp->GetData();
		delete temp;
		--size;
		return true;
	}

	T Front() const {
		assert(!IsEmpty());
		return m_rear->GetNext()->GetData();
	}
	T Rear() const {
		assert(!IsEmpty());
		return m_rear->GetData();
	}
	int GetSize() const {
		return size;
	}
	void Print() const {
		if (!m_rear)
			return;
		Node<T>* temp = m_rear->GetNext();
		do {
			std::cout << temp->GetData() << ' ';
			temp = temp->GetNext();
		} while (temp != m_rear->GetNext());

		std::cout << '\n';
	}

	~CircularLinkedQueue() {
		T x;
		while (Dequeue(x));
	}
};
