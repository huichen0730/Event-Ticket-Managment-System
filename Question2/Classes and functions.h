#pragma once
#include "pch.h"
#include "queuetemplate.h"
#include <iostream>
#include <string>
using namespace std;

class customer
{
private:
	string customer_name;
	string phone_number;
public:
	void setname(string name);
	string getname();
	void set_phonenumber(string phonenumber);
	string get_phonenumber();
};


class event
{
private:
	string event_name;
	Queue<customer> waiting_list;			// create a waiting list containing maximum 10 people as the default value initialised in the queue constructor

public:
	void setname(string name);
	string getname();
	bool add(customer& obj);
	bool remove(customer& front_obj);
	bool reset(string new_name);
	int search(string inputname);
	int count_elements();
};

void add_new_record(event& a_event);

void customer::setname(string name)
{
	customer_name = name;
}
string customer::getname()
{
	return customer_name;
}

void customer::set_phonenumber(string phonenumber)
{
	phone_number = phonenumber;
}
string customer::get_phonenumber()
{
	return phone_number;
}

void event::setname(string name)
{
	event_name = name;
}

string event::getname()
{
	return event_name;
}

bool event::add(customer& obj)
{
	return waiting_list.Add(obj);
}


bool event::remove(customer& front_obj)
{
	return waiting_list.Remove(front_obj);
}


bool event::reset(string new_name)
{
	customer junk;
	while (!waiting_list.Empty())
	{
		waiting_list.Remove(junk);
	}

	event_name = new_name;
	if (waiting_list.Empty())
		return true;
	else
		return false;
}

int event::search(string inputname)
{
	return waiting_list.traverse_element(inputname);
}

int event::count_elements()
{
	return waiting_list.count_element();
}

void add_new_record(event& a_event)
{
	customer new_obj;
	string name, phone_number;
	cout << "Enter a person's surname and his or her phone number to add to the waitling list." << endl;
	cin >> name >> phone_number;
	new_obj.setname(name);
	new_obj.set_phonenumber(phone_number);

	if (a_event.add(new_obj))
	{
		cout << "A new person has been added in successfully" << endl;
	}
	else
	{
		cout << "Sorry the waiting list for this event is already full. You cannot add any more to the list." << endl;
	}
}

