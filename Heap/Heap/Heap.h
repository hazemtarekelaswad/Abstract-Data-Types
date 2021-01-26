#pragma once
template<typename T>
class Heap {
	virtual void IsEmpty() const = 0;
	virtual int Size() const = 0;
	virtual int GetHeight() const = 0;
	virtual T Peek() const = 0;
	virtual bool Add(const T& item) = 0;
	virtual bool Remove() = 0;
	virtual void Clear() = 0;
};