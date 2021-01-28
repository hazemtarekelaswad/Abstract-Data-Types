#pragma once

template<typename K, typename T>
class Dictionary {
public:
	virtual bool IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual void Clear() const = 0;
	virtual bool Add(const K& key, const T& item) = 0;
	virtual bool Remove(const K& key) = 0;
	virtual T GetItem(const K& key) = 0;
	virtual bool Contains(const const K& key) = 0;
};