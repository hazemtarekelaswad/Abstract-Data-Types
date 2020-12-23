#pragma once
#include <iostream>
#include <cassert>
#include "BiNode.h"
#include "BiTree.h"

template<typename T>
class LinkedBiTree : public BiTree<T> {
private:
	BiNode<T>* root;
	int count;

public:
	LinkedBiTree() : root(nullptr), count(0) {}

	LinkedBiTree(const T& item) : count(1) {
		root = new BiNode<T>(item);
	}

	LinkedBiTree(const LinkedBiTree<T>& biTree) {}

	T GetRoot() const {
		assert(!IsEmpty());
		return root->GetData();
	}
	int GetSize() const {
		return count;
	}
	bool IsEmpty() const {

	}
	int GetHeight() const {

	}
	void Clear() {

	}
	void Print() const {

	}

	~LinkedBiTree() {}
};
