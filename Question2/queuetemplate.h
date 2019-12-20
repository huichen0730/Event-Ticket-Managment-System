#pragma once
#ifndef QUEUETEMPLATE_H
#define QUEUETEMPLATE_H
#include "queue.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor

template <class Type>
Queue<Type> ::Queue(int queue_size) :
	Queue_size(queue_size),
	Contents(new Type[queue_size + 1]),
	Front(0), Back(0), count(0)
{}

// Destructor

template <class Type>
Queue<Type> :: ~Queue()
{
	delete[] Contents;
}

// Tests

template <class Type>
bool Queue<Type> ::Empty() const
{
	return (Front == Back) ? true : false;
}

template <class Type>
bool Queue<Type> ::Full() const
{
	return ((1 + Back) % (Queue_size + 1) == Front) ? true : false;
}

// Remove and Add

template <class Type>
bool Queue<Type> ::Remove(Type& front_element)
{
	if (Empty())
		return false;
	else
	{
		front_element = Contents[Front];
		Front = (Front + 1) % (Queue_size + 1);
		count--;
		return true;
	}
}

template <class Type>
bool Queue<Type> ::Add(const Type& new_element)
{
	if (Full())
		return false;
	else
	{
		Contents[Back] = new_element;
		Back = (Back + 1) % (Queue_size + 1);
		count++;
		return true;
	}
}

//traverse through elements to see if there is any matched name. if so return the position of this matched name.
template <class Type>
int Queue<Type> ::traverse_element(string input_name)
{
	for (int i = Front; i < Queue_size; i++)
	{
		//index start from the first element of the queue and increment one by one to traverse through elements
		// e.g. first the index = front % (queue_size + 1) and then index move one to the left: index = (front + 1) % (queue_size +1) 
		// and keeping incrementing until reaching the queue size, in this case, default value: 10.
		int index = i % (Queue_size + 1);

		if (input_name == Contents[index].getname())   //input name compared with objects' names from customer class
			return index > Front ? index - Front + 1 : index + Queue_size - Front + 1;

		//the relationship between front and back could either be:
		// 1. front < back (new elements are added from right end so the back is visually at the right hand side of front) 
		// 2. front > back (new elements are 'wrapped around' from the end of the array back to the start so the back is visually at the left hand side of front).
		// so when the matched name is found, need to consider these two possiblities. 
		// return index - front (when front < back scenairo) to the right position but need to add 1 as the first element of array starts at index 0.
		// return index + queue size - front to the right position but also need to add 1 as the first element of array starts at index 0.
	}
	return -1;		//if there is no match in the waiting list, return -1 to mark it.
}

template <class Type>
int Queue<Type>::count_element()
{
	return count;
}

#endif
