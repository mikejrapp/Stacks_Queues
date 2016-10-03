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
	bool serve();
	bool isEmpty();
	void deleteQueue();
	void printQueue();
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
	//This function appends the data onto the head of the list
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
bool Queue<T>::serve() {
	//This function serves the from of the queue and returns false if the stack is empty
	if (isEmpty()) {
		return false;
	}
	else {
		temp = head;
		if (head->prev != nullptr) {
			head = head->prev;
			head->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete temp;
		return true;
	}
}

template<class T>
bool Queue<T>::isEmpty() {
	//this function returns true if the stack is empty
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


template<class T>
void Queue<T>::deleteQueue() {
	//this function deletes the queue by serving everything left on the queue
	if (!isEmpty()) {
		serve();
	}
}

template<class T>
void Queue<T>::printQueue() {
	//this function prints what is in the queue.
	T printData;
	temp = head;
	while (temp != nullptr) {
		printData = temp->data;
		cout << printData << endl;
		temp = temp->prev;
	}
}
#endif