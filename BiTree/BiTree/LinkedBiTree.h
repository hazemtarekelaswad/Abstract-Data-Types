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

private:
	void ClearHelper(LinkedBiNode<T>* subRoot) {

	}

	LinkedBiNode<T>* AddHelper(LinkedBiNode<T>* mainRoot, LinkedBiNode<T>* subRoot) {

	}

	void RemoveHelper(const T& item, LinkedBiNode<T>* subRoot) {

	}

	void PreOrderTravHelper(void (*Visit)(T&), LinkedBiNode<T>* subRoot) {

	}

	void InOrderTravHelper(void (*Visit)(T&), LinkedBiNode<T>* subRoot) {

	}

	void PostOrderTravHelper(void (*Visit)(T&), LinkedBiNode<T>* subRoot) {

	}

	void PrintHelper(LinkedBiNode<T>* subRoot) {

	}

public:
	LinkedBiTree() : root(nullptr), count(0) {}

	LinkedBiTree(const T& item) : count(1) {
		root = new LinkedBiNode<T>(item);
	}
	
	LinkedBiTree(const T& item, LinkedBiNode<T>* rightSubTree, LinkedBiNode<T>* leftSubTree) {

	}

	LinkedBiTree(const LinkedBiTree& biTree) = delete;

	void SetRoot(const T& data) {
		assert(!IsEmpty());
		root->SetData(data);
	}
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
	void Add(const T& item) {

	}
	void Remove(const T& item) {

	}
	bool Contains(const T& item) const {

	}

	void Clear() {

	}

	void PreOrderTrav(void (*Visit)(T&)) {

	}
	void InOrderTrav(void (*Visit)(T&)) {

	}
	void PostOrderTrav(void (*Visit)(T&)) {

	}

	/*void Print() const {
		sPrint(root);
	}*/

	~LinkedBiTree() {
		Clear();
	}
};
