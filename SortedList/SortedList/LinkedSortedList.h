#pragma once
#include <iostream>
#include <cassert>
#include "SortedList.h"
#include "Node.h"

template<typename T>
class LinkedSortedList : public SortedList<T> {
private:
	Node<T>* head_;
	int size_;
public:
	LinkedSortedList() : size_(0), head_(nullptr) {}

	LinkedSortedList(const LinkedSortedList& lst) = delete;

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

	bool RemoveAt(int index) {
		if (index >= size_ && index < 0)
			return false;

		Node<T>* temp = head_;

		if (index == 0) {
			head_ = head_->GetNext();
			delete temp;
			--size_;
			return true;
		}

		while (--index)
			temp = temp->GetNext();
		Node<T>* nodeToRemove = temp->GetNext();
		temp->SetNext(nodeToRemove->GetNext());
		delete nodeToRemove;
		--size_;
		return true;

	}

	bool Remove(const T& item) {
		if (!head_)
			return false;

		Node<T>* temp = head_;

		if (head_->GetData() == item) {
			head_ = head_->GetNext();
			delete temp;
			--size_;
			return true;
		}

		while (temp->GetNext()) {
			if (temp->GetNext()->GetData() == item) {
				Node<T>* nodeToRemove = temp->GetNext();
				temp->SetNext(nodeToRemove->GetNext());
				delete nodeToRemove;
				--size_;
				return true;
			}
			temp = temp->GetNext();
		}
		return false;
	}

	T GetItem(int index) const {
		assert(index < size_ && index >= 0);
		Node<T>* temp = head_;
		while (index--)
			temp = temp->GetNext();
		return temp->GetData();
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
