#pragma once
#include <iostream>

template<typename T>
class Node {
private:
	T data;
	Node* next;

public:
	Node() : next(nullptr) {}
	Node(const T& data) : data(data), next(nullptr) {}
	Node(const T& data, Node* node) : data(data), next(node) {}

	void SetData(const T& data) {
		this->data = data;
	}

	void SetNext(Node* node) {
		next = node;
	}

	T GetData() const {
		return data;
	}

	Node* GetNext() const {
		return next;
	}
};


