#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include <queue>
#include "BiNode.h"
#include "BiTree.h"

template<typename T>
class LinkedBiTree : public BiTree<T> {
private:
	BiNode<T>* root;
	int count;

	/*BiNode<T>*& LevelOrder(BiNode<T>*& subRoot) {
		std::queue<BiNode<T>*> qu;
		qu.push(subRoot);
		while (!qu.empty()) {

		}
		if (!subRoot)
			return subRoot;
		return LevelOrder(subRoot->GetLeft());
	}*/
	/*void Insert(BiNode<T>*& subRoot, const T& item) {
		BiNode<T>* newNode = new BiNode<T>(item);
		if (!subRoot)
			subRoot = newNode;
		else {
			Insert(subRoot->GetLeft(), item);
			Insert(subRoot->GetRight(), item);
		}
		++count;
	}*/

public:
	LinkedBiTree() : root(nullptr), count(0) {}

	LinkedBiTree(const T& item) : count(1) {
		root = new BiNode<T>(item);
	}

	LinkedBiTree(const LinkedBiTree& biTree) = delete;

	T GetRoot() const {
		assert(!IsEmpty());
		return root->GetData();
	}
	int GetSize() const {
		return count;
	}
	bool IsEmpty() const {
		return root == nullptr;
	}
	int GetHeight() const {
		return ceil(log2(count + 1) - 1);
	}

	void Insert(const T& item) {
		
	}

	void Delete() {

	}

	void Clear() {

	}
	void Print() const {

	}

	~LinkedBiTree() {
		Clear();
	}
};
