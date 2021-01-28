#pragma once
#include "Node.h"

template<typename T>
class SortedList {
public:
	virtual void Insert(const T& item) = 0;
	virtual bool Remove(int index) = 0;
	virtual bool Remove(const T& item) = 0;
	virtual T GetItem(int index) const = 0;
	virtual int GetPosition(const T& item) = 0;
	virtual bool IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual void Clear() = 0;
};
