#pragma once
#include <iostream>

template<typename T>
class Stack {
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Push(const T& item) = 0;
	virtual bool Pop() = 0;
	virtual T Peek() = 0;
	virtual int Size() const = 0;
	virtual void Print() const = 0;
};