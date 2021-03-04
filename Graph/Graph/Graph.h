#pragma once

template<typename T>
class Graph {
public:
	virtual int GetNumVertices() const = 0;
	virtual int GetNumEdges() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool Add(const T& start, const T& end) = 0;
	virtual bool Remove(const T& start, const T& end) = 0;
	virtual int GetWeight(const T& start, const T& end) const = 0;
	virtual void DFPrint(const T& start) const = 0;
	virtual void BFPrint(const T& start) const = 0;
};