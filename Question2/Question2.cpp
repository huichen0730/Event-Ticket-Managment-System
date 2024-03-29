#include "pch.h"
#include "Classes and functions.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int event_size = 10;		//the fixed size to limit that there are maximum ten waiting lists at the same time;

void first_menu(event events[], int event_size);
void show_second_menu();
void operations_for_event(event events[], int num_event);

int main()
{
	event events[event_size];          //create 10 event objects which have a event name and a waiting list;

	cout << "* -------------------------------------------- *" << endl;
	cout << "* " << setw(20) << "< Welcome to the Waiting List System > " << setw(7) << "    *" << endl;
	cout << "* -------------------------------------------- *" << endl;
	cout << endl << endl;
	for (int i = 0; i < event_size; i++)			//intialise names for each event for the purpose to demonstrate the event lists with empty waiting lists for the first time
	{
		cout << "Please initalise event names for ten events." << endl;
		cout << "Enter a name for event " << i + 1 << "." << endl;
		string event_name;
		cin >> event_name;
		events[i].setname(event_name);
		cout << endl;
	}

	first_menu(events, event_size);

	return 0;
}

void operations_for_event(event events[], int num_event)
{
	bool keep_looping;
	do
	{
		show_second_menu();
		keep_looping = 1;
		int choice;
		cout << endl << "Choose the operation you want to perform: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{   //add a new record
			add_new_record(events[num_event]);
			cout << endl;
			break;
		}
		case 2:
		{	//remove the first person from the waiting list
			customer temp;
			if (events[num_event].remove(temp))
			{
				cout << endl;
				cout << "A ticket now is available for " << temp.getname() << " whose phone number is: " << temp.get_phonenumber() << endl;
				cout << "So this person has been removed from the waiting list." << endl;
			}
			else
				cout << "Sorry, this is an empty waiting list." << endl;
			break;
		}
		case 3:
		{ //check position of one person
			string search_name;
			cout << "Enter the surname you want to search in the list." << endl;
			cin >> search_name;

			int position = events[num_event].search(search_name);

			if (position == -1)
				cout << "Sorry, no record is found. The person you want to search is not in the waiting list." << endl;
			else
				cout << search_name << " position " << position << " of the waiting list." << endl;
			break;
		}
		case 4:
		{ //reset the waiting list
			string new_name;
			cout << "The waiting list is about to reset, please enter a new name of the event to create a new waiting list for a new event." << endl;
			cin >> new_name;
			if (events[num_event].reset(new_name))
				cout << "The waiting list has been reset. " << endl;
			else
				cout << "Something went wrong and the operation failed." << endl;
			break;
		}
		case 5:
			//return the main menu
			first_menu(events, event_size);
			break;
		case 6:
		{ // quit the program
			keep_looping = 0;
			cout << "Thank you for using the program." << endl;
			break;
		}

		default:
		{ //handling any unexpected input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, the system cannot recognise your choice. Try again!" << endl;
			break;
		}

		}

	} while (keep_looping);
}

void first_menu(event events[], int event_size)
{
	cout << endl << endl;
	cout << "* -------------------------------------------- *" << endl;
	cout << "* " << setw(20) << "< Welcome to the Waiting List System > " << setw(7) << "    *" << endl;
	cout << "* " << setw(20) << "MENU" << setw(26) << "     *" << endl;
	cout << "* " << setw(20) << "Press 1 to show all the waiting lists" << setw(9) << " *" << endl;
	cout << "* " << setw(20) << "Press 2 to exit the system" << setw(20) << " *" << endl;
	cout << "* -------------------------------------------- *" << endl;

	int choice1;
	cin >> choice1;
	bool wrong_input;
	do
	{
		wrong_input = 0;
		switch (choice1)
		{
		case 1:
		{
			cout << "The following events have waiting lists: " << endl << endl;
			for (int i = 0; i < event_size; i++)
			{
				cout << i + 1 << ". " << events[i].getname() << "\t" << events[i].count_elements() << " people in the list." << endl;
			}
			cout << endl << endl << "Please enter the corresponding number to get access to the waiting list for the specific event. " << endl;
			int num_event;
			cin >> num_event;

			while (num_event < 0 || num_event > 10 || cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Sorry, the system cannot recognise your choice. Try again!" << endl;
				cin >> num_event;
			}
			//as the array index starts from 0, so the number for event the user has input needs to reduce 1 to get correct index position for each event.
			operations_for_event(events, num_event - 1);
			break;
		}
		case 2:
			cout << "Thank you for using the program." << endl;
			break;
		default:
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, the system cannot recognise your choice. Try again!" << endl;
			wrong_input = 1;
			cin >> choice1;
			break;
		}
		}

	} while (wrong_input);

}

void show_second_menu()
{
	cout << endl << endl;
	cout << "* -------------------------------------------- *" << endl;
	cout << "* " << setw(20) << "Menu" << setw(26) << "     *" << endl;
	cout << "* " << setw(5) << "Press 1 to add a new record" << setw(19) << " *" << endl;
	cout << "* " << setw(5) << "Press 2 to delete the first person" << setw(12) << " *" << endl;
	cout << "* " << setw(5) << "Press 3 to check a person's position" << setw(10) << " *" << endl;
	cout << "* " << setw(5) << "Press 4 to reset the list to empty" << setw(12) << " *" << endl;
	cout << "* " << setw(5) << "Press 5 to return to main menu" << setw(16) << " *" << endl;
	cout << "* " << setw(5) << "Press 6 to quit the program" << setw(19) << " *" << endl;
	cout << "* -------------------------------------------- *" << endl;
}