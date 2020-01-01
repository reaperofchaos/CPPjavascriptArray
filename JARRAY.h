#pragma once
#include <iostream>
#include <string>
#include<cstdlib>
#include "iterator.h"

using namespace std;

template <class T>
class Jarray
{
	private:
		T *ptr;
		int size;

	public:
		/*
			 _____                 _                   _
			/  __ \               | |                 | |
			| /  \/ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
			| |    / _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
			| \__/\ (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
			 \____/\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|


		*/
		Jarray(int size)
		{
			size = size;
			ptr = new T[size];
		}

		//take an array with a size parameter
		Jarray(T arr[], int s)
		{
			size = s;
			ptr = arr;
		}
		//destruct
		~Jarray()
		{
			//delete[] ptr;
		}
		/*

			 _____                      _
			|  _  |                    | |
			| | | |_ __   ___ _ __ __ _| |_ ___  _ __ ___
			| | | | '_ \ / _ \ '__/ _` | __/ _ \| '__/ __|
			\ \_/ / |_) |  __/ | | (_| | || (_) | |  \__ \
			 \___/| .__/ \___|_|  \__,_|\__\___/|_|  |___/
				  | |
				  |_|

		*/
		T &operator[] (int index) {
			if (index >= size)
			{
				cout << "Array index out of bounds, exiting" << endl;
				exit(0);
			}
			return ptr[index];
		}

		void display()
		{
			for (int i = 0; i < size; i++)
			{
				cout << "Element " << i << " is " << ptr[i] << endl;
			}
		}

		/*

			___  ___      _        _              ___  ___     _   _               _
			|  \/  |     | |      | |             |  \/  |    | | | |             | |
			| .  . |_   _| |_ __ _| |_ ___  _ __  | .  . | ___| |_| |__   ___   __| |___
			| |\/| | | | | __/ _` | __/ _ \| '__| | |\/| |/ _ \ __| '_ \ / _ \ / _` / __|
			| |  | | |_| | || (_| | || (_) | |    | |  | |  __/ |_| | | | (_) | (_| \__ \
			\_|  |_/\__,_|\__\__,_|\__\___/|_|    \_|  |_/\___|\__|_| |_|\___/ \__,_|___/



		*/

		//shallow copies part of any array to another location in the same array.
		void copyWithin(int target, int start, int end)
		{
			{
				int copyLength;

				//determine how many characters to copy from the array
				copyLength = end - start;
				cout << "The current copy length is " << copyLength << endl;
				//keep changing values until the length is reached
				for (int i = 0; i <= copyLength; i++)
				{
					//set the value of index equal to the startCopy index + i
					cout << "Target: " << target+ i << " now has " << ptr[start +i] << endl;
					ptr[target + i] = ptr[start + i];

				}
			}
		}

		//set elements of an array from a start index to an end index with a value;
		void fill(T value, int start, int end)
		{
			if (!end)
			{
				end = size;
			}
			if (!start)
			{
				start = 0;
			}
			for (int i = start; i < end; i++)
			{
				ptr[i] = value;
			}
		}

		int length() { return size; };

		//Removes the last element from an array and returns that element.


		void pop()
		{
			//create a new array
			int newSize = size - 1;
			T* newArray = new T[newSize];
			cout << "My new size is " << newSize << endl;
			//copy the ptr to the new Array
			//memcpy(newArray, ptr, newSize);

			for (int i = 0; (i < newSize); i++)
			{
				newArray[i] = ptr[i];
			}

			//add the value to the array
			delete[] ptr;
			//update array and size
			ptr = newArray;
			size = newSize;
		}
		//Adds one or more elements to the end of an array and returns the new length of the array.
		void push(T value)
		{
			//create a new array
			int newSize = size + 1;
			T* newArray = new T[newSize];
			cout << "My new size is " << newSize << endl;
			//copy the ptr to the new Array
			//memcpy(newArray, ptr, newSize);

			for (int i = 0; (i < size) && (i < newSize); i++)
			{
				newArray[i] = ptr[i];
			}

			//add the value to the array
			newArray[size] = value;
			delete[] ptr;
			//update array and size
			ptr = newArray;
			size = newSize;
		}
		//Reverses the order of the elements of an array in place — the first becomes the last, and the last becomes the first.
		void reverse()
		{
			T* newArray = new T[size];
			//store the values in reverse order in the new array
			for(int i = 0;  i < size;  i++)
			{
				ptr[i] = newArray[(size-1)-i];
			}
			//delete the old array
			delete[] ptr;
			//update array and size
			ptr = newArray;
		}
		//Removes the first element from an array and returns that element.
		 T shift()
		 {
				//get the first element of the array
				T first = ptr[0];
				//create a new arary;
				T* newArray = new T[size];
				int newSize = size - 1;
				//loop starting at 1 (skip 0) and copy to the new array;
				for(int i = 1; i < size; i++)
				{
					newArray[i - 1] = ptr[i];
				}
				delete[] ptr;
				ptr = newArray;
				size = newSize;
				return first;
		}
		//like copy within, but it will replace the element at target and remove elements after when count is >1
		void splice(int target, int count, T value)
			{
				int newSize = size - (count -1);
				T* newArray = new T[newSize];
				//Check if removing or adding
				if(count > 0)
				{
					//copy everything up to the target index
					for(int i = 0; i < newSize; i++)
					{
						//if at target index replace with value
						if(i == target)
						{
							newArray[i] = value;
							//increment i while less than count (remove entries)
							for(int b = 0; b < count; b++)
							{
								i++;
							}
						}else{
							newArray[i] = ptr[i];
						}

					}
				}

		}
		//Takes an array and adds all of the values to the front of the jarray
		//Due to C++, we can't have an indefinite list of parameters, so a list of parameters
		void unshift(T* arr[], int arrSize)
		{
			int newSize = size + arrSize;
			T* newArray = new T[newSize];
			int a = 0;
			for(int i = 0; i < newSize; i++)
			{
				if(i < arrSize)
				{
					newArray[i] = arr[i];
				}else{
					newArray[i] = ptr[a];
					a++;
				}
			}
			delete[] ptr;
			ptr = newArray;
			size = newSize;
		}
		/*

			  ___                                    ___  ___     _   _               _
			 / _ \                                   |  \/  |    | | | |             | |
			/ /_\ \ ___ ___ ___  ___ ___  ___  _ __  | .  . | ___| |_| |__   ___   __| |___
			|  _  |/ __/ __/ _ \/ __/ __|/ _ \| '__| | |\/| |/ _ \ __| '_ \ / _ \ / _` / __|
			| | | | (_| (_|  __/\__ \__ \ (_) | |    | |  | |  __/ |_| | | | (_) | (_| \__ \
			\_| |_/\___\___\___||___/___/\___/|_|    \_|  |_/\___|\__|_| |_|\___/ \__,_|___/



		*/
		// Creates a new array adding the values of the arr[] to the end of the jarray
		Jarray<T> concat(T* arr[], int arrSize)
		{
			int newSize = size + arrSize;
			T* newArray = new T[newSize];
			//loop through all the original array and store in newArray
			int i;
			for(i = 0; i < size; i++)
			{
				newArray[i] = ptr[i];
			}
			//add a to the value of i and store the value of second array to
			//the newArray
			for(int a = 0; a < newSize; a++)
			{
				newArray[i+a] = arr[a];
			}
			Jarray<T> newJarray(newArray, newSize);
			return newJarray;
		}

		//return a bool
		bool includes(T value)
		{
			bool isInArray = false;
			for(int i = 0; i < size; i++)
			{
				if(ptr[i] == value)
				{
					isInArray = true;
				}
			}
			return isInArray;
		}
		//return the first index with the array equal to the value or -1 if none is found
		int indexOf(T value)
		{
			int index = -1;
			this.sort();
			for(int i = 0; i < size; i++)
			{
				if(ptr[i] == value)
				{
					index = i;
					break;
				}
				return index;
			}
		}
		//Joins all elements of an array into a string, takes a separator as a string
		string join(string separator)
		{
			string newString;
			for(int i = 0; i < size; i++)
			{
				newString += to_string(ptr[i]) + separator;
			}
			return newString;
		}

		//Get the greatest index of an element within an array equal to a value or -1 if not in the array.
		int lastIndexOf(T value)
		{
			int index = -1;
			this.sort();
			for(int i = (size-1); i <= 0; i--)
			{
				if(ptr[i] == value)
				{
					index = i;
					break;
				}
				return index;
			}
		}
		//Extracts a portion of the array between beginning and end of array
		Jarray<T> slice(int begin){
			int end = size;
			int newSize = begin - end;
			T* newArray = new T[newSize];
			int i = 0;
			for(int a = begin; a < end; a++)
			{
				newArray[i] = ptr[a];
				i++;
			}
			Jarray<T> newJarray(newArray, newSize);
			return newJarray;
		}
		//Extracts a portion of the array between beginning index and ending index
		Jarray<T> slice(int begin, int end){
			int newSize = begin - end;
			T* newArray = new T[newSize];

			int i = 0;
			for(int a = begin; a < end; a++)
			{
				newArray[i] = ptr[a];
				i++;
			}
			Jarray<T> newJarray(newArray, newSize);
			return newJarray;
		}
		//Returns a string representing the array characterized by brackets, commas, etc. Similar to PHP's print_r(array[])
		string toSource()
		{
			string sourceString;
			sourceString = "[";
			//check if int
			if(is_same<T, int>::value)
            {
				for(int i = 0; i < size; i++)
				{
					if(i == (size -1))
					{
						sourceString += to_string(ptr[i]);
					}
					else
					{
						sourceString += to_string(ptr[i]) + ", ";
					}
				}
				sourceString += "]";
			}
			//check if float
			if(is_same<T, float>::value)
			{
				for(int i = 0; i < size; i++)
				{
					if(i == (size -1))
					{
						sourceString += to_string(ptr[i]);
					}
					else
					{
						sourceString += to_string(ptr[i]) + ", ";
					}
				}
				sourceString += "]";
			}
			//check if char
			if(is_same<T, char>::value)
			{
				for(int i = 0; i < size; i++)
				{
					if(i == (size -1))
					{
						sourceString += "'" + to_string(ptr[i]) + "'";
					}
					else
					{
						sourceString += "'" + to_string(ptr[i]) + "', ";
					}
				}
				sourceString += "]";
			}
			////check if string
			if(is_same<T, string>::value)
			{
				for(int i = 0; i < size; i++)
				{
					if(i == (size -1))
					{
						sourceString += "\"" + ptr[i] + "\"";
					}
					else
					{
						sourceString += "\"" + ptr[i] + "\",";
					}
				}
				sourceString += "]";
			}
			return sourceString;
		}
		//Joins all elements of an array into a string, takes a separator as a string
		string toString()
		{
			string newString;
			for(int i = 0; i < size; i++)
			{
				newString += to_string(ptr[i]) + ",";
			}
			return newString;
		}


		/*

			 _____ _                 _              ___  ___     _   _               _
			|_   _| |               | |             |  \/  |    | | | |             | |
			  | | | |_ ___ _ __ __ _| |_ ___  _ __  | .  . | ___| |_| |__   ___   __| |___
			  | | | __/ _ \ '__/ _` | __/ _ \| '__| | |\/| |/ _ \ __| '_ \ / _ \ / _` / __|
			 _| |_| ||  __/ | | (_| | || (_) | |    | |  | |  __/ |_| | | | (_) | (_| \__ \
			 \___/ \__\___|_|  \__,_|\__\___/|_|    \_|  |_/\___|\__|_| |_|\___/ \__,_|___/



		*/

		//Returns a new Iterator object that contains the key / value pairs for each index in the array.
		//Iterator is defined in iterator.h
		/*
		iterator entries(){
			iterator myIterator = new iterator(ptr, size);
			return myIterator;
		}
        */
		//returns true if every element in this array satisfies the provided testing function.
		bool every(bool (*f)(T)){
			bool isTrue = true;
			for(int i = 0; i < size; i++)
			{
				if(*f(ptr[i]) == false)
				{
					isTrue == false;
				}
			}
			return isTrue;
		}
		//Creates a new array with all of the elements of this array for
		//	which the provided filtering function returns true.
		Jarray<T> filter(bool (*f)(T)){
			T* tempArray = new T[size];
			int newSize = 0;
			for(int i = 0; i < size; i++)
			{
				if(*f(ptr[i]) == true)
				{
					tempArray[newSize] = ptr[i];
					newSize++;
				}
			}
			Jarray<T> newJarray(tempArray, newSize);
			return newJarray;
		}
		//returns the value of the first element that satisfies the testing function
		T find(bool (*f)(T)){
			T found = NULL;
			for(int i = 0; i < size; i++)
			{
				if(*f(ptr[i]) == true)
				{
					found = ptr[i];
					break;
				}
			}
			return found;
		}

		//returns the value of the first element that satisfies the testing function
		T findIndex(bool (*f)(T)){
			int foundIndex = -1;
			T found;
			for(int i = 0; i < size; i++)
			{
				if(*f(ptr[i]) == true)
				{
					foundIndex = i;
					found = ptr[i];
					break;
				}
			}
			return found;
		}


		//Returns a new array that contains the keys for each index in the array.
		Jarray<T> keys(){
			T* newArray = new T[size];
			for(int i = 0; i < size; i++)
			{
				newArray[i] = i;
			}
			Jarray<T> newJarray(newArray, size);
			return newJarray;
		}

		//Creates a new array with the results of calling a provided function
		//on every element in this array.
		Jarray<T> map(T(*f)(T)) {
			T* newArray = new T[size];
			for (int i = 0; i < size; i++)
			{
				newArray[i] = *f(ptr[i]);
			}
			Jarray<T> newJarray(newArray, size);
			return newJarray;
		}
		//returns true if any element in this array satisfies the provided testing function.
		bool some(bool (*f)(T)){
			bool isTrue = false;
			for(int i = 0; i < size; i++)
			{
				if(*f(ptr[i]) == true)
				{
					isTrue == true;
					break;
				}
			}
			return isTrue;
		}

		//creates a new iterator
		/*
		iterator values(){
			iterator myIterator = new iterator(ptr, size);
			return myIterator;
		}
		*/
};

		//toLocaleString() not really sure how to implement
		//Returns a localized string representing the array and its elements.
		//Overrides the Object.prototype.toLocaleString() method.

		//flat() - not sure how to implement since I am not necessary using an array of ptrs
		//The flat() method creates a new array with all sub - array elements concatenated
		//into it recursively up to the specified depth.
		//forEach()
		//Calls a function for each element in the array.
		//Array.flatMap()
		// flatMap() method first maps each element using a mapping function, then flattens the result into a new array.
		//It is identical to a map followed by a flat of depth 1
		//reduce()
		//Apply a function against an accumulator and each value of the array
		//(from left - to - right) as to reduce it to a single value.
		//reduceRight()
		//Apply a function against an accumulator and each value of the array
		//(from right - to - left) as to reduce it to a single value.
