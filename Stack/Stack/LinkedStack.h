#pragma once
#include <iostream>
#include <cassert>
#include "Stack.h"
#include "Node.h"

template<typename T>
class LinkedStack : public Stack<T> {
private:
	Node<T>* m_head;
	int size;

public:
	LinkedStack() : m_head(nullptr), size(0) {}

	LinkedStack(const LinkedStack& stack) {
		Node<T>* temp = stack.m_head;
		Node<T>* temp2 = nullptr;
		while (temp) {
			//PushBack(temp->GetData());
			Node<T>* newNode = new Node<T>(temp->GetData());
			if (!m_head) {
				m_head = newNode;
				temp2 = m_head;
			}
			else {
				temp2->SetNext(newNode);
				temp2 = temp2->GetNext();
			}
			temp = temp->GetNext();
		}
	}
	//LinkedStack& operator=(const LinkedStack& stack) {}

	bool IsEmpty() const {
		return m_head == nullptr;
	}
	bool IsFull() const {
		return false;
	}
	bool Push(const T& item) {
		Node<T>* newNode = new Node<T>(item, m_head);
		m_head = newNode;
		++size;
		return true;
	}
	bool Pop() {
		if (IsEmpty())
			return false;
		Node<T>* nodeToRemove = m_head;
		m_head = m_head->GetNext();
		delete nodeToRemove;
		--size;
		return true;
	}
	T Peek() {
		assert(!IsEmpty());
		return m_head->GetData();
	}
	int Size() const {
		return size;
	}
	void Print() const {
		Node<T>* temp = m_head;
		while (temp) {
			std::cout << temp->GetData() << ' ';
			temp = temp->GetNext();
		}
		std::cout << '\n';
	}
	~LinkedStack() {
		while (!IsEmpty())
			Pop();
	}

};