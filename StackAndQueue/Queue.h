#pragma once
#ifndef H_QUEUE
#define H_QUEUE

#include<iostream>
#include<fstream>

using namespace std;

template<class T>
struct dNode {
	T data;
	dNode* next;
	dNode* prev;
};

template<class T>
class Queue {

public:
	Queue();
	const void append(T data);
	T serve();
	bool isEmpty();
private:
	dNode<T>* head;
	dNode<T>* tail;
	dNode<T>* temp;
};

template<class T>
Queue<T>::Queue() {
	head = nullptr;
	tail = nullptr;
}

template<class T>
const void Queue<T>::append(T data) {
	if (this->isEmpty()) {
		head = new dNode<T>;
		head->data = data;
		head->next = nullptr;
		head->prev = nullptr;
		tail = head;
	}
	else {
		temp = new dNode<T>;
		temp->data = data;
		temp->prev = nullptr;
		temp->next = head;
		tail->prev = temp;
		tail = temp;
	}
}

template<class T>
T Queue<T>::serve() {
	if (isEmpty()) {
		cout << "Queue Underflow! Null value: ";
		return NULL;
	}
	else {
		T tempData = head->data;
		temp = head;
		if (head->prev != nullptr) {
			head = head->prev;
			head->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete temp;
		return tempData;
	}
}

template<class T>
bool Queue<T>::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

#endif