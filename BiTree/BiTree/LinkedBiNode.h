#pragma once
#include <iostream>
#include "BiNode.h"

template<typename T>
class LinkedBiNode : public BiNode<T> {
private:
	LinkedBiNode* left;
	LinkedBiNode* right;

public:
	LinkedBiNode() : left(nullptr), right(nullptr) {}
	LinkedBiNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
	LinkedBiNode(const T& data, LinkedBiNode* left) : data(data), left(left), right(nullptr) {}
	LinkedBiNode(const T& data, LinkedBiNode* left, LinkedBiNode* right) : data(data), left(left), right(right) {}


	void SetLeft(LinkedBiNode* node) {
		left = node;
	}

	void SetRight(LinkedBiNode* node) {
		right = node;
	}

	void SetChildren(LinkedBiNode* lft, LinkedBiNode* ryt) {
		left = lft;
		right = ryt;
	}

	LinkedBiNode* GetLeft() const {
		return left;
	}

	LinkedBiNode* GetRight() const {
		return right;
	}

	bool IsLeaf() const override {
		return (right == nullptr && left == nullptr);
	}
};
