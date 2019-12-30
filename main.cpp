#include <iostream>
#include <string>
#include <sstream>

#define _ERROR_ std::cout << "error" << std::endl;

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
Stack<T>::Stack() {}

template<typename T>
Stack<T>::Stack(size_t new_capacity) {
	values = new T[new_capacity];
	_capacity = new_capacity;
}

template<typename T>
Stack<T>::~Stack() {
	delete[] values;
}

template<typename T>
void Stack<T>::CommandManager() {
	bool notallocated = true;
	for (std::string line; std::getline(std::cin, line); ) {
		std::istringstream is(line);
		std::string command;
		is >> command;
		if (command == "set_size") {
			notallocated = false;
			if (values == NULL) {
				int new_size;
				is >> new_size;
				std::string add;
				is >> add;
				if (add != "") _ERROR_
				else SetSize(new_size);
			}
			else _ERROR_
		}
		else if (!(notallocated)){			
			if (command == "push") {
			T new_item;
			is >> new_item;
			std::string add;
			is >> add;
			if (add != "") _ERROR_
			else Push(new_item);
			}
			else if (line == command) {
			if (command == "pop") {
				Pop();
			}
			else if (command == "print") {
				Print();
			}
			else if (command.size() > 0) {
				_ERROR_
			}
		}
			else _ERROR_
		}
		else _ERROR_
	}
}

template<typename T>
void Stack<T>::Push(const T& item) {
	if (_head == _capacity - 1) {
		std::cout << "overflow" << std::endl;
	}
	else {
		values[++_head] = item;
	}
}

template<typename T>
void Stack<T>::Pop() {
	if (_head == -1) {
		std::cout << "underflow" << std::endl;
	}
	else {
		std::cout << values[_head] << std::endl;
		--_head;
	}
}
/*
template<typename T>
void Stack<T>::SetSize(size_t new_capacity) {
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
*/
template<typename T>
void Stack<T>::SetSize(size_t new_capacity){
	values = new T[new_capacity];
	_capacity = new_capacity;
}

template<typename T>
void Stack<T>::Print() {
	if (_head == -1) {
		std::cout << "empty";
	}
	else {
		for (int i = 0; i < _head; ++i) {
			std::cout << values[i] << " ";
		}
		std::cout << values[_head];
	}
	std::cout << std::endl;
}


int main()
{
	Stack<std::string> stack;
	stack.CommandManager();
}
