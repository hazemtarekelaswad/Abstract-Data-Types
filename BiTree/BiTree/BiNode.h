#pragma once
#include <iostream>

template<typename T>
class BiNode{
private:
	T data;
	BiNode* left;
	BiNode* right;

public:
	BiNode() : left(nullptr), right(nullptr) {}
	BiNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
	BiNode(const T& data, BiNode* left) : data(data), left(left), right(nullptr) {}
	BiNode(const T& data, BiNode* left, BiNode* right) : data(data), left(left), right(right) {}

	void SetData(const T& data) {
		this->data = data;
	}

	void SetLeft(BiNode* node) {
		left = node;
	}

	void SetRight(BiNode* node) {
		right = node;
	}

	void SetChildren(BiNode* lft, BiNode* ryt) {
		left = lft;
		right = ryt;
	}

	T GetData() const {
		return data;
	}

	BiNode* GetLeft() const {
		return left;
	}

	BiNode* GetRight() const {
		return right;
	}
};
