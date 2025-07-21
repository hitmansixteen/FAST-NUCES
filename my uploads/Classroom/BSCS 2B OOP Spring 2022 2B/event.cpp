#include "event.h"
#include <iostream>

using namespace std;

int main() {

	
	int choice;
	Event* eve = nullptr;
	Event eve1;

	do{
		
		cout << "Menu\n";
		cout << "0) Exit\n";
		cout << "1) Add New Event Using addEventOver\n";
		cout << "2) Add New Event Using addEventSet\n";
		cout << "3) Display Event addEventOver\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
			eve = addEventOver(eve);
		else if (choice == 2)
			addEventSet(eve1);
		else if (choice == 3)
			displayEvent(eve);
	} while (choice != 0);

	system("pause");

	return 0;
}