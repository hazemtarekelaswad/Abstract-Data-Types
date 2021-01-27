#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include "Heap.h"

template<typename T, int capacity>
class ArrayHeap : public Heap<T> {
private:
	T data[capacity]{};
	int size;

private:

	int GetLeftChildIndex(int nodeIndex) const {
		return 2 * nodeIndex + 1;
	}
	int GetRightChildIndex(int nodeIndex) const {
		return 2 * nodeIndex + 2;
	}
	int GetParentIndex(int nodeIndex) const {
		return (nodeIndex - 1) / 2;
	}
	bool IsLeaf(int nodeIndex) const {
		return GetLeftChildIndex(nodeIndex) >= size;
	}
	void ReheapUp() {
		int newIndex = size - 1;
		while (newIndex && data[newIndex] > data[GetParentIndex(newIndex)]) {
			std::swap(data[newIndex], data[GetParentIndex(newIndex)]);
			newIndex = GetParentIndex(newIndex);
		}
	}

	void ReheapDown(int root) {
		if (IsLeaf(root))
			return;

		int firstChildIndex = GetLeftChildIndex(root);
		int secChildIndex = GetRightChildIndex(root);
		if (data[firstChildIndex] > data[secChildIndex] && data[root] < data[firstChildIndex]) {
			std::swap(data[firstChildIndex], data[root]);
			ReheapDown(firstChildIndex);
		}
		else if (data[secChildIndex] > data[firstChildIndex] && data[root] < data[secChildIndex]) {
			std::swap(data[secChildIndex], data[root]);
			ReheapDown(secChildIndex);
		}
	}

	/*void ReheapDown() {
		int root = 0;
		while (root < size) {
			int firstChildIndex = GetLeftChildIndex(root);
			int secChildIndex = GetRightChildIndex(root);
			if (firstChildIndex == size - 1 && data[root] < data[firstChildIndex])
				std::swap(data[firstChildIndex], data[root]);
			else if (firstChildIndex < size - 1 && secChildIndex < size) {
				if (data[firstChildIndex] > data[secChildIndex] && data[root] < data[firstChildIndex]) {
					std::swap(data[firstChildIndex], data[root]);
					root = firstChildIndex;
				}
				else if (data[secChildIndex] > data[firstChildIndex] && data[root] < data[secChildIndex]) {
					std::swap(data[secChildIndex], data[root]);
					root = secChildIndex;
				}
			}
			else
				return;
		}
	}*/


public:
	ArrayHeap() : size(0) {}

	ArrayHeap(T* arr, int length) : size(0) {
		assert(length <= capacity && length >= 0);
		for (int i = 0; i < length; ++i)
			Add(arr[i]);
	}

	ArrayHeap(const std::initializer_list<T>& list) : size(0) {
		assert(list.size() <= capacity);
		for (const T& item : list)
			Add(item);
	}

	bool IsEmpty() const override {
		return size == 0;
	}
	int Size() const override {
		return size;
	}
	int GetHeight() const override {
		return std::ceil(log2(size + 1)) - 1;
	}
	T Peek() const override {
		assert(!IsEmpty());
		return data[0];
	}
	bool Add(const T& item) override {
		if (size == capacity)
			return false;
		data[size++] = item;
		ReheapUp();
		return true;
	}
	bool Remove() override {
		if (IsEmpty())
			return false;
		data[0] = data[size - 1];
		--size;
		ReheapDown(0);
		return true;
	}
	void Clear() override {
		size = 0;
	}

	void Print() const override {
		for (int i = 0; i < size; ++i)
			std::cout << data[i] << ' ';
		std::cout << '\n';
	}

	virtual ~ArrayHeap() {}

};