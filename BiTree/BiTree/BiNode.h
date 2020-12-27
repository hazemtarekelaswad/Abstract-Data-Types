#pragma once
#include <iostream>

template<typename T>
class BiNode {
protected:
	T data;
public:
	void SetData(const T& data) {
		this->data = data;
	}
	T GetData() const {
		return data;
	}

	virtual bool IsLeaf() const = 0;
};
