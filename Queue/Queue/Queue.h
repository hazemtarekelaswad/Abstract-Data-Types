#pragma once
#include <iostream>

template<typename T>
class Queue {
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Enqueue(const T& item) = 0;
	virtual bool Dequeue(const T& item) = 0;
	virtual T Front() const = 0;
	virtual T Back() const = 0;
	virtual void Print() const = 0;
};
