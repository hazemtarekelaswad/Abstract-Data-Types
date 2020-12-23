#pragma once
#include <iostream>
#include <cassert>
#include "Node.h"
#include "Queue.h"

template<typename T>
class LinkedQueue : public Queue<T> {
private:
	Node<T>* m_front;
	Node<T>* m_rear;
	int size;

public:
	LinkedQueue() : m_front(nullptr), m_rear(nullptr), size(0) {}

	LinkedQueue(const LinkedQueue& queue) : m_front(nullptr), m_rear(nullptr), size(0) {
		Node<T>* temp = queue.m_front;
		while (temp) {
			Enqueue(temp->GetData());
			temp = temp->GetNext();
		}
	}

	bool IsEmpty() const {
		return m_rear == nullptr;
	}

	bool IsFull() const {
		return false;
	}

	bool Enqueue(const T& item) {
		if (IsFull())
			return false;
		Node<T>* newNode = new Node<T>(item, nullptr);
		if (!m_rear)
			m_front = newNode;
		else
			m_rear->SetNext(newNode);
		m_rear = newNode;
		++size;
		return true;
	}

	bool Dequeue(T& item) {
		if (IsEmpty())
			return false;
		Node<T>* temp = m_front;
		if (m_front == m_rear)
			m_rear = nullptr;
		item = m_front->GetData();
		m_front = m_front->GetNext();
		delete temp;
		--size;
		return true;
	}

	T Front() const {
		assert(!IsEmpty());
		return m_front->GetData();
	}
	T Rear() const {
		assert(!IsEmpty());
		return m_rear->GetData();
	}
	int GetSize() const {
		return size;
	}
	void Print() const {
		Node<T>* temp = m_front;
		while (temp) {
			std::cout << temp->GetData() << ' ';
			temp = temp->GetNext();
		}
		std::cout << '\n';
	}

	~LinkedQueue() {
		T x;
		while (Dequeue(x));
	}
};
