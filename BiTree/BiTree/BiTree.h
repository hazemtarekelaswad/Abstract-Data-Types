#pragma once

template<typename T>
class BiTree {
public:
	virtual T GetRoot() const = 0;
	virtual int GetSize() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual int GetHeight() const = 0;
	virtual void Clear() = 0;
	virtual void Print() const = 0;
};