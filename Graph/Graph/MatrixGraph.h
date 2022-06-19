#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "Graph.h"


// Undirected, Unweighted Graph
template<typename T>
struct Edge {
	T item;
	mutable int status;		// 0 ==> Unprocessed | 1 ==> processed | 2 ==> pushed 
};

template<typename T, int capacity>
class MatrixGraph : public Graph<T> {
private:
	Edge<T> vertex_[capacity];
	bool matrix_[capacity][capacity];
	int size_;

public:
	MatrixGraph() : size_(0) {
		for (int i = 0; i < capacity; ++i) {
			vertex_[i].status = 0;
			for (int j = 0; j < capacity; ++j)
				matrix_[i][j] = 0;
		}
	}

	int GetNumVertices() const {
		return size_;
	}

	int GetNumEdges() const {
		int numEdges = 0;
		for (int i = 0; i < size_ - 1; ++i)
			for (int j = i + 1; j < size_; ++j)
				if (matrix_[i][j])
					++numEdges;
		return numEdges;
	}

	bool IsEmpty() const {
		return size_ == 0;
	}

	bool Add(const T& start, const T& end) {
		int startIndex = -1;
		int endIndex = -1;

		for (int i = 0; i < size_; ++i) {
			if (startIndex >= 0 && endIndex >= 0)
				break;

			if (vertex_[i].item == start)
				startIndex = i;

			if (vertex_[i].item == end)
				endIndex = i;
		}

		if ((startIndex == -1 || endIndex == -1) && size_ == capacity)
			return false;

		if (startIndex == -1) {
			startIndex = size_++;
			vertex_[startIndex].item = start;
		}

		if (endIndex == -1) {
			endIndex = size_++;
			vertex_[endIndex].item = end;
		}

		matrix_[startIndex][endIndex] = matrix_[endIndex][startIndex] = 1;
		return true;
	}

	bool Remove(const T& start, const T& end) {
		return false;
	}

	int GetWeight(const T& start, const T& end) const {
		return 0;
	}

	void DFPrint(const T& start) const {
		if (IsEmpty())
			return;
		
		int index = 0;
		while (index < size_ && vertex_[index].item != start)
			++index;
		if (index == size_)
			return;

		std::stack<int> st;
		st.push(index);
		int topIndex = st.top();

		while (!st.empty()) {
			topIndex = st.top();
			std::cout << vertex_[topIndex].item << ' ';
			vertex_[topIndex].status = 1;
			st.pop();
			for (int j = size_ - 1; j >= 0; --j)
				if (matrix_[topIndex][j] && !vertex_[j].status) {
					st.push(j);
					vertex_[j].status = 2;	// pushed
				}
		}
		std::cout << '\n';
	}

	void BFPrint(const T& start) const {
		if (IsEmpty())
			return;

		int index = 0;
		while (index < size_ && vertex_[index].item != start)
			++index;
		if (index == size_)
			return;

		std::queue<int> st;
		st.push(index);
		int topIndex = st.front();

		while (!st.empty()) {
			topIndex = st.front();
			std::cout << vertex_[topIndex].item << ' ';
			vertex_[topIndex].status = 1;
			st.pop();
			for (int j = size_ - 1; j >= 0; --j)
				if (matrix_[topIndex][j] && !vertex_[j].status) {
					st.push(j);
					vertex_[j].status = 2;	// pushed
				}
		}
		std::cout << '\n';
	}

	void PrintMatrix() const {
		for (int i = 0; i < capacity; ++i) {
			std::cout << vertex_[i].item << ' ';
			for (int j = 0; j < capacity; ++j)
				std::cout << matrix_[i][j] << ' ';
			std::cout << '\n';
		}
	}

	virtual ~MatrixGraph() {}
};