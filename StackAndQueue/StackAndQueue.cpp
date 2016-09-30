#include<iostream>
#include<fstream>
#include<string>
#include"Stack.h"
#include"Queue.h"

using namespace std;

void test(Stack<int> &pStack);
void testQ(Queue<int> &pQueue);

int main() {
	
	Stack<int> stack;
	Queue<int> queue;

	test(stack);
	testQ(queue);

	cin.get();
	return 0;
}

void test(Stack<int> &pStack) {
	cout << "pushing 1 onto stack" << endl;
	pStack.push(1);
	cout << "pushing 2 onto stack" << endl;
	pStack.push(2);
	cout << "pushing 3 onto stack" << endl;
	pStack.push(3);

	cout << "popping first item: ";
	cout << pStack.pop() << endl;
	cout << "popping next item: ";
	cout << pStack.pop() << endl;
	cout << "popping next item: ";
	cout << pStack.pop() << endl;
	cout << "popping next item: ";
	cout << pStack.pop() << endl;
}

void testQ(Queue<int> &pQueue) {
	cout << "appending 1 onto queue" << endl;
	pQueue.append(1);
	cout << "appending 2 onto queue" << endl;
	pQueue.append(2);
	cout << "appending 3 onto queue" << endl;
	pQueue.append(3);

	cout << "Serving first item: ";
	cout << pQueue.serve() << endl;
	cout << "Serving next item: ";
	cout << pQueue.serve() << endl;
	cout << "Serving next item: ";
	cout << pQueue.serve() << endl;
	cout << "Serving next item: ";
	cout << pQueue.serve() << endl;
}
