/*
CS240, Section ...
Program 3 "Stacks and Queues"
Author: Michael Rapp
Date: 0/1/2016
Description: This program reads data from a file which contains as part of the data commands for the corresponding information which it then
			 executes within the program.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Stack.h"
#include"Queue.h"

using namespace std;

void readFile(Stack<int>* pStack, Queue<int>* pQueue, ifstream &inFile);

int main() {
	
	Stack<int>* stack = new Stack<int>;
	Queue<int>* queue = new Queue<int>;
	ifstream inFile;
	int userSelection = 0;

	do {
		readFile(stack, queue, inFile);
		cout << "Would you like to: " << endl;
		cout << "1) Enter another file" << endl;
		cout << "2) Exit program" << endl;
		cin >> userSelection;	
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Please enter a number: ";
			cin >> userSelection;
		}
		while (userSelection != 1 && userSelection != 2) {
			cout << "Please enter either 1 or 2" << endl;
			cin >> userSelection;
		}
		if (userSelection == 1) {
			stack->deleteStack();
			queue->deleteQueue();
		}
	} while (userSelection != 2);

	cin.ignore();
	cout << "Program complete. Press enter to close.";
	cin.get();
	return 0;
}

void readFile(Stack<int>* pStack, Queue<int>* pQueue, ifstream &inFile) {
	//This function reads in the command and data from the file and loads the data into the stack or queue
	string filepath;
	string line;
	string data;
	int iData;
	const int OFFSET = 2; //used as the offset for parsing the string. Finds last character of command, then moves to first pos of data.

	cout << "Please enter the file path including the file extension: ";
	cin >> filepath;
	inFile.open(filepath);

	if (!inFile) {
		cout << "File not found.";
	}
	else {
		int width = 15;
		cout << setw(width) << "Operation" << setw(width) << " Stack" << setw(width) << " Value" << setw(width) << " Result" << endl;
		while (!inFile.eof()) {
			getline(inFile, line);
			if (line.find("push") != string::npos) {
				data = line.substr(line.find_first_of("h") + OFFSET, line.length() - 1);
				iData = stoi(data);
				cout << setw(width) << "Push" << setw(width) << " Stack " << setw(width) << data << setw(width) << " Success" << endl;
				pStack->push(iData);
			}//end if
			if (line.find("pop") != string::npos) {
				if (pStack->pop()) {
					cout << setw(width) << "Pop" << setw(width) << " Stack" << setw(width) << " --" << setw(width) << " Success" << endl;
				}
				else {
					cout << setw(width) << "Pop" << setw(width) << " Stack" << setw(width) << " --" << setw(width) << " Underflow" << endl;
				}
			}
			if (line.find("append") != string::npos) {
				data = line.substr(line.find_first_of("d") + OFFSET, line.length() - 1);
				iData = stoi(data);
				cout << setw(width) << "Appending" << setw(width) << " Queue " << setw(width) << data << setw(width) << " Success" << endl;
				pQueue->append(iData);
			}
			if (line.find("serve") != string::npos) {
				if (pQueue->serve()) {
					cout << setw(width) << "Serve" << setw(width) << " Queue" << setw(width) << " --" << setw(width) << " Success" << endl;
				}
				else {
					cout << setw(width) << "Serve" << setw(width) << " Queue" << setw(width) << " --" << setw(width) << " Underflow" << endl;
				}
			}
		}//end while
		cout << "Stack:" << endl;
		pStack->printStack();
		cout << "Queue:" << endl;
		pQueue->printQueue();
		inFile.close();
	}//end if !inFile
}