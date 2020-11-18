#pragma once
#include <iostream>
#include <cassert>
#include "Stack.h"

template<typename T, int CAPACITY>
class ArrayStack : public Stack<T> {
private:
	T m_stack[CAPACITY];
	int top;

public:
	ArrayStack() : top(-1){}
	bool IsEmpty() const {
		return Size() == 0;
	}
	bool IsFull() const {
		return Size() == CAPACITY;
	}
	bool Push(const T& item) {
		if (IsFull())
			return false;
		m_stack[++top] = item;
		return true;
	}
	bool Pop() {
		if (IsEmpty())
			return false;
		--top;
		return true;
	}
	T Peek() {
		assert(!IsEmpty());
		return m_stack[top];
	}
	int Size() const {
		return top + 1;
	}
	void Print() const {
		for (int i = 0; i < Size(); ++i) 
			std::cout << m_stack[i] << ' ';
		std::cout << std::endl;
	}
};