#pragma once
#include <iostream>
#include <cassert>
#include <cmath>
#include <queue>
#include "LinkedBiNode.h"
#include "BiTree.h"

template<typename T>
class LinkedBiTree : public BiTree<T> {
private:
	LinkedBiNode<T>* root;
	int count;

	//static BiNode<T>* Insert(BiNode<T>* root) {
	//	if (!root)
	//		return nullptr;
	//	queue<BiNode<T>*> trav;
	//	trav.push(root);
	//	while (!trav.empty()) {
	//		if (trav.front()->left)
	//			trav.push(trav.front()->left);
	//		else
	//			return trav.front();
	//		if (trav.front()->right)
	//			trav.push(trav.front()->right);
	//		else
	//			return trav.front();
	//		//cout << trav.front()->data << ' ';
	//		trav.pop();
	//	}
	//}
	/*static void sPrint(BiNode<T>* root) const {
		if (root == nullptr)
			return;
		Print(root->GetLeft());
		cout << root->GetData() << ' ';
		Print(root->GetRight());
	}*/

public:
	LinkedBiTree() : root(nullptr), count(0) {}

	LinkedBiTree(const T& item) : count(1) {
		root = new LinkedBiNode<T>(item);
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

	void Delete() {

	}

	void Clear() {

	}
	/*void Print() const {
		sPrint(root);
	}*/

	~LinkedBiTree() {
		Clear();
	}
};
