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
	bool pop();
	bool isEmpty();
	void deleteStack();
	void printStack();
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
	//This function pushes data onto the stack
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
bool Stack<T>::pop() {
	//this function pops data off the stack and returns false if the stack is empty.
	if (!isEmpty()) {
		T data = top->data;
		temp = top;
		top = top->next;
		delete temp;
		return true;
	}
	else {
		//underflow
		return false;
	}
}

template<class T>
bool Stack<T>::isEmpty() {
	//this function returns true if the stack is empty
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void Stack<T>::deleteStack() {
	//this function deletes the stack by popping everything off the stack
	while (!isEmpty()) {
		pop();
	}
}

template<class T>
void Stack<T>::printStack() {
	//this function prints what is on the stack.
	T printData;
	temp = top;
	while (temp != nullptr) {
		printData = temp->data;
		cout << printData << endl;
		temp = temp->next;
	}
}
#endif