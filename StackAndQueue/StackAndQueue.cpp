#include<iostream>
#include<fstream>
#include<string>
#include"Stack.h"
#include"Queue.h"

using namespace std;

void test(Stack<int> &pStack);
void testQ(Queue<int> &pQueue);
void readFile(Stack<int> &pStack, Queue<int> &pQueue, ifstream &inFile);

int main() {
	
	Stack<int> stack;
	Queue<int> queue;
	ifstream inFile;

	/*test(stack);
	testQ(queue);*/
	readFile(stack, queue, inFile);

	cin.ignore();
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

void readFile(Stack<int> &pStack, Queue<int> &pQueue, ifstream &inFile) {
	string filepath;
	string line;
	string data;
	int iData;
	const int OFFSET = 2; //used as the offset for parsing the string. Finds last character of command, then moves to first pos of data.
	cout << "Please enter the file path including the file extension: ";
	cin >> filepath;
	inFile.open(filepath);


	if (!inFile) {
		cout << "File not found. Program terminates.";
	}
	else {
		while (!inFile.eof()) {
			getline(inFile, line);
			if (line.find("push") != string::npos) {
				data = line.substr(line.find_first_of("h") + OFFSET, line.length() - 1);
				iData = stoi(data);
				cout << "Pushing " << data << " onto stack." << endl;
				pStack.push(iData);
			}//end if
			if (line.find("pop") != string::npos) {
				cout << "Popping " << pStack.pop() << " off of stack" << endl;
			}
		}//end while
	}//end if !inFile
}