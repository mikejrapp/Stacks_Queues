#include<iostream>
#include<fstream>
#include<string>
#include"Stack.h"

using namespace std;

void test(Stack<int> &pStack);

int main() {
	
	Stack<int> stack;

	test(stack);

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
