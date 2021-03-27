#include "Vector.h"

Vector::Vector() {
	length = 0;
	capacity = 2;
	elements = new int[2];
}

int Vector::size() {
	return this->length;
}

bool Vector::is_empty() {
	return (length != 0);
}

int Vector::at(int index) {
	return elements[index];
}

int Vector::operator[](int index) {
	return this->at(index);
}

void Vector::insert(int index, int value) {
	if (length == capacity)
		resize(2 * capacity);

	for (int i = length; i > index; i--)
		elements[i] = elements[i - 1];

	elements[index] = value;
	length++;
}

int Vector::pop_back() {
	length--;

	return elements[length + 1];
}

void Vector::erase(int index) {
	if (index >= length) return;

	for (int i = index; i < length - 1; i++)
		elements[i] = elements[i + 1];

	length--;
}

void Vector::remove(int value) {
	int numberOfOccurences = 0, i;

	for (i = 0; i < length; i++)
		if (elements[i] == value)
			numberOfOccurences++;

	if (numberOfOccurences == 0) return;

	int* aux = new int[length - numberOfOccurences];
	int position = 0;


	for (i = 0; i < length; i++)
		if (elements[i] != value)
			aux[position++] = elements[i];

	delete[] elements;
	elements = aux;
	length = capacity = length - numberOfOccurences;
}

int Vector::find(int value) {
	for (int i = 0; i < length; i++)
		if (elements[i] == value)
			return i;

	return -1;
}

void Vector::resize(int newLength) {
	int* aux = new int[newLength];

	if (newLength < length) {
		for (int i = 0; i < newLength; ++i)
			aux[i] = elements[i];

		length = newLength;
	}

	else {
		for (int i = 0; i < length; ++i)
			aux[i] = elements[i];
	}

	delete[] elements;
	elements = aux;

	capacity = newLength;
}


void Vector::push_back(int value) {
	if (length == capacity) 
		resize(2 * capacity);

	elements[length++] = value;
}

void Vector::clear() {
	resize(0);
}