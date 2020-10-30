#pragma once
#include <iostream>
#include <vector>

template<typename T>
class Bag {
public:
	virtual int GetSize() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool Add(const T& item) = 0;
	virtual bool Remove(const T& item) = 0;
	virtual void Clear() = 0;
	virtual int GetFrequencyOf(const T& item) const = 0;
	virtual bool Contains(const T& item) const = 0;
	virtual std::vector<T> ToVector() const = 0;
};
