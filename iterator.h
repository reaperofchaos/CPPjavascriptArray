#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

template <class T>
class iterator
{
	private:
		int size;
		T* array;
		int position;
	public:
		/*
			 _____                 _                   _
			/  __ \               | |                 | |
			| /  \/ ___  _ __  ___| |_ _ __ _   _  ___| |_ ___  _ __
			| |    / _ \| '_ \/ __| __| '__| | | |/ __| __/ _ \| '__|
			| \__/\ (_) | | | \__ \ |_| |  | |_| | (__| || (_) | |
			 \____/\___/|_| |_|___/\__|_|   \__,_|\___|\__\___/|_|


		*/
		iterator(string* arr, int s)
		{
			array = arr;
			size = s;
			position = 0;
		}

		void next(){
			position++;
			if(position >= size){
				position = 0;
			}
		}

		string value(){
			string value = "[" + to_string(position) + ", \"" + to_string(array[position]) + "\"]";
			return value;
		}
};


#endif // ITERATOR_H_INCLUDED
