#pragma once
#ifndef H_STACK
#define H_STACK

#include<iostream>
#include<fstream>

using namespace std;

template <class T>
struct node {
	T data;
	node* next;
};

template<class T>
class Stack {
public:
	Stack();
	const void push(T pData);
	T pop();
	bool isEmpty();
private:
	node<T>* top;
	node<T>* temp;
	node<T>* newNode;
};

template<class T>
Stack<T>::Stack() {
	top = nullptr;
}

template<class T>
const void Stack<T>::push(T pData) {
	if (this->isEmpty()) {
		top = new node<T>;
		top->data = pData;
		top->next = nullptr;
	}
	else {
		newNode = new node<T>;
		newNode->data = pData;
		newNode->next = top;
		top = newNode;
	}
}

template<class T>
T Stack<T>::pop() {
	if (this->isEmpty()) {
		cout << "Error: Stack Underflow" << endl;
	}
	else {
		T data = top->data;
		temp = top;
		top = top->next;
		delete temp;
		return data;
	}
}

template<class T>
bool Stack<T>::isEmpty() {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
#endif