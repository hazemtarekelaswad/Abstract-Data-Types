#pragma once
#include <iostream>

template<typename T>
class Stack {
public:
	bool IsEmpty() const = 0;
	bool IsFull() const = 0;
	bool Push(const T& item) = 0;
	bool Pop() = 0;
	T Peek() = 0;
};