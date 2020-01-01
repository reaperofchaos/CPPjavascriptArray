// javascriptArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "JARRAY.h"
#include <iostream>
using namespace std;

int main()
{
	int myArr[5] = { 0, 1, 2, 3, 4 };
	Jarray<int> intJarray(myArr, 5);
	cout << "The javascript array length is " << intJarray.length() << endl;
	cout << "The last element is " << intJarray[4] << endl;
	//Test Push
	cout << "Pushing 3 to the end of the array" << endl;
	intJarray.display();
	intJarray.push(3);
	cout << "The last element is " << intJarray[5] << endl;
	//Test Pop
	cout << "Popping the last element of the array" << endl;
	intJarray.pop();
	int currentSize = intJarray.length();
	cout << "The current last element is " << intJarray[currentSize - 1] << endl;
	//Test Fill
	cout << "Filling the array with 1s" << endl;
	intJarray.fill(1, 0, currentSize);
	intJarray.display();
	//Test copyWithin
    intJarray.push(5);
    cout << "Adding 5 to the end of the list " << endl;
    intJarray.display();
    cout << "Copying array from positions 3 to " << currentSize << " to index 0" << endl;
    intJarray.copyWithin(0, 3, currentSize);
    intJarray.display();
	system("pause");
	return 0;
}
