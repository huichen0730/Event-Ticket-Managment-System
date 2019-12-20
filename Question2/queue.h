#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;

// Standard queue template

template <class Type>
class Queue
{
private:
	Type* Contents;
	int Queue_size;
	int Front, Back;
	int count;	//added to keep tracking on how many elements are in the queue
public:
	Queue(int queue_size = 10);
	~Queue();
	bool Empty() const;
	bool Full() const;
	bool Remove(Type& front_element);
	bool Add(const Type& new_element);
	int traverse_element(string input_name);  //added function 
	int count_element();		//added function 
};
#endif
