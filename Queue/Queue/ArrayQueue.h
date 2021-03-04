#pragma once
#include <iostream>
#include "Queue.h"

template<typename T, int capacity>
class ArrayQueue : public Queue<T> {
private:
	T m_data[capacity + 1];
	int m_front;
	int m_rear;
	int m_size;

public:
	ArrayQueue() : m_front(0), m_rear(0), m_size(0) {}

	bool IsEmpty() const {
		return (m_rear == m_front);
	}

	bool IsFull() const {
		return ((m_rear + 1) % (capacity + 1) == m_front);
	}

	bool Enqueue(const T& item) {
		if (IsFull())
			return false;
		m_data[m_rear] = item;
		m_rear = (m_rear + 1) % (capacity + 1);
		++m_size;
		return true;
	}

	bool Dequeue(T& item) {
		if (IsEmpty())
			return false;
		item = m_front;
		m_front = (m_front + 1) % (capacity + 1);
		--m_size;
		return true;
	}

	T Front() const {
		return m_data[m_front];
	}

	T Rear() const {
		return m_data[m_rear];
	}

	int GetSize() const {
		return m_size;
	}

	void Print() const {
		if (IsEmpty())
			return;
		for(int i = m_front; i != m_rear % (capacity + 1); i = (i + 1) % (capacity + 1))
			std::cout << m_data[i] << ' ';
	}

};
