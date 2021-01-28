#pragma once
#include <iostream>
#include "SortedList.h"
#include "Node.h"

template<typename T>
class LinkedSortedList : public SortedList<T> {
private:
	Node<T>* head_;
	int size_;
public:
	LinkedSortedList() : size_(0), head_(nullptr) {}

	void Insert(const T& item) {
		Node<T>* newNode = new Node<T>(item);
		if (!head_ || head_ && item <= head_->GetData()) {
			newNode->SetNext(head_);
			head_ = newNode;
			++size_;
			return;
		}
		Node<T>* temp = head_;
		while (temp->GetNext() && item > temp->GetNext()->GetData())
			temp = temp->GetNext();

		newNode->SetNext(temp->GetNext());
		temp->SetNext(newNode);
		++size_;
	}
	bool Remove(int index) {
		return false;
	}
	bool Remove(const T& item) {
		return false;
	}
	T GetItem(int index) const {
		return head_->GetData();
	}
	int GetPosition(const T& item) {
		Node<T>* temp = head_;
		int index = 0;
		while (temp) {
			if (temp->GetData() == item)
				return index;
			temp = temp->GetNext();
			++index;
		}
		return -1;
	}
	bool IsEmpty() const {
		return head_ == nullptr;
	}
	int GetSize() const {
		return size_;
	}
	void Clear() {
		Node<T>* temp = head_;
		while (temp) {
			head_ = head_->GetNext();
			delete temp;
			temp = head_;
		}
	}

	void Print() const {
		Node<T>* temp = head_;
		while (temp) {
			std::cout << temp->GetData() << ' ';
			temp = temp->GetNext();
		}
		std::cout << '\n';
	}

	~LinkedSortedList() {
		Clear();
	}
};
