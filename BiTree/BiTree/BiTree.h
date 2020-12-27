#pragma once

//	Following the convention that the root is at level 0

template<typename T>
class BiTree {
public:
	virtual T GetRoot() const = 0;
	virtual int GetSize() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual int GetHeight() const = 0;
	virtual void Clear() = 0;
	virtual void Print() const = 0;
	virtual void Insert(const T& item) = 0;
	virtual void Delete() = 0;
};