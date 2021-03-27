#pragma once
class Vector{
private:
	int length, capacity;
	int *elements;

public:
	Vector();

	int size();
	bool is_empty();
	int at(int index);
	int operator[](int index);
	void insert(int index, int value);
	int pop_back();
	void erase(int index);
	void remove(int value);
	int find(int value);
	void resize(int newSize);
	void push_back(int value);
	void clear();
};

