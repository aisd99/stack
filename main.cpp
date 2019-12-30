﻿#include <iostream>
#include <string>
#include <sstream>

template<typename T>
class Stack {
public:
	Stack();
	Stack(size_t new_capacity);
	~Stack();

	void CommandManager();
	void Push(const T& item);
	void Pop();
	void SetSize(size_t new_capacity);
	void Print();
private:
	T* values = NULL;
	size_t _capacity = 0;
	int _head = -1;
};

template<typename T>
Stack<T>::Stack(){}

template<typename T>
Stack<T>::Stack(size_t new_capacity){
	values = new T[new_capacity];
	_capacity = new_capacity;
}

template<typename T>
Stack<T>::~Stack(){
	delete[] values;
}

template<typename T>
void Stack<T>::CommandManager(){
	for (std::string line; std::getline(std::cin, line); ) {
		std::istringstream is(line);
		std::string command;
		is >> command;
		if (command == "set_size") {
			int new_size;
			is >> new_size;
			SetSize(new_size);
		}
		else if (command == "push") {
			T new_item;
			is >> new_item;
			Push(new_item);
		}
		else if (command == "pop") {
			Pop();
		}
		else if (command == "print") {
			Print();
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
}

template<typename T>
void Stack<T>::Push(const T& item){
	if (_head == _capacity - 1) {
		std::cout << "overflow" << std::endl;
	}
	else {
		values[++_head] = item;
	}
}

template<typename T>
void Stack<T>::Pop(){
	if (_head == -1) {
		std::cout << "underflow" << std::endl;
	}
	else {
		--_head;
	}
}

template<typename T>
void Stack<T>::SetSize(size_t new_capacity){
	if (new_capacity != _capacity) {
		T* new_values = new T[new_capacity];
		for (int i = 0; i < _head && i < new_capacity; ++i) {
			new_values[i] = std::move(values[i]);
		}
		delete[] values;
		if (new_capacity < _capacity) {
			_head = new_capacity;
		}
		_capacity = new_capacity;
		values = new_values;
	}
}

template<typename T>
void Stack<T>::Print(){
	if (_head == -1) {
		std::cout << "empty";
	}
	else {
		for (int i = 0; i <= _head; ++i) {
			std::cout << values[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	Stack<int> stack;
	stack.CommandManager();
}