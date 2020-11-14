#pragma once
#include <iostream>

template<typename T>
class List {
public:
	virtual bool IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual void Clear() = 0;
	virtual bool Insert(int index) = 0;
	virtual bool Remove(int index) = 0;
	virtual bool Remove(const T& item) = 0;
	virtual void Replace(int index, const T& item) = 0;
	virtual T GetItem(int index) const = 0;
};


